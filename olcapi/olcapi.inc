<?php

function _olcapi_basepath () {
  
  $result = array();
  
  $result['methods'] = array(
    '<basepath>' => array(
      'output' => 'List of API methods',
    ),
    'chapter' => array(
      'output' => 'List of top-level chapters',
    ),
    'chapter/NID' => array(
      'output' => 'Chapter name, list of sections, and list of child chapters',
    ),
    'section' => array(
      'output' => 'List of sections that do not have any prerequisites',
    ),
    'section/NID' => array(
      'output' => 'Section data',
    ),
    'node/NID' => array(
      'output' => 'Node data',
    ),
    'file/FID' => array(
      'output' => 'File',
    )
  );
  
  $result ['status']['success'] [] = 'Finished';
  
  return $result;

}

function _olcapi_chapters () {
  
  $result = array();

  // Get the terms
  $chapter_vocab = taxonomy_vocabulary_machine_name_load(CHAPTER_TAXONOMY_NAME);
  $terms = taxonomy_get_tree($chapter_vocab->vid, 0, NULL, TRUE);
  
  // Collect the sections for each term
  foreach ($terms as &$term) {
    $term->sections = taxonomy_select_nodes($term->tid);
    usort($term->sections, '_olcapi_compare_nids_by_node_weight');
  }

  // Return the results
  $result ['data'] = $terms;
  $result ['status']['success'] [] = 'Finished';

  return $result; 
  
}

function _olcapi_chapter ($term) {
  
  $result = array();
  
  $term->sections = taxonomy_select_nodes($term->tid);
  usort($term->sections, '_olcapi_compare_nids_by_node_weight');
  
  $chapter_vocab = taxonomy_vocabulary_machine_name_load(CHAPTER_TAXONOMY_NAME);
  $term->children = taxonomy_get_tree($chapter_vocab->vid, $term->tid, 1, TRUE);
  
  $result ['data'] = $term;
  $result ['status']['success'] [] = 'Finished';
  
  return $result;
  
}

function _olcapi_sections () {

  $result = array();

  // Who references me?
  $query_result = db_query('
    select distinct
      n.nid,
      n.title
    from
    	{node} n
    where
      n.type = :type and
    	n.nid not in (
    	  select distinct
    	    node_has_prereq.entity_id
    	  from
    	    {field_data_field_prerequisites} node_has_prereq
    	)
  ', array(':type' => 'section'));

  foreach ($query_result as $row) {

    $result ['data'] []= $row;

  }

  $result ['status']['success'] [] = 'Finished';
  return $result;

}

function _olcapi_section ($node) {
  
  $result = array();

  //
  // Section's node
  //

  $result['data']['node'] = $node;
  
  //
  // Section's group
  //

  $group = og_get_group('node', $node->nid);
  $result['data']['group'] = $group; 

  //
  // Section's parts
  //
  
  $parts = new stdClass;
  $types = array(
    'lesson',
    'morpheme',
    'word',
    'person',
    'place',
    'conjugation',
    'phrase',
    'sentence',
    'conversation_turn',
    'narrative',
    'article'
  );

  $query_result = _olcapi_query_section_content_nodes($group->gid, $types);

  foreach ($query_result as $row) {

    $parts->{$row->type} []= array('node' => node_load($row->nid));

  }

  $result['data']['section_parts'] = $parts;
  
  //
  // Add instructions for each part
  //

  foreach ($result['data']['section_parts'] as $type => &$part_items) {
    foreach ($part_items as &$part_item) {

      $part_item['instructions'] = _olcapi_instruction_nodes($part_item['node']->nid);

    }
  }
  
  //
  // Sort parts by weights
  //

  foreach ($result['data']['section_parts'] as &$part) {

    usort($part, '_olcapi_compare_weights');

  }
  
  //
  // Sort morphemes by alphabet
  //

  if (isset($result['data']['section_parts']->morpheme)) {

    usort($result['data']['section_parts']->morpheme, '_olcapi_compare_morpheme');

  }
  else {
    // Morpeheme missing
  }
  
  if (isset($result['data']['section_parts']->conjugation)) {
    
    //
    // Re-arrange conjugations
    // 

    _olcapi_group_by_parent_node( $result['data']['section_parts']->conjugation, 'field_root_word');

    //
    // Sort conjugations
    //
    
    usort( $result['data']['section_parts']->conjugation, '_olcapi_compare_parent_weights');
    
  }
  else {
    // No conjugations to re-arrange
  }

  if (isset($result['data']['section_parts']->conversation_turn)) {
    
    //
    // Re-arrange conversations
    //

    _olcapi_group_by_parent_node($result['data']['section_parts']->conversation_turn, 'field_for_conversation');

    $conversations = &$result['data']['section_parts']->conversation_turn;

    //
    // Prune orphaned conversations
    //

    foreach ($conversations as $conversation_index => &$conversation) {

      if (!$conversation['parent']['node']) {

        unset($conversations[$conversation_index]);

      }
      else {
        // pass
      }

    }

    //
    // Add instructions to parent (conversation)
    //

    foreach ($conversations as &$conversation) {

      $conversation['parent']['instructions'] = _olcapi_instruction_nodes($conversation['parent']['node']->nid);

    }

    //
    // Sort the parent (conversation)
    //

    usort($conversations, '_olcapi_compare_conversation_parents');

    //
    // Sort the conversation turns
    //

    foreach ($conversations as &$conversation) {

      usort($conversation['children'], '_olcapi_compare_conversation_turns');

    }
    
  }
  else {
    // No conversations to re-arrange
  }
  
  $result['status']['success'] [] = 'Finished';
  
  return $result;
  
}

function _olcapi_booklet ($node) {
  
  $result = array(
    'data' => $node,
    'status' => array()
  );
  
  $valid_relationships = array(
    'conversation_turn' => array('field_for_conversation'),
    'instruction' => array('field_for_entity'),
    'alternative_spelling' => array('field_for_entity'),
  );
  
  foreach ($valid_relationships as $child_type => $child_relationship) {
    foreach ($child_relationship as $valid_relationship) {
      if (isset($result['data']->{'olc_children_'.$valid_relationship.'_by_type_'.$child_type})) {
        $sub_nodes = array();
        foreach ($result['data']->olc_children['relationship_'.$valid_relationship]['by_type'][$child_type] as $child_nid) {
          $sub_node = node_load($child_nid);
          $sub_result = _olcapi_booklet($sub_node);
          $sub_nodes []= $sub_result['data'];
          $result['status'] += $sub_result['status'];
        }
        $result['data']->olc_children['relationship_'.$valid_relationship]['by_type'][$child_type] = $sub_nodes;
      }
    }
  }
  
  $valid_group_content_types = array(
    'lesson',
    'morpheme',
    'word',
    'person',
    'place',
    'conjugation',
    'phrase',
    'sentence',
    'conversation',
    'conversation_turn',
    'narrative',
    'article',
  );
  
  foreach ($valid_group_content_types as $valid_type) {
    if (isset($result['data']->olc_group_content[$valid_type])) {
      $sub_nodes = array();
      foreach ($result['data']->olc_group_content[$valid_type] as $child_nid) {
        $sub_node = node_load($child_nid);
        $sub_result = _olcapi_booklet($sub_node);
        $sub_nodes []= $sub_result['data'];
        $result['status'] += $sub_result['status'];
      }
      $result['data']->olc_group_content[$valid_type] = $sub_nodes;
    }
  }
  
  return $result;

}

function _olcapi_node ($nid) {
  
  // Prepare URL
  unset($_GET['q']);

  $url = url(
    "node/$nid.json", 
    array(
      'absolute'=> TRUE, 
      'query' => $_GET
    )
  );

  // Set header  
  header("Location: $url");
  
  module_invoke_all('exit');
  exit;
  
}

function _olcapi_file ($file) {
  
  header ('Content-type:' . $file->filemime);
  
  echo file_get_contents($file->uri);
  
  module_invoke_all('exit');
  exit;
  
}


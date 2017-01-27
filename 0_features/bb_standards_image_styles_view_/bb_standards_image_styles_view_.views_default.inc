<?php
/**
 * @file
 * bb_standards_image_styles_view_.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bb_standards_image_styles_view__views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'image_styles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Image styles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Image styles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = 'scale_100x100';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture_1']['id'] = 'field_picture_1';
  $handler->display->display_options['fields']['field_picture_1']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture_1']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture_1']['label'] = 'scale_220x220';
  $handler->display->display_options['fields']['field_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_1']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture_2']['id'] = 'field_picture_2';
  $handler->display->display_options['fields']['field_picture_2']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture_2']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture_2']['label'] = 'scale_480x480';
  $handler->display->display_options['fields']['field_picture_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_2']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture_3']['id'] = 'field_picture_3';
  $handler->display->display_options['fields']['field_picture_3']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture_3']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture_3']['label'] = 'scale_700x700';
  $handler->display->display_options['fields']['field_picture_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_3']['settings'] = array(
    'image_style' => 'large_print',
    'image_link' => '',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture_4']['id'] = 'field_picture_4';
  $handler->display->display_options['fields']['field_picture_4']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture_4']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture_4']['label'] = 'scale_1024x1024';
  $handler->display->display_options['fields']['field_picture_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_4']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_4']['settings'] = array(
    'image_style' => 'scale_to_fit__1024x1024',
    'image_link' => '',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture_5']['id'] = 'field_picture_5';
  $handler->display->display_options['fields']['field_picture_5']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture_5']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture_5']['label'] = 'scale_1280x1280';
  $handler->display->display_options['fields']['field_picture_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_5']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_5']['settings'] = array(
    'image_style' => 'scale_to_fit__1280x1280',
    'image_link' => '',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_picture_6']['id'] = 'field_picture_6';
  $handler->display->display_options['fields']['field_picture_6']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture_6']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture_6']['label'] = 'scale_1600x1600';
  $handler->display->display_options['fields']['field_picture_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_6']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_6']['settings'] = array(
    'image_style' => 'scale_to_fit__1600x1600',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'api/image-styles';
  $export['image_styles'] = $view;

  return $export;
}

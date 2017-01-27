<?php
/**
 * @file
 * bb_standards_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function bb_standards_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: scale_to_fit__1024x1024.
  $styles['scale_to_fit__1024x1024'] = array(
    'label' => 'Scale to fit (1024 x 1024)',
    'effects' => array(
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1024,
          'height' => 1024,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: scale_to_fit__1280x1280.
  $styles['scale_to_fit__1280x1280'] = array(
    'label' => 'Scale to fit (1280 x 1280)',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1280,
          'height' => 1280,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: scale_to_fit__1600x1600.
  $styles['scale_to_fit__1600x1600'] = array(
    'label' => 'Scale to fit (1600 x 1600)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1600,
          'height' => 1600,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

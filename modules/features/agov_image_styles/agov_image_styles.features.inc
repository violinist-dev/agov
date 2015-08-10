<?php
/**
 * @file
 * agov_image_styles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agov_image_styles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function agov_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: full_page_wide.
  $styles['full_page_wide'] = array(
    'label' => 'Full page wide',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

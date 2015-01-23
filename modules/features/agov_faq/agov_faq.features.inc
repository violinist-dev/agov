<?php
/**
 * @file
 * agov_faq.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agov_faq_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function agov_faq_node_info() {
  $items = array(
    'faq_question' => array(
      'name' => t('FAQ Question'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

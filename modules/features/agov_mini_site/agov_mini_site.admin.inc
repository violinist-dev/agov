<?php

/**
 * @file
 * Contains admin paths for agov_mini_site.
 */

/**
 * Settings form for agov_mini_site.
 *
 * @return array
 *   Settings form for agov_mini_site.
 */
function minisite_admin_settings() {
  $form = array();

  $form['agov_mini_site_allowed_extensions'] = array(
    '#title' => 'Allowed extensions',
    '#description' => t('Allowed extensions for files inside mini-site archives. Separate extensions with a space or comma and do not include the leading dot.'),
    '#required' => TRUE,
    '#type' => 'textfield',
    '#element_validate' => array('_file_generic_settings_extensions'),
    '#default_value' => _agov_mini_site_allowed_extensions(),
  );

  $form['agov_mini_site_file_path'] = array(
    '#title' => 'File path',
    '#description' => 'File path for storage of mini-site files.',
    '#required' => TRUE,
    '#type' => 'textfield',
    '#element_validate' => array('_file_generic_settings_file_directory_validate'),
    '#default_value' => _agov_mini_site_get_path(),
  );

  return system_settings_form($form);
}

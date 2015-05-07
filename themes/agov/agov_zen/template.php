<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
function agov_zen_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  agov_zen_preprocess_html($variables, $hook);
  //agov_zen_preprocess_page($variables, $hook);

  $t_function = get_t();

  $variables['footer'] = '<div id="footer">' . t('!aGov is developed by !PreviousNext', array(
    '!aGov' => l(t('aGov'), 'http://agov.com.au'),
    '!PreviousNext' => l(t('PreviousNext'), 'http://previousnext.com.au'),
  )) . '</div>';

  if (drupal_installation_attempted()) {
    $variables['logo'] = base_path() . drupal_get_path('theme', 'agov_zen') . '/logo-alt.png';
    // Override the site name, which will be "Drupal".
    // @todo: Dynamically rename "aGov" using $conf.
    $variables['site_name'] = $t_function('Install aGov');
    // @todo: Use this to style the installer appropriately.
    $variables['classes_array'][] = 'installer';
  }
  else {
    if (empty($variables['content'])) {
      $variables['content'] = $t_function('This web site is currently undergoing some maintenance and is unavailable.');
    }
  }
}

/**
 * Override or insert variables into the html templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function agov_zen_preprocess_html(&$variables, $hook) {
  // Adds HTML5 placeholder shim.
  drupal_add_js(libraries_get_path('html5placeholder') . "/jquery.placeholder.js", 'file');
}

/**
 * Override or insert variables into the page templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_zen_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_zen_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  if (strpos($variables['region'], 'sidebar_') === 0) {
    $variables['theme_hook_suggestions'] = array_diff(
      $variables['theme_hook_suggestions'], array('region__sidebar')
    );
  }
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_zen_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'] = array_diff(
      $variables['theme_hook_suggestions'], array('block__no_wrapper')
    );
  }
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function agov_zen_preprocess_node(&$variables, $hook) {
  // Slides get a special read more link.
  if ($variables['type'] == 'slide') {
    if (!empty($variables['field_read_more'][0]['url'])) {
      $variables['title_link'] = l($variables['title'], $variables['field_read_more'][0]['url']);
    }
    else {
      $variables['title_link'] = check_plain($variables['title']);
    }
  }
}

/**
 * Implements hook_process_node().
 */
function agov_zen_process_node(&$variables) {
  // The aGov node template includes a dynamic title tag. This defaults to
  // h2, if not set elsewhere.
  if (!isset($variables['title_tag']) || empty($variables['title_tag'])) {
    $variables['title_tag'] = 'h2';
  }

  // We only want to set these if Display Suite HASN'T already been used.
  // This allows us to control the defaults but let end-users override with
  // DS wherever necessary.
  // This happens in _process_node(), as DS doesn't do its thing till AFTER
  // _preprocess_node() has run.
  if (!isset($variables['rendered_by_ds']) || $variables['rendered_by_ds'] != TRUE) {
    if (isset($variables['view_mode'])) {
      // Compact view modes are intended to be embedded in views.
      if ($variables['view_mode'] == 'compact') {
        _agov_zen_process_node_compact($variables);
      }

      // Limit image fields to 1 item only in teaser and compact modes.
      if ($variables['view_mode'] == 'compact' || $variables['view_mode'] == 'teaser') {
        _agov_zen_process_node_compact_teaser($variables);
      }
    }
  }
}

/**
 * Private callback to process compact node view modes.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 */
function _agov_zen_process_node_compact(&$variables) {
  // Compact items are wrapped in an h3, as there is usually an h2
  // preceding them (the view or pane title).
  $variables['title_tag'] = 'h3';
}

/**
 * Private callback to process compact and teaser node view modes.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 */
function _agov_zen_process_node_compact_teaser(&$variables) {
  $fields = field_read_fields(array('entity_type' => 'node', 'bundle' => $variables['type']));
  foreach ($fields as $field_name => $field_settings) {
    if ($field_settings['type'] == 'image') {
      if (isset($variables['content'][$field_name])) {
        $children = element_children($variables['content'][$field_name]);
        if (!empty($children)) {
          $limited = $variables['content'][$field_name][0];
          foreach ($children as $child_index) {
            unset ($variables['content'][$field_name][$child_index]);
          }
          $variables['content'][$field_name][0] = $limited;
        }
      }
    }
  }
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_zen_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Implements hook_form_alter().
 */
function agov_zen_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'funnelback_search_block_form') {
    $form['funnelback_search_field']['#attributes']['placeholder'] = 'Enter keywords…';
  }
}

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
/* -- Delete this line if you want to use this function
function agov_whitlam_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  agov_whitlam_preprocess_html($variables, $hook);
  agov_whitlam_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_whitlam_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  $variables['classes_array'] = array_diff($variables['classes_array'],
    array('class-to-remove')
  );
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_whitlam_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
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
/* -- Delete this line if you want to use this function
function agov_whitlam_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // agov_whitlam_preprocess_node_page() or
  // agov_whitlam_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_whitlam_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Implements hook_preprocess_comment().
 */
function agov_whitlam_preprocess_comment(&$variables, $hook) {
  $comment = $variables['comment'];
  $variables['submitted'] = t('<span class="field author">!username</span> - <span class="field date-month">!date</span>',
    array(
      '!username' => $variables['author'],
      '!date' => format_date($comment->created, 'custom', 'l d M, Y'),
    ));
  if (variable_get('comment_subject_field_' . $variables['node']->type, 1) == 0) {
    $variables['title'] = '';
  }
}

/**
 * Implements hook_preprocess_comment_wrapper().
 */
function agov_whitlam_preprocess_comment_wrapper(&$variables, $hook) {
  if ($variables['node']->comment_count) {
    $variables['total_comments_in_node'] = $variables['node']->comment_count;
  }
  else {
    $variables['total_comments_in_node'] = 0;
  }
}


/**
 * Override or insert variables into the region templates.
 *
 * @param array $variables
 *   Variables to pass to the theme template.
 * @param string $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function agov_whitlam_preprocess_region(&$variables, $hook) {
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
function agov_whitlam_preprocess_block(&$variables, $hook) {
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

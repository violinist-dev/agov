<?php
/**
 * @file
 * Defines the home panel layout
 * @copyright Copyright(c) 2012 Previous Next Pty Ltd
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 */

/**
 * Implementation of hook_panels_layouts().
 */
$plugin = array(
  'title' => t('Home Layout'),
  'category' => t('aGov Whitlam'),
  'icon' => 'home.png',
  'theme' => 'agov_layouts_home',
  'regions' => array(
    'header' => t('Header region'),
    'main' => t('Main region'),
    'right-sidebar' => t('Right sidebar region'),
    'footer' => t('Footer region'),
  ),
);

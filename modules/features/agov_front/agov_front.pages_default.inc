<?php
/**
 * @file
 * agov_front.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function agov_front_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Front Page';
  $page->admin_description = 'Provides a front page for aGov.';
  $page->path = 'front';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'home';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'left' => NULL,
      'right' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
      'right-sidebar' => NULL,
      'footer-1' => NULL,
      'footer-2' => NULL,
      'footer-3' => NULL,
      'promo-1' => NULL,
      'promo-2' => NULL,
      'promo-3' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Welcome to aGov';
  $display->uuid = '018af563-e806-4469-95a0-52e841018e36';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-72c6dc3f-c978-4dee-bf4f-b32a7bbaafe9';
    $pane->panel = 'footer-1';
    $pane->type = 'block';
    $pane->subtype = 'bean-book-icon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '72c6dc3f-c978-4dee-bf4f-b32a7bbaafe9';
    $display->content['new-72c6dc3f-c978-4dee-bf4f-b32a7bbaafe9'] = $pane;
    $display->panels['footer-1'][0] = 'new-72c6dc3f-c978-4dee-bf4f-b32a7bbaafe9';
    $pane = new stdClass();
    $pane->pid = 'new-eafb23cd-a2d5-45e7-90b6-744142659176';
    $pane->panel = 'footer-2';
    $pane->type = 'block';
    $pane->subtype = 'bean-bus-icon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eafb23cd-a2d5-45e7-90b6-744142659176';
    $display->content['new-eafb23cd-a2d5-45e7-90b6-744142659176'] = $pane;
    $display->panels['footer-2'][0] = 'new-eafb23cd-a2d5-45e7-90b6-744142659176';
    $pane = new stdClass();
    $pane->pid = 'new-d8257788-0d30-40b8-bb11-99a1ffdf6006';
    $pane->panel = 'footer-3';
    $pane->type = 'block';
    $pane->subtype = 'bean-calendar-icon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd8257788-0d30-40b8-bb11-99a1ffdf6006';
    $display->content['new-d8257788-0d30-40b8-bb11-99a1ffdf6006'] = $pane;
    $display->panels['footer-3'][0] = 'new-d8257788-0d30-40b8-bb11-99a1ffdf6006';
    $pane = new stdClass();
    $pane->pid = 'new-8785a12b-42ae-4e3b-ac04-ac8cede1905c';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Call to action',
      'title' => '',
      'body' => '<div class="layout-3col"><div class="layout-3col__left-content"><h2>aGov is a free open source Drupal 7 distribution developed specifically for Australian government organisations.</h2></div><div class="layout-3col__right-sidebar"><p><a class="button button--large button--wide" href="https://agov.com.au/">Discover aGov 3</a></p></div></div>',
      'format' => 'rich_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8785a12b-42ae-4e3b-ac04-ac8cede1905c';
    $display->content['new-8785a12b-42ae-4e3b-ac04-ac8cede1905c'] = $pane;
    $display->panels['header'][0] = 'new-8785a12b-42ae-4e3b-ac04-ac8cede1905c';
    $pane = new stdClass();
    $pane->pid = 'new-6502df14-5504-4047-bb0a-23f054ef1bf5';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'latest_updates';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '6',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => 'Latest Updates',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6502df14-5504-4047-bb0a-23f054ef1bf5';
    $display->content['new-6502df14-5504-4047-bb0a-23f054ef1bf5'] = $pane;
    $display->panels['main'][0] = 'new-6502df14-5504-4047-bb0a-23f054ef1bf5';
    $pane = new stdClass();
    $pane->pid = 'new-c88ee9c7-05b6-4fea-ae5f-81cf7a1e0fb7';
    $pane->panel = 'promo-1';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '4',
      'links' => 0,
      'leave_node_title' => 1,
      'identifier' => '',
      'build_mode' => 'teaser',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c88ee9c7-05b6-4fea-ae5f-81cf7a1e0fb7';
    $display->content['new-c88ee9c7-05b6-4fea-ae5f-81cf7a1e0fb7'] = $pane;
    $display->panels['promo-1'][0] = 'new-c88ee9c7-05b6-4fea-ae5f-81cf7a1e0fb7';
    $pane = new stdClass();
    $pane->pid = 'new-65ccb7cf-b616-4bcb-a878-37aa5d63ad36';
    $pane->panel = 'promo-2';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '5',
      'links' => 0,
      'leave_node_title' => 1,
      'identifier' => '',
      'build_mode' => 'teaser',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '65ccb7cf-b616-4bcb-a878-37aa5d63ad36';
    $display->content['new-65ccb7cf-b616-4bcb-a878-37aa5d63ad36'] = $pane;
    $display->panels['promo-2'][0] = 'new-65ccb7cf-b616-4bcb-a878-37aa5d63ad36';
    $pane = new stdClass();
    $pane->pid = 'new-093a7ab6-7f30-48e4-b65f-2f8e5e852c98';
    $pane->panel = 'promo-3';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '8',
      'links' => 0,
      'leave_node_title' => 1,
      'identifier' => '',
      'build_mode' => 'teaser',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '093a7ab6-7f30-48e4-b65f-2f8e5e852c98';
    $display->content['new-093a7ab6-7f30-48e4-b65f-2f8e5e852c98'] = $pane;
    $display->panels['promo-3'][0] = 'new-093a7ab6-7f30-48e4-b65f-2f8e5e852c98';
    $pane = new stdClass();
    $pane->pid = 'new-aaf8dc56-6a54-45ce-85ba-c50091a540b8';
    $pane->panel = 'right-sidebar';
    $pane->type = 'block';
    $pane->subtype = 'twitter_block-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Twitter feed',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aaf8dc56-6a54-45ce-85ba-c50091a540b8';
    $display->content['new-aaf8dc56-6a54-45ce-85ba-c50091a540b8'] = $pane;
    $display->panels['right-sidebar'][0] = 'new-aaf8dc56-6a54-45ce-85ba-c50091a540b8';
    $pane = new stdClass();
    $pane->pid = 'new-b4fc4d0c-e043-4153-8196-83f6353044d7';
    $pane->panel = 'right-sidebar';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-quick-links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'nav-menu__wrapper divider',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b4fc4d0c-e043-4153-8196-83f6353044d7';
    $display->content['new-b4fc4d0c-e043-4153-8196-83f6353044d7'] = $pane;
    $display->panels['right-sidebar'][1] = 'new-b4fc4d0c-e043-4153-8196-83f6353044d7';
    $pane = new stdClass();
    $pane->pid = 'new-3c15c097-2765-4fb9-9f38-daf703d4b902';
    $pane->panel = 'right-sidebar';
    $pane->type = 'block';
    $pane->subtype = 'agov_social_links-services';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'divider',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3c15c097-2765-4fb9-9f38-daf703d4b902';
    $display->content['new-3c15c097-2765-4fb9-9f38-daf703d4b902'] = $pane;
    $display->panels['right-sidebar'][2] = 'new-3c15c097-2765-4fb9-9f38-daf703d4b902';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}

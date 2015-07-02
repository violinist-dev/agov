<?php
/**
 * @file
 * agov_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function agov_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_media';
  $page->task = 'page';
  $page->admin_title = 'News & Media';
  $page->admin_description = 'Provides News & Media page.';
  $page->path = 'news-media';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'News & Media',
    'name' => 'main-menu',
    'weight' => '-46',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_media_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news_media';
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
      'middle' => NULL,
      'header' => NULL,
      'main' => NULL,
      'right-sidebar' => NULL,
      'footer-1' => NULL,
      'footer-2' => NULL,
      'footer-3' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'News & Media';
  $display->uuid = '4baeaa24-4eeb-4753-a9ac-786200ce92b9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5f250f51-e174-4b72-846b-8628dd3fa5bb';
    $pane->panel = 'header';
    $pane->type = 'views';
    $pane->subtype = 'footer_teaser';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
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
    $pane->uuid = '5f250f51-e174-4b72-846b-8628dd3fa5bb';
    $display->content['new-5f250f51-e174-4b72-846b-8628dd3fa5bb'] = $pane;
    $display->panels['header'][0] = 'new-5f250f51-e174-4b72-846b-8628dd3fa5bb';
    $pane = new stdClass();
    $pane->pid = 'new-99a19956-e825-438a-afca-885c9bd6205c';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'bean-current-news';
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
    $pane->uuid = '99a19956-e825-438a-afca-885c9bd6205c';
    $display->content['new-99a19956-e825-438a-afca-885c9bd6205c'] = $pane;
    $display->panels['main'][0] = 'new-99a19956-e825-438a-afca-885c9bd6205c';
    $pane = new stdClass();
    $pane->pid = 'new-8dc2e141-ffe4-407b-986c-5d2f4699665c';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'bean-events';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8dc2e141-ffe4-407b-986c-5d2f4699665c';
    $display->content['new-8dc2e141-ffe4-407b-986c-5d2f4699665c'] = $pane;
    $display->panels['main'][1] = 'new-8dc2e141-ffe4-407b-986c-5d2f4699665c';
    $pane = new stdClass();
    $pane->pid = 'new-0530795a-c287-49e8-8c67-6bb6aea1aaa8';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'bean-media-releases';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0530795a-c287-49e8-8c67-6bb6aea1aaa8';
    $display->content['new-0530795a-c287-49e8-8c67-6bb6aea1aaa8'] = $pane;
    $display->panels['main'][2] = 'new-0530795a-c287-49e8-8c67-6bb6aea1aaa8';
    $pane = new stdClass();
    $pane->pid = 'new-19cb3817-4d87-4318-8ed6-bc351f46bb89';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'bean-blog';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '19cb3817-4d87-4318-8ed6-bc351f46bb89';
    $display->content['new-19cb3817-4d87-4318-8ed6-bc351f46bb89'] = $pane;
    $display->panels['main'][3] = 'new-19cb3817-4d87-4318-8ed6-bc351f46bb89';
    $pane = new stdClass();
    $pane->pid = 'new-c7008297-f3d3-43a7-a7e7-b004201121ce';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c7008297-f3d3-43a7-a7e7-b004201121ce';
    $display->content['new-c7008297-f3d3-43a7-a7e7-b004201121ce'] = $pane;
    $display->panels['right-sidebar'][0] = 'new-c7008297-f3d3-43a7-a7e7-b004201121ce';
    $pane = new stdClass();
    $pane->pid = 'new-23c5291b-8a89-4c42-ace2-4c632d6d5d3d';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '23c5291b-8a89-4c42-ace2-4c632d6d5d3d';
    $display->content['new-23c5291b-8a89-4c42-ace2-4c632d6d5d3d'] = $pane;
    $display->panels['right-sidebar'][1] = 'new-23c5291b-8a89-4c42-ace2-4c632d6d5d3d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_media'] = $page;

  return $pages;

}

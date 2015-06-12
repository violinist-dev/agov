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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'News & Media';
  $display->uuid = '4baeaa24-4eeb-4753-a9ac-786200ce92b9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-42b225e5-0d7e-4006-8fd5-3d41de8ecf26';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'bean-news-and-media-intro';
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
    $pane->uuid = '42b225e5-0d7e-4006-8fd5-3d41de8ecf26';
    $display->content['new-42b225e5-0d7e-4006-8fd5-3d41de8ecf26'] = $pane;
    $display->panels['middle'][0] = 'new-42b225e5-0d7e-4006-8fd5-3d41de8ecf26';
    $pane = new stdClass();
    $pane->pid = 'new-99a19956-e825-438a-afca-885c9bd6205c';
    $pane->panel = 'middle';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '99a19956-e825-438a-afca-885c9bd6205c';
    $display->content['new-99a19956-e825-438a-afca-885c9bd6205c'] = $pane;
    $display->panels['middle'][1] = 'new-99a19956-e825-438a-afca-885c9bd6205c';
    $pane = new stdClass();
    $pane->pid = 'new-8dc2e141-ffe4-407b-986c-5d2f4699665c';
    $pane->panel = 'middle';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8dc2e141-ffe4-407b-986c-5d2f4699665c';
    $display->content['new-8dc2e141-ffe4-407b-986c-5d2f4699665c'] = $pane;
    $display->panels['middle'][2] = 'new-8dc2e141-ffe4-407b-986c-5d2f4699665c';
    $pane = new stdClass();
    $pane->pid = 'new-0530795a-c287-49e8-8c67-6bb6aea1aaa8';
    $pane->panel = 'middle';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0530795a-c287-49e8-8c67-6bb6aea1aaa8';
    $display->content['new-0530795a-c287-49e8-8c67-6bb6aea1aaa8'] = $pane;
    $display->panels['middle'][3] = 'new-0530795a-c287-49e8-8c67-6bb6aea1aaa8';
    $pane = new stdClass();
    $pane->pid = 'new-19cb3817-4d87-4318-8ed6-bc351f46bb89';
    $pane->panel = 'middle';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '19cb3817-4d87-4318-8ed6-bc351f46bb89';
    $display->content['new-19cb3817-4d87-4318-8ed6-bc351f46bb89'] = $pane;
    $display->panels['middle'][4] = 'new-19cb3817-4d87-4318-8ed6-bc351f46bb89';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_media'] = $page;

  return $pages;

}

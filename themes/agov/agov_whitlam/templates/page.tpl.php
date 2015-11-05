<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<header class="header" role="banner">
  <div class="layout-center header__inner clearfix">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
    <?php endif; ?>

    <?php if ($site_name || $site_slogan): ?>
      <div class="header__name-and-slogan">
        <?php if ($site_name): ?>
          <div class="header__site-name visually-hidden">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
          </div>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <div class="header__site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if ($secondary_menu): ?>
      <nav class="header__secondary-menu" role="navigation">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array('links', 'inline', 'clearfix'),
          ),
          'heading' => array(
            'text' => $secondary_menu_heading,
            'level' => 'h2',
            'class' => array('visually-hidden'),
          ),
        )); ?>
      </nav>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </div>
</header>

<div class="navbar__wrapper">
  <div class="layout-center clearfix">
    <?php print render($page['navigation']); ?>
  </div>
</div>

<div class="layout-center layout-3col" role="main">

  <?php
    // Render the sidebars to see if there's anything in them.
    $sidebar_first  = render($page['sidebar_first']);
    $sidebar_second = render($page['sidebar_second']);
    // Decide on layout classes by checking if sidebars have content.
    $content_class = 'layout-3col__full';
    $sidebar_first_class = $sidebar_second_class = '';
    if ($sidebar_first && $sidebar_second):
      $content_class = 'layout-3col__right-content';
      $sidebar_first_class = 'layout-3col__left-sidebar';
      $sidebar_second_class = 'layout-3col__left-sidebar';
    elseif ($sidebar_second):
      $content_class = 'layout-3col__left-content';
      $sidebar_second_class = 'layout-3col__right-sidebar';
    elseif ($sidebar_first):
      $content_class = 'layout-3col__right-content';
      $sidebar_first_class = 'layout-3col__left-sidebar';
    endif;
  ?>

  <div class="<?php print $content_class; ?>">
    <?php print render($page['highlighted']); ?>
    <?php print $breadcrumb; ?>
    <a href="#skip-link" class="visually-hidden--focusable" id="main-content">Back to top</a>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <h1><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print $messages; ?>
    <?php print render($tabs); ?>
    <?php print render($page['help']); ?>
    <?php if ($action_links): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>
    <?php print render($page['content']); ?>
    <?php print $feed_icons; ?>
  </div>

  <?php if ($sidebar_first): ?>
    <aside class="<?php print $sidebar_first_class; ?>" role="complementary">
      <?php print $sidebar_first; ?>
    </aside>
  <?php endif; ?>

  <?php if ($sidebar_second): ?>
    <aside class="<?php print $sidebar_second_class; ?>" role="complementary">
      <?php print $sidebar_second; ?>
    </aside>
  <?php endif; ?>

</div>

<?php print render($page['footer']); ?>

<?php print render($page['footer_bottom']); ?>

<?php print render($page['bottom']); ?>

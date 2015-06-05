<?php
/**
 * @file
 * Provides themed representation of the home layout.
 * @copyright Copyright(c) 2012 Previous Next Pty Ltd
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 *
 * Available variables
 * -------------------
 * $content array of panels.
 */

?>

<div class="layout-3col clearfix" <?php if (!empty($css_id)) : print "id=\"$css_id\""; endif; ?>>

  <?php if (!empty($content['header'])) : ?>
    <div class="layout-3col__full region-featured-top">
      <?php print $content['header'];?>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['main'])) : ?>
    <div class="layout-3col__left-content">
      <?php print $content['main'];?>
    </div>
  <?php endif; ?>

  <?php if(!empty($content['right-sidebar'])) : ?>
    <div class="layout-3col__right-sidebar">
      <?php print $content['right-sidebar'];?>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['footer-1'])) : ?>
    <div class="layout-3col__col-1 divider">
      <?php print $content['footer-1'];?>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['footer-2'])) : ?>
    <div class="layout-3col__col-2 divider">
      <?php print $content['footer-2'];?>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['footer-3'])) : ?>
    <div class="layout-3col__col-3 divider">
      <?php print $content['footer-3'];?>
    </div>
  <?php endif; ?>

</div>

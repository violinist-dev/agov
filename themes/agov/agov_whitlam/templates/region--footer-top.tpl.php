<?php
/**
 * @file
 * Returns the HTML for the footer top region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($content): ?>
  <div class="<?php print $classes; ?>">
    <div class="footer-top layout-center clearfix">
      <?php print $content; ?>
    </div>
  </div>
<?php endif; ?>

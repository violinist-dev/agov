<?php
/**
 * @file
 * Returns the HTML for the bottom region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($content): ?>
  <div class="<?php print $classes; ?>">
    <div class="footer-bottom layout-center clearfix">
      <?php print $content; ?>
      <div class="footer-bottom__to-top"><i class="fa fa-chevron-circle-up fa-lg"></i> <a class="footer-bottom__link" href="#top">Back to top </a></div>
    </div>
  </div>
<?php endif; ?>

<?php
/**
 * @file
 * Returns the HTML for the footer bottom region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($content): ?>
  <footer class="footer-bottom">
    <div class="layout-center clearfix">
      <div class="footer-bottom__left <?php print $classes; ?>">
        <?php print $content; ?>
      </div>
      <div class="footer-bottom__right">
        <p>
          <span class="fa fa-chevron-circle-up fa-lg" aria-hidden="true"></span>
          <a class="footer-bottom__link" href="#skip-link">Back to top</a>
        </p>
      </div>
    </div>
  </footer>
<?php endif; ?>

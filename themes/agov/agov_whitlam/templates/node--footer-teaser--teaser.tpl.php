<?php
/**
 * @file
 * Template for article teasers.
 *
 * $title_tag defaults to h2.
 * @see agov_whitlam_process_node();
 */
?>


  <div class="teaser">
  <?php if (!empty($content['field_image'])): ?>
  <div class="teaser--image">
    <a href="<?php print $node_url; ?>"><?php print drupal_render($content['field_image']) ?></a>
  </div>
  <?php endif; ?>
  <<?php print $title_tag; ?> class="teaser__title">
    <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
  </<?php print $title_tag; ?>>
  <div class="teaser__content">
    <?php print drupal_render($content['field_description']) ?>
  </div>
 </div>

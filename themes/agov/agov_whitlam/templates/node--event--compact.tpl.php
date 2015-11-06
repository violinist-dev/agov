<?php
/**
 * @file
 * Template for article compact teasers.
 *
 * $title_tag defaults to h2.
 * @see agov_whitlam_process_node();
 */
?>

<div class="teaser clearfix">
  <?php if (!empty($content['field_feature_image'][0])): ?>
    <div class="teaser__image teaser__image-wide">
      <?php print drupal_render($content['field_feature_image'][0]) ?>
    </div>
  <?php endif; ?>
  <<?php print $title_tag; ?> class="teaser__title">
    <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
  </<?php print $title_tag; ?>>
  <div class="teaser__content">
    <?php hide($content['field_feature_image']); ?>
    <?php hide($content['links']); ?>
    <span class="teaser__date"><?php print drupal_render($content['field_event_date']) ?></span>
    <?php print drupal_render($content) ?>
    <?php print drupal_render($content['links']) ?>
  </div>
</div>

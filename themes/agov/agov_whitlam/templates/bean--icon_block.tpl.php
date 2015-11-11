<?php
/**
 * @file
 * Implementation for beans.
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="box--icon">
    <?php if ($box_icon) : ?>
      <div class="box--icon__left">
        <span class="fa <?php print $box_icon; ?>" aria-hidden="true"></span>
      </div>
    <?php endif; ?>

    <?php if (!empty($box_link_to) || $box_text) : ?>
      <div class="box--icon__right">
        <?php if (!empty($box_link_to)) : ?>
          <h2 class="box__title"><?php print render($box_link_to); ?></h2>
        <?php endif; ?>

        <?php if ($box_text) : ?>
          <div class="box__content"><?php print render($box_text); ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>
</div>

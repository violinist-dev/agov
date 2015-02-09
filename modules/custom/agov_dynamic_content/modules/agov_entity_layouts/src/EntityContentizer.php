<?php

/**
 * @file
 * Contains a EntityContentizer
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at previousnext dot com dot au
 * @copyright Copyright(c) 2015 Previous Next Pty Ltd
 */

namespace Drupal\agov_entity_layouts;


/**
 * Class EntityContentizer
 * @package Drupal\agov_entity_layouts
 */
class EntityContentizer {

  /**
   * Defines the layout field name.
   */
  const FIELD_LAYOUT = 'field_layout_mode';

  /**
   * Defines the paragraphs field name.
   */
  const FIELD_PARAGRAPHS = 'field_entity_content';

  /**
   * The content buffer.
   *
   * @var array
   */
  protected $contentBuffer = array();

  /**
   * Lazy constructor.
   *
   * @static
   * @return static
   *   Returns an instance of EntityContentizer
   */
  static public function init() {

    return new static();
  }

  /**
   * Callback for hook_entity_view().
   *
   * @param object $entity
   *   The entity.
   * @param string $entity_type
   *   The entity type.
   * @param string $view_mode
   *   The view mode.
   * @param string $langcode
   *   The langcode
   */
  public function entityView($entity, $entity_type, $view_mode, $langcode) {
    $this->contentBuffer = $entity->content;

    if ($view_mode == 'full') {
      $layout_lang = $this->fieldLanguage($entity_type, $entity, $this::FIELD_LAYOUT, $langcode);
      if (isset($entity->{$this::FIELD_LAYOUT}[$layout_lang][0]['value']) && !empty($entity->{$this::FIELD_LAYOUT}[$layout_lang][0]['value'])) {

        // The layout field switches content between normal and paragraphs
        // (dynamic) mode.
        if ($entity->{$this::FIELD_LAYOUT}[$layout_lang][0]['value'] == AGOV_ENTITY_LAYOUTS_MODE_DYNAMIC) {
          $this->processParagraphsEntity($entity, $entity_type, $langcode);
        }
        else {
          // The paragraphs field should not appear in normal mode.
          unset($entity->content[self::FIELD_PARAGRAPHS]);
        }
      }
    }
  }

  /**
   * Process the Paragraphs entity.
   *
   * @param object $entity
   *   The entity.
   * @param string $entity_type
   *   The entity type.
   * @param string $langcode
   *   The langcode
   */
  protected function processParagraphsEntity($entity, $entity_type, $langcode) {

    // Replace the entity content with the content of the paragraphs
    // field.
    $entity->content = field_view_field($entity_type, $entity, self::FIELD_PARAGRAPHS, array('label' => 'hidden'), $langcode);

    // If there is an 'entity_content' paragraph item, replace its content
    // with the current entity.
    if (isset($entity->content['#items'])) {
      foreach ($entity->content['#items'] as $paragraphs_index) {
        foreach (array_keys($entity->content) as $content_row_id) {
          if (!is_array($entity->content[$content_row_id])) {
            continue;
          }

          if (isset($entity->content[$content_row_id]['entity']['paragraphs_item'][$paragraphs_index['value']]) && $entity->content[$content_row_id]['entity']['paragraphs_item'][$paragraphs_index['value']]['#bundle'] == 'entity_content') {
            $entity->content[$content_row_id]['entity']['paragraphs_item'][$paragraphs_index['value']]['content'] = $this->contentBuffer;
          }
        }
      }
    }
  }

  /**
   * Get the correct language for a field.
   *
   * @param string $entity_type
   *   The entity type.
   * @param object $entity
   *   The entity
   * @param string $field_name
   *   The field name
   * @param string $langcode
   *   The language code
   *
   * @return string
   *   The language code.
   */
  protected function fieldLanguage($entity_type, $entity, $field_name, $langcode) {
    return field_language($entity_type, $entity, $field_name, $langcode);
  }
}

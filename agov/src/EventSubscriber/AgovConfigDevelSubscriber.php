<?php

namespace Drupal\agov\EventSubscriber;

use Drupal\config_devel\Event\ConfigDevelEvents;
use Drupal\config_devel\Event\ConfigDevelSaveEvent;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;

class AgovConfigDevelSubscriber implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   */
  public function doSave(ConfigDevelSaveEvent $event) {
    $optionalModules = ['workbench_moderation'];
    $data = $event->getData();

    if (isset($data['third_party_settings'])) {
      foreach ($data['third_party_settings'] as $key => $value) {
        // If this is an optional module, then remove the config.
        if (in_array($key, $optionalModules)) {
          unset($data['third_party_settings'][$key]);

          // Now find the module in the dependencies list and remove that.
          foreach ($data['dependencies']['module'] as $i => $module) {
            if ($module === $key) {
              unset($data['dependencies']['module'][$i]);
            }
          }
        }
      }
    }
    $event->setData($data);
  }

  /**
   * {@inheritdoc}
   */
  public static function getSubscribedEvents() {
    $events[ConfigDevelEvents::SAVE][] = ['doSave'];
    return $events;
  }

}

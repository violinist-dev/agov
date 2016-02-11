<?php

/**
 * @file
 * Contains \Drupal\agov\Tests\ScheduledPublicationTest.
 */

namespace Drupal\agov\Tests;

/**
 * Test the scheduled publications.
 *
 * @group agov
 */
class ScheduledPublicationTest extends AgovTestBase {

  /**
   * An array of modules to be installed.
   *
   * @var array
   */
  public static $modules = ['agov_scheduled_updates'];

  /**
   * The admin user.
   *
   * @var \Drupal\user\Entity\User
   */
  protected $adminUser;

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    parent::setUp();
    $this->adminUser = $this->drupalCreateUser([
      'administer nodes',
      'administer scheduled update types',
      'view scheduled update entities',
      'create scheduled_publications scheduled updates',
      'delete any scheduled_publications scheduled updates',
      'edit any scheduled_publications scheduled updates',
      'create publication content',
      'access content overview',
      'bypass node access',
      'administer content types',
    ]);
  }

  /**
   * Test the scheduled publications is available and working.
   */
  public function testScheduledPublication() {
    $this->drupalLogin($this->adminUser);
    // Create an unpublished node with a future publication date.
    $this->drupalGet('node/add/publication');
    $this->assertText('scheduled publication');
    $this->drupalPostForm(NULL, [], 'Add new scheduled publish date');
    $this->drupalPostAjaxForm(NULL, [
      'created[0][value][date]' => '2016-02-11',
      'created[0][value][time]' => '20:57:29',
    ], 'Create scheduled publish date');
    // @todo, rewrind the publication date to be in the past.
    // @todo, run scheduled updates.
    // @todo, assert the node is published.
  }

}

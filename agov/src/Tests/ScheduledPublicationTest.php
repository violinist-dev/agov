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
    $this->adminUser = $this->drupalCreateUser([]);
  }

  /**
   * Test the scheduled publications is available and working.
   */
  public function testScheduledPublication() {
    $this->drupalLogin($this->adminUser);
  }

}

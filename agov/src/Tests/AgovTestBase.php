<?php

/**
 * @file
 * Contains \Drupal\agov\Tests\AgovTestBase.
 */

namespace Drupal\agov\Tests;

use Drupal\simpletest\WebTestBase;
use Symfony\Component\BrowserKit\Request;

/**
 * Base class for testing aGov.
 */
abstract class AgovTestBase extends WebTestBase {

  /**
   * Override the installation profile to our testing profile.
   *
   * @var string
   */
  protected $profile = 'agov';

  protected static $configSchemaCheckerExclusions = array(
    // Following are used to test lack of or partial schema. Where partial
    // schema is provided, that is explicitly tested in specific tests.
    'config_schema_test.noschema',
    'config_schema_test.someschema',
    'config_schema_test.schema_data_types',
    'config_schema_test.no_schema_data_types',
    // Used to test application of schema to filtering of configuration.
    'config_test.dynamic.system',
    'page_manager.page_variant.panels',
  );

}

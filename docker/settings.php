<?php

$settings['hash_salt'] = getenv('DRUPAL_HASH_SALT') ?: '';
$settings['container_yamls'][] = __DIR__ . '/services.yml';

// Connection to persistent storage.
$databases['default']['default'] = array (
  'database' => getenv('DRUPAL_DB_NAME') ?: '',
  'username' => getenv('DRUPAL_DB_USER') ?: '',
  'password' => getenv('DRUPAL_DB_PASS') ?: '',
  'prefix' => getenv('DRUPAL_DB_PREFIX') ?: '',
  'host' => getenv('DRUPAL_DB_HOST') ?: '',
  'port' => getenv('DRUPAL_DB_PORT') ?: '3306',
  'namespace' => getenv('DRUPAL_DB_NAMESPACE') ?: 'Drupal\\Core\\Database\\Driver\\mysql',
  'driver' => getenv('DRUPAL_DB_DRIVER') ?: 'mysql',
);

$settings['install_profile'] = getenv('DRUPAL_PROFILE') ?: 'standard';

$config_directories = array(
  'sync' => getenv('DRUPAL_DIR_CONFIG_SYNC') ?: '',
);

// Allows for a "last say" on an environments configuration.
if (file_exists(__DIR__ . '/settings.local.php')) {
  include __DIR__ . '/settings.local.php';
}

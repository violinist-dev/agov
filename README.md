# aGov

7.x-3.x build status: ![](https://circleci.com/gh/previousnext/agov/tree/7.x-3.x.png?circle-token=:circle-token)
8.x-1.x build status: ![](https://circleci.com/gh/previousnext/agov/tree/8.x-1.x.png?circle-token=:circle-token)

## Getting Started

See [the aGov readme](https://github.com/previousnext/agov/blob/8.x-1.x/agov/README.md)

### Troubleshooting and docs

See [the docs](https://github.com/previousnext/agov/blob/8.x-1.x/agov/docs/index.md)

## Testing

### Run all tests

    make test

### Debug Kernel tests

Ensure you have:

    export SIMPLETEST_DB=mysql://root:@localhost/tests

To run:

    ./vendor/bin/phpunit -c core profiles/agov/tests/src/Kernel/DefaultConfigTest.php

## Updating Contrib Modules

Many contrib modules don't provide an upgrade path for config schema changes. In order
to avoid any issues, follow these steps:

1. Install from the UI, and do **NOT** select any of the optional modules.
2. Update your module in the drush make file, then run `make make-contrib`.
3. Run `drush updb` to run any db and schema updates.
4. Re-export config using `make config-export`.

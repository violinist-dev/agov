# Getting Started

See [the aGov readme](https://github.com/previousnext/agov/blob/8.x-1.x/agov/README.md)

### Troubleshooting and docs

See [the docs](https://github.com/previousnext/agov/blob/8.x-1.x/agov/docs/index.md)

# Running Tests

### Run all tests

    make test

### Debug Kernel tests

Ensure you have:

    export SIMPLETEST_DB=mysql://root:@localhost/tests

To run:

    ./vendor/bin/phpunit -c core profiles/agov/tests/src/Kernel/DefaultConfigTest.php


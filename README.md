# aGov

7.x-3.x build status: ![](https://circleci.com/gh/previousnext/agov/tree/7.x-3.x.png?circle-token=:circle-token)
8.x-1.x build status: ![](https://circleci.com/gh/previousnext/agov/tree/8.x-1.x.png?circle-token=:circle-token)

## Getting Started

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

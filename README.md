# Running Tests

### Run all tests

    phing tests

### Debug Kernel tests

Ensure you have:

    export SIMPLETEST_DB=mysql://root:@localhost/tests

To run:

    ./vendor/bin/phpunit -c core profiles/agov/tests/src/Kernel/DefaultConfigTest.php


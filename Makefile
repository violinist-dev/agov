#!/usr/bin/make -f

cc_green="\033[0;32m" #Change text to green.
cc_end="\033[0m" #Change text back to normal.

APP_DIR=${PWD}/app
APP_URI=http://agov.dev
APP_PASSWORD=password

DRUSH_CMD=drush -r ${APP_DIR}
DB_URL=mysql://drupal:drupal@localhost/local
INSTALL_OPTIONS=agov_install_additional_options.install=1

PHPCS_STANDARD="vendor/drupal/coder/coder_sniffer/Drupal"
PHPCS_EXTENSIONS="php,module,inc,install,test,profile,theme"
PHPCS_EXCLUSIONS=""
PHPCS_REPORT_FILE="build/logs/checkstyle.xml"
PHPCS_DIRS="agov/modules/custom"

CIRCLE_PHP=/home/ubuntu/.phpenv/shims/php
CIRCLE_PHP_VERSION?=5.5.11

EXPORT_MODULES=agov agov_standard_page agov_article agov_publication agov_default_content agov_password_policy agov_scheduled_updates agov_media

.PHONY: list build make install styleguide test

# Display a list of the commands
list:
	@$(MAKE) -pRrq -f $(lastword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/^# File/,/^# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1n}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'

# Build steps for local dev
build: init mkdirs lint-php styleguide make

# Builds steps for CI
ci-build: init mkdirs ci-vhost styleguide make

clean:
	chmod u+w ${APP_DIR}/sites/default || true
	rm -rf ${APP_DIR} agov/modules/contrib agov/themes/contrib

init:
	@echo ${cc_green}">>> Installing dependencies..."${cc_end}
	composer install --prefer-dist --no-progress
	bundle install --path vendor/bundle
	npm install

mkdirs:
	@echo ${cc_green}">>> Creating dirs..."${cc_end}
	mkdir -p ${APP_DIR}/profiles ${APP_DIR}/sites/default/files/tmp ${APP_DIR}/sites/default/private ${APP_DIR}/sites/simpletest build/logs/simpletest
	chmod -R 2775 ${APP_DIR}/sites/default/files ${APP_DIR}/sites/default/private ${APP_DIR}/sites/simpletest
	chmod -R 777 ${APP_DIR}/sites/simpletest
	ln -sv ${PWD}/agov ${APP_DIR}/profiles/agov

make:
	cd ${APP_DIR} && ../bin/drush make -y profiles/agov/drupal-org.make --no-core --contrib-destination=profiles/agov
	cd ${APP_DIR} && ../bin/drush make -y profiles/agov/drupal-org-core.make --no-cache --prepare-install

install:
	cd ${APP_DIR} && ../bin/drush site-install agov -y --site-name=aGov --account-pass='${APP_PASSWORD}' --db-url=${DB_URL} ${INSTALL_OPTIONS}

lint-php:
	@echo ${cc_green}">>> Linting PHP..."${cc_end}
	bin/phpcs --standard=${PHPCS_STANDARD} --extensions=${PHPCS_EXTENSIONS} --ignore=${PHPCS_EXCLUSIONS} ${PHPCS_DIRS}


ci-lint: ci-lint-php ci-lint-js ci-lint-sass

ci-lint-php:
	@echo ${cc_green}">>> Linting PHP..."${cc_end}
	bin/phpcs --report=checkstyle --report-file=${PHPCS_REPORT_FILE} --standard=${PHPCS_STANDARD} --extensions=${PHPCS_EXTENSIONS} --ignore=${PHPCS_EXCLUSIONS} ${PHPCS_DIRS}

ci-lint-js:
	node_modules/.bin/gulp lint:js-with-fail

ci-lint-sass:
	# Temporarily disable sass lint failing, until Issue #2650652 is complete.
	# - node_modules/.bin/gulp lint:sass-with-fail

styleguide:
	@echo ${cc_green}">>> Generate the styles..."${cc_end}
	node_modules/.bin/gulp

config-export:
	${DRUSH_CMD} config-devel-export ${EXPORT_MODULES}

ci-vhost:
	@echo ${cc_green}"PHP version: "${CIRCLE_PHP_VERSION}${cc_end}
	sudo cp vhost /etc/apache2/sites-available/agov
	sudo sed -i -e 's@##app.uri##@${APP_URI}@g' -e 's@##app.dir##@${APP_DIR}@g' -e 's@##php.version##@${CIRCLE_PHP_VERSION}@g' /etc/apache2/sites-available/agov
	a2ensite agov
	a2enmod rewrite
	sudo service apache2 restart

devify:
	chmod u+w ${APP_DIR}/sites/default
	cp ${APP_DIR}/sites/example.settings.local.php ${APP_DIR}/sites/default/settings.local.php
	${DRUSH_CMD} en -y simpletest config_devel

test:
	cd ${APP_DIR} && sudo -u www-data php ./core/scripts/run-tests.sh \
	--concurrency 8 \
	--verbose \
	--dburl ${DB_URL}  \
	--url ${APP_URI}/ \
	--module agov

ci-test:
	cd ${APP_DIR} && sudo -u www-data ${CIRCLE_PHP} ./core/scripts/run-tests.sh \
	--concurrency 8 \
	--verbose \
	--sqlite /tmp/test-db.sqlite \
	--dburl sqlite://localhost//tmp/test-db.sqlite  \
	--php ${CIRCLE_PHP} \
	--url ${APP_URI} \
	--module agov

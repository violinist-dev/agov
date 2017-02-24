# aGov [![Build Status](https://travis-ci.org/previousnext/agov.svg?branch=2.x)](https://travis-ci.org/previousnext/agov)

## Download

aGov is available as a full drupal site in tgz and zip format at: http://drupal.org/project/agov

## Building from Source

Source is available from GitHub at https://github.com/previousnext/agov

## Requirements

* Vagrant 1.6+ (+ Plugins) - http://docs.vagrantup.com/v2/installation
* Virtualbox - https://www.virtualbox.org/wiki/Downloads

**Install Vagrant plugins**

Run the following via the command line:

```bash
# Virtualbox support.
$ vagrant plugin install vagrant-vbguest

# Automatically assigns an IP address.
$ vagrant plugin install vagrant-auto_network

# Adds "/etc/hosts" (local DNS) records.
$ vagrant plugin install vagrant-hostsupdater
```

## Getting started

**1) Start the VM.**

```bash
$ vagrant up
```

All commands from here are to be run within the VM. This can be done via the command:

```bash
$ vagrant ssh
```

This will take you to the root of the project **inside** of the vm.

**2) Pull down the dependencies**

```bash
$ composer install --prefer-dist
$ bundle install --path vendor/bundle
$ npm install
```

**3) Build the project**

```bash
$ phing
```

The default build task is to build the project. To call this step directly, run:

```bash
$ phing build
```

**3) Go to the site on the following domain**

```
http://agov.dev
```

## Testing

```bash
$ phing test
```

## List other targets

```bash
$ phing -l
```

The output for this should look something like the following:

```
Default target:
-------------------------------------------------------------------------------
 build            Build (or rebuild) the project.

Main targets:
-------------------------------------------------------------------------------
 build            Build (or rebuild) the project.
 build:dev        Build (or rebuild) the project with development dependencies.
 ci:phpcs         Find coding standard violations using PHP_CodeSniffer creating a log file for the continuous integration server.
 ci:phpmd         Perform project mess detection using PHPMD creating a log file for the continuous integration server
 clean            Cleans up autogenerated files
 config:export    Export all of the configuration for the defined modules.
 dev:modules      Install the development modules.
 gulp:build       Generate all compiled Sass and style guide resources.
 install          Install aGov with standard configuration.
 login            Generate a one-time login link
 make             Compile aGov from a make file
 phpcpd           Find duplicate code using PHPCPD
 phpcs            Find coding standard violations using PHP_CodeSniffer and print human readable output. Intended for usage on the command line before committing.
 phploc           Measure project size using PHPLOC
 phpmd            Perform project mess detection using PHPMD and print human readable output. Intended for usage on the command line before committing.
 phpqatools:init  Setup steps for PHP build tasks.
 prepare          Setup the project
 styleguide:link  Link the style guide to make it publicly available.
 test             Run the test suite
```

### Gulp

- **gulpfile.js** - Contains the Gulp task definitions.
- **package.json** - Specifies the Node.js modules needed for the Gulp tasks and the KSS style guide. New modules can be added with `npm install <name> --save-dev`.
- **npm-shrinkwrap.json** - This file locks specific versions of Node.js modules so that all developers on the project are using the exact same versions. It is generated with `npm shrinkwrap --dev` and should be checked into the Git repository.

Many of the front-end development tasks are run with gulp. This include compiling Sass and generating a styleguide.

To run the default gulp command, type:

```
gulp
```

To see a list of gulp commands, type:

```
gulp -T
```

### Troubleshooting and docs

See [the docs](https://github.com/previousnext/agov/blob/8.x-1.x/docs/index.md)
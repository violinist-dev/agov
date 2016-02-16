## Theming

### Table of Contents

1. [Initial Setup](theming.md#initial-setup)
2. [Gulp](theming.md#task-automation-with-gulp)
3. [Styleguide](theming.md#styleguide-generation-with-kss-node)
4. [CSS Compilation](theming.md#css-compilation-with-sass--3rd-party-libraries)
5. [Coding Standards](theming.md#maintaining-coding-standards)
6. [Sass structure](theming.md#sub-theme-sass-structure)
7. [Accessibility](theming.md#maintaining-accessibility)
8. [Twig](theming.md#twig) (coming soon)

### Initial setup

Ensure the following files are included in your root folder:

- **[Gemfile](https://github.com/previousnext/agov/blob/8.x-1.x/Gemfile)** - Specifies the Ruby Gems needed for the Sass compilation and linting.
- **[Gemfile.lock](https://github.com/previousnext/agov/blob/8.x-1.x/Gemfile.lock)** - This file locks specific versions of the Ruby Gems so that all developers on the project are using the exact same versions. It is generated with `bundle install` and should be checked into the Git repository.
- **[package.json](https://github.com/previousnext/agov/blob/8.x-1.x/package.json)** - Specifies the Node.js modules needed for the Gulp tasks and the KSS styleguide. New modules can be added with `npm install <name> --save-dev`.
- **[npm-shrinkwrap.json](https://github.com/previousnext/agov/blob/8.x-1.x/npm-shrinkwrap.json)** - This file locks specific versions of Node.js modules so that all developers on the project are using the exact same versions. It is generated with `npm shrinkwrap --dev` and should be checked into the Git repository.
- **[gulpfile.js](https://github.com/previousnext/agov/blob/8.x-1.x/gulpfile.js)** - Contains the Gulp task definitions.
- **[.scss-lint.yml](https://github.com/previousnext/agov/blob/8.x-1.x/.scss-lint.yml)** - Sass linting configuration file
- **[.eslintrc](https://github.com/previousnext/agov/blob/8.x-1.x/.eslintrc)** - JS linting configuration file

Ensure the following dependencies have been installed.

```bash
$ bundle install --path vendor/bundle
$ npm install
$ npm shrinkwrap --dev
```

It is recommended to commit Gemfile.lock and npm-shrinkwrap.json to the projects repo.

### Task automation with Gulp

[Gulp](https://www.npmjs.com/package/gulp) is a toolkit that helps us automate painful or time-consuming tasks in our development workflow.

Many of the front-end development tasks are run with gulp. This include compiling Sass and generating a styleguide and are all configured with the one file;

- **[gulpfile.js](https://github.com/previousnext/agov/blob/8.x-1.x/gulpfile.js)** - Contains the Gulp task definitions.

To run the default gulp command, type:

```
$ gulp
```

To see a list of gulp commands, type:

```
$ gulp -T
```

Gulp is configured to run from agov_whitlam by default. To change this to your custom theme;

1. Edit the gulpfile.js
2. Change the `compiledTheme` variable to the location of your sub-theme.

**Adding new tasks**

New tasks should follow the [API](https://github.com/gulpjs/gulp/blob/master/docs/API.md#gulptaskname-deps-fn) (specifically dependencies and async support)

### Styleguide generation with KSS Node

[KSS Node](https://www.npmjs.com/package/kss) is a Node.js implementation of Knyle Style Sheets (KSS), "a documentation syntax for CSS" that's intended to have syntax readable by humans and machines.

aGov includes the agov_base Sass in any sub-themes styleguide, so it compiles from two sources;

1. The `options.rootPath.baseTheme` which is set to agov_base.
2. The `options.rootPath.subTheme` or `compiledTheme` which defaults to agov_whitlam but can be any sub-theme.

To avoid duplication in the styleguide the current Sass files are only documented in one place (agov_base). 
Any new components that you add to a sub-theme will need to be documented in the sub-theme to be included in the styleguide.

The styleguide is generated on the default gulp command, but can also be created/updated using:

```
$ gulp styleguide
```

Once generate you can view the styleguide at:

```
http://agov.dev/styleguide
```

Please refer to the [KSS Node Documentation](https://github.com/kss-node/kss/blob/spec/SPEC.md) for details about how to format your Sass documentation.

To include additional Stylesheets or Javascript files in the styleguide;

1. Edit the gulpfile.js
2. Find the `options.styleGuide` section
3. Edit the `options.styleGuide.css` and `options.styleGuide.js` paths as required.

To change the name of the styleguide;

1. Edit the gulpfile.js
2. Find the `options.styleGuide` section
3. Edit the `options.styleGuide.title` line

To edit the styleguides homepage text just edit your themes /sass/style-guide/homepage.md file

### CSS compilation with Sass + 3rd Party libraries

The following sass modules are shared with all .scsss files
- [Breakpoint](http://breakpoint-sass.com/)
- [Chroma](https://github.com/JohnAlbin/chroma)
- [Compass support](http://compass-style.org/reference/compass/support/)
- [Compass sprites](http://compass-style.org/reference/compass/utilities/sprites/)
- [Compass CSS3](http://compass-style.org/reference/compass/css3/)
- [Typey](https://github.com/jptaranto/typey)
- [Zen Grids](http://next.zengrids.com/help/)

Sass is compiled in the default gulp task but also can be generated with the following:

```
# Development friendly output
$ gulp styles

# Production ready output
$ gulp styles:production
```

The agov_base CSS is only compiled by the standalone task;

```
$ gulp styles:base-theme
```

### Maintaining coding standards

By default Linting is required for all custom Sass and JS files.

Configuration of the linting tools is provided by Scaffold but can be configured;

- **[.scss-lint.yml](https://github.com/previousnext/agov/blob/8.x-1.x/.scss-lint.yml)** - Sass linting configuration file
- **[.eslintrc](https://github.com/previousnext/agov/blob/8.x-1.x/.eslintrc)** - JS linting configuration file

To exclude 3rd party JS files from being linted:

1. Edit the gulpfile.js
2. Find the `options.eslint.files` and add a line starting with ! to exclude it.

**SMACSS, BEM and DRY**

Be sure to follow the [SMACSS](http://smacss.com/) approach to categorisation, 
breaking your Sass down into modular components.

As well as the following the basic [BEM](http://bem.info/) naming pattern.

Combined with DRY (don’t repeat yourself) approach to your Sass in general, 
will all ensure your theme meets current coding standards.

Because Drupal uses some of these names (ie. blocks and modules) 
we are using alternative names. They map to the original as follows:

```
# From SMACSS
module = component
submodule = variant
theme = variant

# From BEM
block = component
modifier = variant
```

### Sub-theme Sass structure

Sass files are all compiled into the one styles.css file in the following order:

```
# Outputs as styles.css with everything else included in it.
/sass/styles.scss

# Imports all 3rd party Sass libraries and custom variables.
/sass/_init.scss

# Custom variables; edit these first to change presentation.
/sass/init/_colors.scss
/sass/init/_typography.scss
/sass/init/_breakpoints.scss

# Custom mixins.
/sass/library/*

# Base styles; resets, element defaults, fonts, etc.
/sass/base/*

# Layouts and grid systems.
/sass/layouts/*

# Components; independently styled components that can live anywhere in a layout.
/sass/components/*
```

For basic re-theming of the existing agov_whitlam theme, editing the variables inside the `/sass/init` directory should be all you need to do.

The STARTERKIT contains this folder structure and some example Sass files.

### Maintaining accessibility

The agov_base theme already has a lot of accessibility improves baked into it.
It is highly recommended to use the STARTERKIT sub-theme as the basis for your custom theme to leverage this accessibility.

Though even if you do there are still a few things to keep in mind:

- Colour contrast
- Heading heirarchy and page structure
- Providing alternative text for images and link text on icons
- Ensuring [hidden content is accessible and doesn't create keyboard traps](https://www.previousnext.com.au/blog/so-many-ways-hide)

To make sure you aren't introducing any accessibility errors 
it is recommended that you regularly run your theme through a checker like the [HTML_CodeSniffer](https://squizlabs.github.io/HTML_CodeSniffer/)

### Twig

TBC.

[back to index](index.md)

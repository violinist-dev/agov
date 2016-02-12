## Theming

### Initial setup

Ensure the following dependencies have been installed.

```bash
$ bundle install --path vendor/bundle
$ npm install
$ npm shrinkwrap --dev
```

It is recommended to commit Gemfile.lock and npm-shrinkwrap.json to the projects repo.

### Task automation with Gulp

[Gulp](https://www.npmjs.com/package/gulp) is a toolkit that helps us automate painful or time-consuming tasks in our development workflow.

Many of the front-end development tasks are run with gulp. This include compiling Sass and generating a styleguide.

- **gulpfile.js** - Contains the Gulp task definitions.
- **package.json** - Specifies the Node.js modules needed for the Gulp tasks and the KSS style guide. New modules can be added with `npm install <name> --save-dev`.
- **npm-shrinkwrap.json** - This file locks specific versions of Node.js modules so that all developers on the project are using the exact same versions. It is generated with `npm shrinkwrap --dev` and should be checked into the Git repository.

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

The styleguide is generated on the default gulp command, but can also be created/updated using:

```
$ gulp styleguide
```

Once generate you can view the styleguide at:

```
http://agov.dev/styleguide
```

Please refer to the [KSS Node Documentation](https://github.com/kss-node/kss/blob/spec/SPEC.md) for details about how to format your Sass comments.

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

- Sass linting config: .scss-lint.yml
- JS linting config: .eslintrc

To exclude 3rd party JS files from being linted:

1. Edit the gulpfile.js
2. Find the `options.eslint.files` and add a line starting with ! to exclude it.

**SMACSS, BEM and DRY**

Be sure to follow the [SMACSS](http://smacss.com/) approach to categorisation, 
breaking your Sass down into modular components.

As well as the following the [BEM](http://bem.info/) naming pattern.

Combined with DRY (don’t repeat yourself) approach to your Sass in general, will all ensure your theme meets current coding standards.

### Twig

TBC.

[back to index](index.md)

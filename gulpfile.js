'use strict';

var Promise = require('es6-promise').Promise;
var path = require('path');

var options = {};

// #############################
// Edit these paths and options.
// #############################

// The subTheme that gulp compiles Sass from.
// Change this to your custom sub-subTheme.
var compiledTheme = '/app/profiles/agov/themes/contrib/agov_whitlam/';

// The root paths are used to construct all the other paths in this
// configuration. The "project" root path is where this gulpfile.js is located.
// While Zen distributes this in the theme root folder, you can also put this
// (and the package.json) in your project's root folder and edit the paths
// accordingly.
options.rootPath = {
  project     : __dirname + '/',
  web         : __dirname + '/app/',
  baseTheme   : __dirname + '/app/profiles/agov/themes/contrib/agov_base/',
  styleGuide  : __dirname + '/app/styleguide/',
  subTheme    : __dirname + compiledTheme
};

options.baseTheme = {
  root  : options.rootPath.baseTheme,
  css   : options.rootPath.baseTheme + 'css/',
  sass  : options.rootPath.baseTheme + 'sass/',
  js    : options.rootPath.baseTheme + 'js/',
  sassjs: options.rootPath.baseTheme + 'source/components/'
};

options.subTheme = {
  root  : options.rootPath.subTheme,
  css   : options.rootPath.subTheme + 'css/',
  sass  : options.rootPath.subTheme + 'sass/',
  js    : options.rootPath.subTheme + 'js/',
  sassjs: options.rootPath.subTheme + 'source/components/'
};


// Set the URL used to access the Drupal website under development. Without protocol.
options.drupalURL = 'agov.dev';

// Define the node-sass/eyeglass configuration.
options.sass = {
  includePaths: [
    __dirname + '/node_modules',
    options.baseTheme.sass,
    options.subTheme.sass
  ],
  outputStyle: 'expanded'
};

// Base theme Sass should be compiled separately to sub theme sass.
options.baseThemeSassFiles = [
  options.baseTheme.sass + '**/*.scss',
  // Do not open Sass partials as they will be included as needed.
  '!' + options.baseTheme.sass + '**/_*.scss',
  // Do not open the UI Kit.
  '!' + options.baseTheme.sass + '/ui-kit.scss'
];
options.subThemeSassFiles = [
  options.subTheme.sass + '**/*.scss',
  // Do not open Sass partials as they will be included as needed.
  '!' + options.subTheme.sass + '**/_*.scss'
];

// Define which browsers to add vendor prefixes for.
options.autoprefixer = {
  browsers: [
    'last 2 versions',
    'ie >= 9',
    'and_chr >= 2.3'
  ]
};

// Define the style guide paths and options.
options.styleGuide = {
  source: [
    options.baseTheme.sass,
    options.baseTheme.css + 'style-guide/',
    options.subTheme.sass
  ],
  destination: options.rootPath.styleGuide,
  builder: options.rootPath.project + 'node_modules/kss-node-offscreen-template',

  // The css and js paths are URLs, like '/misc/jquery.js'.
  // The following paths are relative to the generated style guide.
  css: [
    path.relative(options.rootPath.styleGuide, options.baseTheme.css + 'style-guide/kss-only.css'),
    path.relative(options.rootPath.styleGuide, options.baseTheme.css + 'styles.css'),
    path.relative(options.rootPath.styleGuide, options.subTheme.css + 'styles.css')
  ],
  js: [
    '/core/assets/vendor/jquery/jquery.min.js',
    path.relative(options.rootPath.styleGuide, options.baseTheme.sass + 'components/primary-navigation/primary-navigation.js'),
    path.relative(options.rootPath.styleGuide, options.subTheme.js + 'script.js')
  ],

  homepage: 'homepage.md',
  title: 'aGov Style Guide'
};

// Define the paths to the JS files to lint.
options.eslint = {
  files  : [
    options.subTheme.js + '**/*.js',
    '!' + options.subTheme.js + '**/*.min.js',
    '!' + __dirname + '/node_modules'
  ]
};

// If your files are on a network share, you may want to turn on polling for
// Gulp watch. Since polling is less efficient, we disable polling by default.
options.gulpWatchOptions = {};
// options.gulpWatchOptions = {interval: 1000, mode: 'poll'};

// ################################
// Load Gulp and tools we will use.
// ################################
var gulp        = require('gulp'),
  $           = require('gulp-load-plugins')(),
  browserSync = require('browser-sync').create(),
  del         = require('del'),
// gulp-load-plugins will report "undefined" error unless you load gulp-sass manually.
  sass        = require('gulp-sass'),
  sassGlob    = require('gulp-sass-glob'),
  spawn       = require('child_process').spawn,
  eyeglass    = require('eyeglass'),
  sassLint    = require('gulp-sass-lint'),
  kss         = require('kss');

// The default task.
gulp.task('default', ['build']);

// #################
// Build everything.
// #################
gulp.task('build', ['styles:production', 'styleguide']);

// ##########
// Build CSS.
// ##########
gulp.task('styles', ['clean:css'], function() {
  return gulp.src(options.subThemeSassFiles)
    .pipe(sassGlob())
    .pipe($.sourcemaps.init())
    .pipe(sass(eyeglass(options.sass)).on('error', sass.logError))
    .pipe($.autoprefixer(options.autoprefixer))
    .pipe($.size({showFiles: true}))
    .pipe($.sourcemaps.write('./'))
    .pipe(gulp.dest(options.subTheme.css))
    .pipe($.if(browserSync.active, browserSync.stream({match: '**/*.css'})));
});

gulp.task('styles:production', ['clean:css'], function() {
  return gulp.src(options.subThemeSassFiles)
    .pipe(sassGlob())
    .pipe(sass(eyeglass(options.sass)).on('error', sass.logError))
    .pipe($.autoprefixer(options.autoprefixer))
    .pipe($.size({showFiles: true}))
    .pipe(gulp.dest(options.subTheme.css));
});

gulp.task('styles:base-theme', ['clean:base-theme-css'], function() {
  return gulp.src(options.baseThemeSassFiles)
    .pipe(sassGlob())
    .pipe(sass(eyeglass(options.sass)).on('error', sass.logError))
    .pipe($.autoprefixer(options.autoprefixer))
    .pipe($.size({showFiles: true}))
    .pipe(gulp.dest(options.baseTheme.css));
});

// ##################
// Build style guide.
// ##################
gulp.task('styleguide', ['clean:styleguide'], function(cb) {
  kss(options.styleGuide, cb);
});

// Debug the generation of the style guide with the --verbose flag.
gulp.task('styleguide:debug', ['clean:styleguide'], function(cb) {
  options.styleGuide.verbose = true;
  kss(options.styleGuide, cb);
});

// #########################
// Lint Sass and JavaScript.
// #########################
gulp.task('lint', ['lint:sass', 'lint:js']);

// Lint JavaScript.
gulp.task('lint:js', function() {
  return gulp.src(options.eslint.files)
    .pipe($.eslint())
    .pipe($.eslint.format());
});

// Lint JavaScript and throw an error for a CI to catch.
gulp.task('lint:js-with-fail', function() {
  return gulp.src(options.eslint.files)
    .pipe($.eslint())
    .pipe($.eslint.format())
    .pipe($.eslint.failOnError());
});

// Lint Sass.
gulp.task('lint:sass', function() {
  return gulp.src([
      options.subTheme.sass + '**/*.scss'
    ])
    .pipe(sassLint())
    .pipe(sassLint.format());
});

// Lint Sass and throw an error for a CI to catch.
gulp.task('lint:sass-with-fail', function() {
  return gulp.src(options.subTheme.sass + '**/*.scss')
    .pipe(sassLint())
    .pipe(sassLint.format())
    .pipe(sassLint.failOnError());
});

// ##############################
// Watch for changes and rebuild.
// ##############################
gulp.task('watch', ['browser-sync', 'watch:lint-and-styleguide', 'watch:js']);

gulp.task('browser-sync', ['watch:css'], function() {
  return browserSync.init({
    proxy: options.drupalURL,
    host: options.drupalURL,
    open: false
  });
});

gulp.task('watch:css', ['styles'], function() {
  return gulp.watch(options.subTheme.sass + '**/*.scss', options.gulpWatchOptions, ['styles']);
});

gulp.task('watch:lint-and-styleguide', ['styleguide', 'lint:sass'], function() {
  return gulp.watch([
    options.subTheme.sass + '**/*.scss',
    options.subTheme.sass + '**/*.hbs'
  ], options.gulpWatchOptions, ['styleguide', 'lint:sass']);
});

gulp.task('watch:js', ['lint:js'], function() {
  return gulp.watch(options.eslint.files, options.gulpWatchOptions, ['lint:js']);
});

// ######################
// Clean all directories.
// ######################
gulp.task('clean', ['clean:css', 'clean:styleguide']);

// Clean style guide files.
gulp.task('clean:styleguide', function() {
  // You can use multiple globbing patterns as you would with `gulp.src`
  return del([
      options.styleGuide.destination + '*.html',
      options.styleGuide.destination + 'public',
      options.subTheme.css + '**/*.hbs'
    ], {force: true});
});

// Clean Base Theme CSS files.
gulp.task('clean:base-theme-css', function() {
  return del([
    options.baseTheme.root + '**/.sass-cache',
    options.baseTheme.css + '**/*.css',
    options.baseTheme.css + '**/*.map'
  ], {force: true});
});

// Clean CSS files.
gulp.task('clean:css', function() {
  return del([
      options.subTheme.root + '**/.sass-cache',
      options.subTheme.css + '**/*.css',
      options.subTheme.css + '**/*.map'
    ], {force: true});
});


// Resources used to create this gulpfile.js:
// - https://github.com/google/web-starter-kit/blob/master/gulpfile.js
// - https://github.com/north/generator-north/blob/master/app/templates/Gulpfile.js

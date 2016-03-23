# Theme customisation and override documentation

## Prerequisite knowledge

* Sass Preprocessor http://sass-lang.com/guide
* SMACSS https://smacss.com/
* Responsive layouts with Zen https://www.previousnext.com.au/blog/responsive-layouts-zen-5x

## What is a sub-theme?

Sub-themes allow Drupal themes to inherit stylesheets, template files, regions, screen shots, logo, favicon, and theme/preprocess functions from a parent theme. More information can be found on Drupal.org:
https://www.drupal.org/node/225125

Starterkits are pre-built sub-theme templates that allow you to replace the uppercase name of the theme e.g. "STARTERKIT" with your theme's machine name e.g. "my_theme"

## Themes that come with agov

**agov_base**
A base theme that contains the structural components of aGov. agov_base inherits from Classy and provides very minimally styled components.

**agov_whitlam**
A sub-theme of agov_base that has been lightly customized to show the aGov colour palette and font. *ENABLE this theme to see a standard representation of aGov*

**agov_STARTERKIT**
An example sub-theme that contains all the structure of agov_base so that you can use as a starting point to creating a sub-theme for your website.

## Theme Hierarchy diagram:

<pre>
+-----------------+  +--------------+
|                 |  |              |
| agov_STARTERKIT |  | agov_whitlam |
|                 |  |              |
+---+-------------+  +--+-----------+
    |                   |
    | +-----------------+
    | |
    v v
+-----------+
|           |
| agov_base |
|           |
+---+-------+
    |
    |
    |
    v
+-------------+
|             |
|   classy    |
|             |
+-------------+
</pre>

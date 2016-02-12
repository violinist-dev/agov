# agov_base

The aGov base theme. This theme provides the structure for aGov with very minimal styling.

# Want to customise this theme?

* Copy this agov_base folder (/profiles/agov/themes/agov/agov_base)
  * Paste it into /themes/custom
* Rename the copied folder to MY_THEME (this can be any machine name you like, but we'll use MY_THEME as the example.)
* Within this copy, rename the following files
  * Rename the agov_base.info.yml file to MY_THEME.info.yml
  * Rename the agov_base.libraries.yml to MY_THEME.libraries.yml
* Edit the newly renamed agov_base.info.yml
  * Change the following lines to suit your needs
    * `name = My Custom Theme`
    * `description = My custom aGov subtheme`
    * libraries 
      * Rename `agov_base/base` to `MY_THEME/base`
* Enable your subtheme
  * visit /admin/appearance
  * Click “Install and set default” on the appropriate subtheme you’ve created.
  * Visit your aGov site. Without any customisation this theme will be a black and white version of the default theme (agov_whitlam)
* Customise the theme. Check [the docs](https://github.com/previousnext/agov/blob/8.x-1.x/agov/docs/theming.md) for help.

## More information

For more information about theming in Drupal 8, please visit [this theming guide](https://www.drupal.org/theme-guide/8)

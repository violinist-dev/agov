/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document) {

  "use strict";

  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.agov_whitlam = {
    attach: function(context, settings) {

      // Menu responsive
      $(".block-superfish").prepend('<div class="menu-icon open active">menu<i class="fa fa fa-bars"></i></div><div class="menu-icon close">close<i class="fa fa-close"></i></div>');

      $(".block-superfish a.menuparent").after('<div class="sub-menu-icon"><i class="fa fa-plus"></i></div>');

      $(".menu-icon.open").click(function() {
        $(this).removeClass("active");
        $(".menu-icon.close").addClass("active");
        $(".sf-menu").addClass("active");
      });

      $(".menu-icon.close").click(function() {
        $(this).removeClass("active");
        $(".menu-icon.open").addClass("active");
        $(".sf-menu").removeClass("active");
      });

      $(".sub-menu-icon").click(function() {
        $(this).toggleClass("active");
        $(this).next().toggleClass("active");
      });
    }
  };

})(jQuery, Drupal, this, this.document);


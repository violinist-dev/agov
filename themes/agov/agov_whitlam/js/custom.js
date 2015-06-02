/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {
// Place your code here.
$(window).load(function(){
  $(document).ready(function() {
    // Variable for responsive js
    $(".block-superfish").prepend('<div class="search-icon open active">menu<i class="fa fa fa-bars"></i></div>');
    $(".block-superfish").prepend('<div class="search-icon close">close<i class="fa fa-close"></i></div>');
    $(".search-icon.open").click(function(){
      $(this).removeClass("active");
      $(".search-icon.close").addClass("active");
      $(".sf-menu").addClass("active");
    });

    $(".search-icon.close").click(function(){
      $(this).removeClass("active");
      $(".search-icon.open").addClass("active");
      $(".sf-menu").removeClass("active");
    });

    var $small = 568;
    var $medium = 768;

    function resize_responsive(){
      var width = window.innerWidth || document.documentElement.clientWidth;

      if (width < $medium) {
      }

      // Add equal heihgt for Content , sidebar for devices has width >= 1024px . Ex:
      if(width > $medium){
      }
    }

    //Call function responsive()
    resize_responsive();
    $(window).resize(function() {
      resize_responsive();
    });
  });
});
})(jQuery, Drupal, this, this.document);


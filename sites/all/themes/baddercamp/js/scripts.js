// TypeKit goodness
Drupal.behaviors.typekit = function(context) {
  try {
    Typekit.load();
  }
  catch(e) {};
}

// Login magic
Drupal.behaviors.badcampLogin = function(context) {
	$('#magical-login-box-link').bind('click', function(e) {

    // Prevent Default Link Behavior
    e.preventDefault();

    // Toggle the Login Box
    $('#login-dropdown-wrapper').slideToggle('slow', function() {});
		
    // Toggle the Login Text
    var text = $('#magical-login-box-link').text();
    $('#magical-login-box-link').text(text == "Log in" ? "Close" : "Log in");

    // Return False for Good Measure
    return false;
  });
}

// Mobile navigation.
Drupal.behaviors.badcampMobileNav = function(context) {
  $topLevel = $('#block-menu-primary-links li.expanded');

  $topLevel.each(function() {
    // Collapse the expanded sub menus.
    $(this).find('ul').css('display', 'none').addClass('collapsed');

    $(this).children('a').after('<a class="expand-arrow" href="#">&darr;</a>').siblings('a.expand-arrow').click(function() {
      var $childMenu = $(this).siblings('ul');

      if ($childMenu.is('.collapsed')) {
        $(this).html('&uarr;');
        $topLevel.siblings('ul:not(.collapsed)').slideUp().addClass('collapsed');
        $childMenu.slideDown().removeClass('collapsed');
      }
      else {
        $(this).html('&darr;');
        $childMenu.slideUp().addClass('collapsed');
      }
      return false;
    });
  });
};

// ask not for whom the bell tolls
Drupal.behaviors.bells = function(context) {
  // Only run on page load, not any AJAX attachments of behaviors.
  if (context !== document) {
    return;
  }

  var playSound = function() {
    try { $(this).children('audio')[0].play(); } catch (e) {};
  };

  // nb: this only works for non-IE browsers, but i'm not sorry about 
  $('#pirateship')
    .append('<audio id="bells" style="display: none;"><source src="/sites/all/themes/baddercamp/sounds/bellring.ogg" type="audio/ogg" /><source src="/sites/all/themes/baddercamp/sounds/bellring.mp3" type="audio/mpeg" /></audio>')
    .bind('click', playSound);
  $('#footer')
    .append('<audio id="whistle" style="display: none;"><source src="/sites/all/themes/baddercamp/sounds/whistle.ogg" type="audio/ogg" /><source src="/sites/all/themes/baddercamp/sounds/whistle.mp3" type="audio/mpeg" /></audio>')
    .bind('click', playSound);
};

// add mobile class to body
Drupal.behaviors.mobileclass = function (context) {
	if ($(window).width() < 720){
			$("body").addClass("mobile");
		}
		else {
			$("body").removeClass("mobile");
	}	
};

// pass mobile class on both doc ready and window resize
$(document).ready(Drupal.behaviors.mobileclass);
$(window).resize(Drupal.behaviors.mobileclass);


Drupal.behaviors.fancytables = function(context) {
  if($('body').is('.page-program-schedule')) {

    // make a proper thead element for this shit
    $('<thead />').insertBefore('.session-calendar > tbody');

    // COD doesn't provide fucking ids for the individual tables, jesus
    $('.view-content table:nth-child(2)').attr('id', 'saturday-schedule');
    $('.view-content table:nth-child(4)').attr('id', 'sunday-schedule');

    $('#saturday-schedule thead').append($('#saturday-schedule tbody tr:first-child'));
    $('#sunday-schedule thead').append($('#sunday-schedule tbody tr:first-child'));

    if ($('body').is('.mobile')) {
      //$('#saturday-schedule').tableScroll({height:300});
      //$('#sunday-schedule').tableScroll({height:300});
    }
  }
}

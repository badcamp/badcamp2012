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
    $('#login-dropdown-wrapper').slideToggle('slow');

    // Toggle the Login Text
    var text = $('#magical-login-box-link').text();
    $('#magical-login-box-link').text(text == "Log in" ? "Close" : "Log in");

    // Return False for Good Measure
    return false;
  });
}

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

  $('#pirateship').append('<audio id="bells" src="/sites/all/themes/baddercamp/sounds/bellring.mp3" style="display: none;"></audio>');
  $('#pirateship').bind('click', function() {
    //.play method only words on naked DOM object
    $('#bells')[0].play();
  });
}

  $('#pirateship')
    .append('<audio id="bells" style="display: none;"><source src="/sites/all/themes/baddercamp/sounds/bellring.ogg" type="audio/ogg" /><source src="/sites/all/themes/baddercamp/sounds/bellring.mp3" type="audio/mpeg" /></audio>')
    .bind('click', playSound);
  $('#footer')
    .append('<audio id="whistle" style="display: none;"><source src="/sites/all/themes/baddercamp/sounds/whistle.ogg" type="audio/ogg" /><source src="/sites/all/themes/baddercamp/sounds/whistle.mp3" type="audio/mpeg" /></audio>')
    .bind('click', playSound);
}

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
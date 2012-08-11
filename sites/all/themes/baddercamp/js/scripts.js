// TypeKit goodness
Drupal.behaviors.badcamp = function(context) {
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

    // TODO - Change the link to say Close

    // Return False for Good Measure
    return false;
  });
}


Drupal.behaviors.bells = function(context) {
  $('#pirateship').append('<audio id="bells" src="/sites/all/themes/baddercamp/sounds/bellring.mp3" style="display: none;"></audio>');
  $('#pirateship').bind('click', function() {
    var audio = document.getElementById('bells');
    audio.play();
  });
}
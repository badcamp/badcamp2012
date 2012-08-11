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

    // TODO - Change the link to say Close

    // Return False for Good Measure
    return false;
  });
}

// ask not for whom the bell tolls
Drupal.behaviors.bells = function(context) {
  // nb: this only works for non-IE browsers, but i'm not sorry about 
  $('#pirateship').append('<audio id="bells" src="/sites/all/themes/baddercamp/sounds/bellring.mp3" style="display: none;"></audio>');
  $('#pirateship').bind('click', function() {
    //.play method only words on naked DOM object
    $('#bells')[0].play();
  });
}
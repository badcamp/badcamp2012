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

<?php

/**
 * Change the page title on the user registration form.
 */
function badasstheme_preprocess_page(&$variables) {
  if (arg(0) == 'user' && arg(1) == 'register') {
    $variables['title'] = 'Register for BADCamp 2012!';
  }
}

/**
 * Don't show any text when signups are closed.
 */
function badasstheme_signup_signups_closed($node, $current_signup = '') {
  $output = '';
  return $output;
}


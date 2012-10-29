<?php
/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to baddercamp_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: baddercamp_breadcrumb()
 *
 *   where baddercamp is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


/**
 * Implementation of HOOK_theme().
 */
function baddercamp_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  // Add your theme hooks like this:
  /*
  $hooks['hook_name_here'] = array( // Details go here );
  */
  // @TODO: Needs detailed comments. Patches welcome!
  return $hooks;
}

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function baddercamp_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function baddercamp_preprocess_page(&$vars, $hook) {
  // The magic that makes the login header do its thing.
  global $user;
  if (!$user->uid) {
    $vars['account_links'] = l(t('Log in'), 'user/login', array('attributes' => array('id' => 'magical-login-box-link', 'class' => 'closed-box')));
    $vars['account_information'] = '<h2>' . t('Login to your account') . '</h2>' . '<p>' . t('Returning 2011 attendee? Log in now!') . '</p>' . '<p>' . t('Not registered yet? !registration', array('!registration' => l(t('Sign up!'), 'user/register'))) . '</p>';
    $vars['account_box'] = '<h2>' . t('User Login') . '</h2>' . drupal_get_form('baddercamp_user_login');

    // Capture the messages that come back in a less than idael way
    $vars['messages'] .= theme_status_messages();
  }
  else {
    $vars['account_links'] = l(t('My Profile'), 'user') . ' &middot; ' . l(t('Logout'), 'logout');
    $vars['account_information'] = '';
    $vars['account_box'] = '';
  }

  // Change the page titles on news items.
  if (arg(0) == 'node' && is_numeric(arg(1)) && !arg(2)) {
    $node = node_load(arg(1)); // Free on node page.
    if ($node->type == 'news') {
      // Change the titles.
      $vars['title'] = t('Recent News');
      $vars['head_title'] = t('Recent news') . ': ' . check_plain($node->title);
    }
  }

  // Set the regiser page title to something sane.
  if (arg(0) == 'user' && arg(1) == 'register') {
    $vars['title'] = 'Register for BADCamp 2012!';
  }

//Removing as per Darius's request- mks
// The magic that adds anchors around the page titles.

 /** if ($vars['title'] != '') {
    $vars['title'] = '<span class="anchor anchor-left">&nbsp;</span>' . trim($vars['title']) . '<span class="anchor anchor-right">&nbsp;</span>';
  }
  else {
    $vars['title'] = '<span class="anchor anchor-left">&nbsp;</span>' . t('BADCamp 2012') . '<span class="anchor anchor-right">&nbsp;</span>';
  }
}
**/

/**
 * Super special user login form for BADCamp super login header.
 */
function baddercamp_user_login() {
  $badcamp_user_login = user_login_block();

  // Remove the descriptions
  $badcamp_user_login['name']['#description'] = '';
  $badcamp_user_login['pass']['#description']= '';

  // Switch the titles to placeholders
  $badcamp_user_login['name']['#attributes']['placeholder'] = $badcamp_user_login['name']['#title'] . ' *';
  unset($badcamp_user_login['name']['#title']);
  $badcamp_user_login['pass']['#attributes']['placeholder'] = $badcamp_user_login['pass']['#title'] . ' *';
  unset($badcamp_user_login['pass']['#title']);

  // Change around the submit valiue
  $badcamp_user_login['submit']['#value'] = t('Login');

  // Add the forgot password link and remove old links
  unset($badcamp_user_login['links']);
  $badcamp_user_login['lost_password'] = array(
    '#value' => '<p class="lost-password">' . '( ' . l(t('Lost your password?'), 'user/password') . ' )' . '</p>',
  );

  return $badcamp_user_login;
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function baddercamp_preprocess_node(&$vars, $hook) {
  $node = $vars['node']; // Nice shorthand.
  $vars['comment_count'] = format_plural($node->comment_count, '1 comment', '@count comments');

  /* Optionally, run node-type-specific preprocess functions, like
  // baddercamp_preprocess_node_page() or baddercamp_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars, $hook);
  }
  */
  
  //dpm($vars);
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function baddercamp_preprocess_comment(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function baddercamp_preprocess_block(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Call site-external TypeKit js
 * 
 * see invocation in scripts.js
 *
 **/
drupal_set_html_head('<script type="text/javascript" src="//use.typekit.net/xes0fnw.js"></script>');

// site JS call goes in the footer
drupal_add_js(drupal_get_path('theme', 'baddercamp') .'/js/scripts.js', 'theme', 'footer');

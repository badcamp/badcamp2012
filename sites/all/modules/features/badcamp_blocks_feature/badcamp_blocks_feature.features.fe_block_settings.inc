<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function badcamp_blocks_feature_default_fe_block_settings() {
  $export = array();

  // baddercamp
  $theme = array();

  $theme['block-schedule_of_events'] = array(
    'module' => 'block',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-31',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'schedule_of_events',
  );

  $theme['block-contact'] = array(
    'module' => 'block',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-29',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule
logistics/ride-share*',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'contact',
  );

  $theme['block-hashtags'] = array(
    'module' => 'block',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-25',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule
logistics/ride-share*',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'hashtags',
  );

  $theme['block-scholarship'] = array(
    'module' => 'block',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-27',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'scholarship',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-33',
    'region' => 'navigation',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Small Viewport Menu',
    'cache' => '-1',
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-34',
    'region' => 'navigation',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Large Menu',
    'cache' => '-1',
  );

  $theme['on_the_web-web'] = array(
    'module' => 'on_the_web',
    'delta' => 'web',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-24',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-Sponsors-block_1'] = array(
    'module' => 'views',
    'delta' => 'Sponsors-block_1',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-28',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'sponsors',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-attendees-block_1'] = array(
    'module' => 'views',
    'delta' => 'attendees-block_1',
    'theme' => 'baddercamp',
    'status' => 0,
    'weight' => '-28',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-orders-block_1'] = array(
    'module' => 'views',
    'delta' => 'orders-block_1',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-28',
    'region' => 'content_top',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'sponsors/individual',
    'title' => '',
    'cache' => '-1',
  );

  $export['baddercamp'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}

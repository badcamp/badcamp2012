<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function badcamp_blocks_feature_default_fe_block_settings() {
  $export = array();

  // baddercamp
  $theme = array();

  $theme['badcamp-blimp'] = array(
    'module' => 'badcamp',
    'delta' => 'blimp',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-25',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['dynamic_persistent_menu-0'] = array(
    'module' => 'dynamic_persistent_menu',
    'delta' => '0',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '0',
    'region' => 'navigation',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-25',
    'region' => 'top_navigation',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Small Viewport Menu',
    'cache' => '-1',
  );

  $theme['on_the_web-web'] = array(
    'module' => 'on_the_web',
    'delta' => 'web',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-20',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'sponsors
program/schedule',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-badcamp_sponsors-block_1'] = array(
    'module' => 'views',
    'delta' => 'badcamp_sponsors-block_1',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-25',
    'region' => 'content_bottom',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'sponsors',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-badcamp_sponsors-block_3'] = array(
    'module' => 'views',
    'delta' => 'badcamp_sponsors-block_3',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-25',
    'region' => 'content_bottom',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'sponsors',
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

<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function badcamp_blocks_feature_default_fe_block_settings() {
  $export = array();

  // baddercamp
  $theme = array();

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-27',
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
    'weight' => '-27',
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
    'weight' => '-22',
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
    'weight' => '-27',
    'region' => 'content_bottom',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'sponsors',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-Sponsors-block_3'] = array(
    'module' => 'views',
    'delta' => 'Sponsors-block_3',
    'theme' => 'baddercamp',
    'status' => '1',
    'weight' => '-26',
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

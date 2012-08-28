<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_sponsors_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function cod_sponsors_imagecache_default_presets() {
  $items = array(
    'sponsor_logo_bronze' => array(
      'presetname' => 'sponsor_logo_bronze',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'sponsor_logo_callout' => array(
      'presetname' => 'sponsor_logo_callout',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '195',
            'height' => '118',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_canvas2file',
          'data' => array(
            'xpos' => 'center',
            'ypos' => 'center',
            'alpha' => '100',
            'path' => 'sites/all/themes/badasstheme/img/bg-white.png',
            'dimensions' => 'background',
          ),
        ),
        '2' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '200',
            'height' => '120',
            'xoffset' => 'center',
            'yoffset' => 'center',
          ),
        ),
      ),
    ),
    'sponsor_logo_gold' => array(
      'presetname' => 'sponsor_logo_gold',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '215',
            'height' => '134',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_canvas2file',
          'data' => array(
            'xpos' => 'center',
            'ypos' => 'center',
            'alpha' => '100',
            'path' => 'sites/all/themes/badasstheme/img/bg-white.png',
            'dimensions' => 'background',
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '220',
            'height' => '137',
            'xoffset' => 'center',
            'yoffset' => 'center',
          ),
        ),
      ),
    ),
    'sponsor_logo_platinum' => array(
      'presetname' => 'sponsor_logo_platinum',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '295',
            'height' => '174',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_canvas2file',
          'data' => array(
            'xpos' => 'center',
            'ypos' => 'center',
            'alpha' => '100',
            'path' => 'sites/all/themes/badasstheme/img/bg-white.png',
            'dimensions' => 'background',
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '300',
            'height' => '180',
            'xoffset' => 'center',
            'yoffset' => 'center',
          ),
        ),
      ),
    ),
    'sponsor_logo_silver' => array(
      'presetname' => 'sponsor_logo_silver',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '135',
            'height' => '85',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_canvas2file',
          'data' => array(
            'xpos' => 'center',
            'ypos' => 'center',
            'alpha' => '100',
            'path' => 'sites/all/themes/badasstheme/img/bg-white.png',
            'dimensions' => 'background',
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '140',
            'height' => '87',
            'xoffset' => 'center',
            'yoffset' => 'center',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function cod_sponsors_node_info() {
  $items = array(
    'sponsor' => array(
      'name' => t('Sponsor'),
      'module' => 'features',
      'description' => t('An event sponsor'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cod_sponsors_views_api() {
  return array(
    'api' => '2',
  );
}

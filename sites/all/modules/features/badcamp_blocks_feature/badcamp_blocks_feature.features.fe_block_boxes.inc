<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function badcamp_blocks_feature_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'contact';
  $fe_block_boxes->body = NULL;

  $export['contact'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'hashtags';
  $fe_block_boxes->body = NULL;

  $export['hashtags'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'schedule_of_events';
  $fe_block_boxes->body = NULL;

  $export['schedule_of_events'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'scholarship';
  $fe_block_boxes->body = NULL;

  $export['scholarship'] = $fe_block_boxes;

  return $export;
}

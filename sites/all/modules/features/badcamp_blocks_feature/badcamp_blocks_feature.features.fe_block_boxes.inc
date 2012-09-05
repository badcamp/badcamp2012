<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function badcamp_blocks_feature_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Contact';
  $fe_block_boxes->format = '1';
  $fe_block_boxes->machine_name = 'contact';
  $fe_block_boxes->body = 'If you have questions regarding BADCamp or would like to become a sponsor please <a href="/contact">contact us</a>.

';

  $export['contact'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Hashtags';
  $fe_block_boxes->format = '1';
  $fe_block_boxes->machine_name = 'hashtags';
  $fe_block_boxes->body = 'IRC: #drupal-bayarea

Flickr: #badcamp #badcamp2012';

  $export['hashtags'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Schedule of events';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'schedule_of_events';
  $fe_block_boxes->body = '<h4>Thursday, November 1st</h4>
<a href="/program/training">Free Drupal Training</a><br />
<a href="/program/non-profit-summit">Non-Profit Summit</a><br />
<a href="/program/ui-ux-summit">Drupal UI/UX Summit</a><br />
<a href="/program/drupal-devops-summit">Drupal DevOps Summit</a><br />
<a href="/program/drupal-business-summit">Drupal Business Summit</a><br />


<h4>Friday, November 2nd</h4>
<a href="/program/free-drupal-training">Free Drupal Training</a><br />
<a href="/program/mobile-summit">Mobile Drupal Summit</a><br />
<a href="/program/core-developer-summit">Core Developer Summit</a><br />
<a href="/program/mobile-summit">Mobile Drupal Summit</a><br />
<a href="/program/higher-education-summit">Higher Education Summit</a><br />
<a href="/program/product-summit">Drupal Product Summit</a><br />

<h4>Saturday, November 3rd</h4>
Sessions<br />
Job Fair<br />
BoFs<br />

<h4>Sunday, November 4th</h4>
Sessions<br />
BoFs<br />
<br />
...and so much more!<br />';

  $export['schedule_of_events'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Scholarship';
  $fe_block_boxes->format = '1';
  $fe_block_boxes->machine_name = 'scholarship';
  $fe_block_boxes->body = 'BADCamp has a scholarship program to help deserving individuals make the journey. <a href="/scholarship-program">Apply today</a>!';

  $export['scholarship'] = $fe_block_boxes;

  return $export;
}

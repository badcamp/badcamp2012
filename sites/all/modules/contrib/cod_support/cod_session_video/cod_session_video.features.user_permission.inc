<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_session_video_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_video
  $permissions['edit field_video'] = array(
    'name' => 'edit field_video',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'editor',
      '3' => 'video editor',
    ),
  );

  // Exported permission: view field_video
  $permissions['view field_video'] = array(
    'name' => 'view field_video',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'video editor',
    ),
  );

  return $permissions;
}

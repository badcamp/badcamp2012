<?php
// $Id: profile_fields_pane.tpl.php,v 1.1 2009/04/18 02:00:35 merlinofchaos Exp $
/**
 * @file
 * Display profile fields.
 *
 * @todo Need definition of what variables are available here.
 */
?>
<?php if (is_array($vars)): ?>
  <?php  foreach ($vars as $class => $field): ?>
    <div class="profile-<?php print $class; ?>"><?php print $field['value']; ?></div>
  <?php endforeach; ?>
<?php endif; ?>

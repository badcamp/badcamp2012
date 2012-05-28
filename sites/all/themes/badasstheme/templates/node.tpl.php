<?php // $Id: node.tpl.php,v 1.1.2.3.2.2.2.6 2010/03/01 13:37:46 psynaptic Exp $ ?>
<?php print $pre; ?>

<div <?php print drupal_attributes($attr); ?>>

  <?php if (!$page && $title && ($node->nid != 3)): ?>
    <h2 class='node-title'>
      <?php print $title; ?>
    </h2>
  <?php endif; ?>

  <div class="node-content clear-block">
    <?php print $content; ?>
    <?php if ($submitted): ?>
      <div class='node-submitted clear-block'>
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>
  </div>
  
  <?php if ($links): ?>
    <div class="node-links clear-block"><?php print $links; ?></div>
  <?php endif; ?>

</div>

<?php print $post; ?>

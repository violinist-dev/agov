<?php
/**
 * @file
 * agov_faq.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agov_faq_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create faq_question content'.
  $permissions['create faq_question content'] = array(
    'name' => 'create faq_question content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any faq_question content'.
  $permissions['edit any faq_question content'] = array(
    'name' => 'edit any faq_question content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}

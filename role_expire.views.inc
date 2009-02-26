<?php 
// $Id$

/**
 * @file
 * Role Expire Views hooks
 *
 * Hooks for integrating Role Expire with Views
 */


function role_expire_views_data() {
  // Get all roles
  $roles = user_roles(true);
  unset($roles[DRUPAL_AUTHENTICATED_RID]);  
      	
  // Prepare views structures
  foreach ($roles as $rid => $role) {
	$data['role_expire_'. $rid]['table']['group']  = t('User');
	  
	$data['role_expire_'. $rid]['table']['join'] = array(
	  'users' => array(
	    'left_field' => 'uid',
	    'field' => 'uid',
	  ),
	  'node' => array(
	    'left_field' => 'uid',
	    'field' => 'uid',
	  ),
	  'node_revisions' => array(
	    'left_table' => 'node',
	    'left_field' => 'uid',
	    'field' => 'uid',
	  ),
	);
	  
	$data['role_expire_'. $rid]['expiry_timestamp'] = array(
	  'title' => $role ." ". t('role expiry time'), 
	  'help' => t('Time and date the role will expire.'), 
	  'field' => array(
	    'handler' => 'views_handler_field_date',
	    'click sortable' => TRUE,
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort_date',
	  ),
	  'filter' => array(
	    'handler' => 'views_handler_filter_date',
	  ),
    );    
  }
  
  return $data;
}
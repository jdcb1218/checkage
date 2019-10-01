<?php

/**
 * @file
 * checkage module.
 */

/**
 * Implements hook_form().
 */
function checkage_form($node, &$form_state) {

	$form = array();
	
	$form['checkage'] = array(
	    '#type' => 'fieldset',
	    '#title' => t('Date of birth'),
	);

	$form['checkage']['date'] = array(
	  '#type' => 'date', 
	 // '#default_value' => $edit[$field->name], 
	  '#required' => TRUE
	);

	$form['checkage']['remember'] = array(
	  '#type' =>'checkbox', 
	  '#title' => t('Remember me'),
	);	

	$form['checkage']['info'] = array(
	  '#type' => 'item',
	  '#markup' => t('Do not say connect is of computer is shared witchof 18'),
	  '#prefix' => '<div id="result_places_polices_div">',
      '#suffix' => '</div>',
	);

   return $form;
}
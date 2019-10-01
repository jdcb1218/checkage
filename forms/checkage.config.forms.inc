<?php

/**
 * Implements hook_form().
 */

function checkage_config($form, $form_state, $no_js_use = FALSE) {

 	$form = array();
    $form['#tree'] = TRUE;
    $form['#attributes']['enctype'] = 'multipart/form-data';

    $form['config_views'] = array(
        '#type' => 'fieldset',
        '#title' => t('Please Add Urls'),
        "#prefix" => '<div id="form-config_views">',
        "#suffix" => '</div>',
        '#collapsible' => FALSE,
    );

    $form['config_views']['entry_fieldset'] = array(
        '#type' => 'fieldset',
        '#title' => t('List Urls'),
        '#prefix' => '<div id="entry-fieldset-wrapper">',
        '#suffix' => '</div>',
    );

    if (empty($form_state['pnum_names'])) {
        $form_state['pnum_names'] = 1;
    }

    for ($i = 0; $i < $form_state['pnum_names']; $i++) {
        $form['config_views']['entry_fieldset']['urls'][$i] = array(
            '#type' => 'textfield',
            '#title' => '',
            '#size' => 22,
            '#description' => t('Example : node/' . $i),
            '#attributes' => array('multiple' => 'multiple'),
        );
    }
    $form['config_views']['entry_fieldset']['add_url_name'] = array(
        '#type' => 'submit',
        '#value' => t('Add more url'),
        '#submit' => array('urls_add_more_add_one'),
        '#ajax' => array(
            'callback' => 'urls_add_more_callback',
            'wrapper' => 'entry-fieldset-wrapper',
        ),
    );

    if (empty($form_state['num_names'])) {
        $form_state['num_names'] = 1;
    }

  	$form['config_views']['submit'] = array(
       '#type' => 'submit',
       '#value' => t('Submit'),
  	);

    return $form;
}


function urls_add_more_add_one($form, &$form_state) {

    if (!isset($form_state['pnum_names'])) {
        $form_state['pnum_names'] = 0;
        $form_state['pnum_names']++;
    }

    $form_state['pnum_names']++; 
    $form_state['rebuild'] = TRUE;
}

function urls_add_more_callback($form, $form_state) {
    return $form['config_views']['entry_fieldset'];
}
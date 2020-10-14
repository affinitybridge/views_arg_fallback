<?php

/**
 * @file
 * Provide views data and handlers for views_arg_fallback.module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_arg_fallback_views_plugins() {
  return array(
    'module' => 'views_arg_fallback',
    'argument default' => array(
      'node_referer' => array(
        'title' => t('Content ID from URL, with Referer fallback'),
        'handler' => 'views_plugin_argument_default_node_referer'
      ),
    ),
  );
}

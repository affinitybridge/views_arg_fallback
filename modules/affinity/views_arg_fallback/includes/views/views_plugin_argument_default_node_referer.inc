<?php

/**
 * @file
 * Contains the node from URL with referer fallback argument default plugin.
 */

/**
 * Default argument plugin to extract a node via URL with referer fallback
 *
 * This plugin actually has no options so it does not need to do a great deal.
 */
class views_plugin_argument_default_node_referer extends views_plugin_argument_default_node {
  function get_argument() {
    // Get Content ID from URL if available
    if ($nid = parent::get_argument()) {
      return $nid;
    }

    if ($path = _views_arg_fallback_referer_path($_SERVER['HTTP_REFERER'])) {
      foreach (range(1, 3) as $i) {
        $node = menu_get_object('node', $i, $path);
        if (!empty($node)) {
          return $node->nid;
        }
      }
      $path_parts = explode('/', $path);
      if ($path_parts[0] == 'node' && is_numeric($path_parts[1])) {
        return $path_parts[1];
      }      
    }
  }
}

<?php
// $Id$
/**
 * @file
 * Provide views data and handlers for twitter.module
 */

/**
 * @defgroup views_twitter_module twitter.module handlers
 *
 * Includes the ability to create views of just the twitter table.
 * @{
 */

/**
 * Implementation of hook_views_data()
 */
function twitter_views_data() {
  // Basic table information.

  $data['twitter']['table']['group']  = t('Twitter');

  // Advertise this table as a possible base table
  $data['twitter']['table']['base'] = array(
    'field' => 'twitter_id',
    'title' => t('Twitter message'),
    'help' => t('Stores Twitter status messages.'),
    'weight' => 10,
  );

  // Twitter screen name
  $data['twitter']['screen_name'] = array(
    'title' => t('Login name'),
    'help' => t('The login account of the Twitter user.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Twitter message timestamp
  $data['twitter']['created_time'] = array(
    'title' => t('Created time'),
    'help' => t('The time the Twitter message was posted.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Twitter text
  $data['twitter']['text'] = array(
    'title' => t('Message text'),
    'help' => t('The text of the Twitter message.'),
    'field' => array(
      'handler' => 'twitter_views_handler_field_xss',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // Twitter source
  $data['twitter']['source'] = array(
    'title' => t('Source'),
    'help' => t('The name of the application that posted the Twitter message.'),
    'field' => array(
      'handler' => 'views_handler_field_xss',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );




  $data['twitter_account']['table']['group']  = t('Twitter');

  $data['twitter_account']['table']['join'] = array(
    'twitter' => array(
      'left_field' => 'screen_name',
      'field' => 'screen_name',
    ),
    'users' => array(
      'field' => 'screen_name',
      'left_table' => 'twitter_user',
      'left_field' => 'screen_name',
    ),
  );

  // Twitter screen name
  $data['twitter_account']['screen_name'] = array(
    'title' => t('Login name'),
    'help' => t('The login account of the Twitter user.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );


  // Twitter account full name
  $data['twitter_account']['name'] = array(
    'title' => t('Full name'),
    'help' => t('The full name Twitter account user.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Twitter account description
  $data['twitter_account']['description'] = array(
    'title' => t('Description'),
    'help' => t('The description of the Twitter account.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_field_xss',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Twitter account location
  $data['twitter_account']['location'] = array(
    'title' => t('Location'),
    'help' => t('The location of the Twitter account.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_field_xss',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Twitter account description
  $data['twitter_account']['followers_count'] = array(
    'title' => t('Location'),
    'help' => t('The number of users following this Twitter account.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Twitter account profile image
  $data['twitter_account']['profile_image_url'] = array(
    'title' => t('Profile image'),
    'help' => t('The image used by the Twitter account.'),
    'field' => array(
      'handler' => 'twitter_views_handler_profile_image',
      'click sortable' => TRUE,
    ),
  );

  // Twitter account url
  $data['twitter_account']['url'] = array(
    'title' => t('URL'),
    'help' => t('The URL given by the Twitter account user.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Twitter account protected
  $data['twitter_account']['protected'] = array(
    'title' => t('Protected status'),
    'help' => t('Whether posts from this Twitter account should be visible to the general public.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Twitter message timestamp
  $data['twitter_account']['last_refresh'] = array(
    'title' => t('Last refresh'),
    'help' => t('The time the Twitter account statuses were retrieved.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );


  $data['twitter_user']['table']['group']  = t('Twitter');

  $data['twitter_user']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'twitter_account' => array(
      'left_field' => 'screen_name',
      'field' => 'screen_name',
    ),
    'twitter' => array(
      'left_table' => 'twitter_account',
      'left_field' => 'screen_name',
      'field' => 'screen_name',
    ),
  );

  // Twitter account description
  $data['twitter_user']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('The UID of the Twitter account.'),
  );

  // Twitter account description
  $data['twitter_user']['screen_name'] = array(
    'title' => t('Screen name'),
    'help' => t('The screen name of the Twitter account.'),
  );

  // Twitter account protected
  $data['twitter_user']['import'] = array(
    'title' => t('Import status'),
    'help' => t('Whether posts from this Twitter account should be imported automatically.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );


  return $data;
}


function twitter_views_data_alter(&$data) {
  $data['users']['table']['join']['twitter'] = array(
    'left_table' => 'twitter_user',
    'left_field' => 'uid',
    'field' => 'uid',
  );
  $data['users']['table']['join']['twitter_account'] = array(
    'left_table' => 'twitter_user',
    'left_field' => 'uid',
    'field' => 'uid',
  );
  $data['users']['table']['join']['twitter_user'] = array(
    'left_field' => 'uid',
    'field' => 'uid',
  );
}


/**
 * Field handler to provide simple renderer that turns a URL into a clickable link.
 */
class twitter_views_handler_profile_image extends views_handler_field {
  function render($values) {
    $value = $values->{$this->field_alias};
    return theme('image', $value, '', '', array(), FALSE);
  }
}


/**
 * Process Twitter-style @usernames and URLs before filtering XSS.
 */
class twitter_views_handler_field_xss extends views_handler_field {
  function render($values) {
    $value = $values->{$this->field_alias};
    $value = _filter_url($value, FILTER_DEFAULT);
    $value = preg_replace(
      array('/^@([a-z0-9_]{0,15})/i', '/(\s+)@([a-z0-9_]{0,15})/i'),
      array('<a href="http://twitter.com/${1}">@${1}</a>', '${1}@<a href="http://twitter.com/${2}">${2}</a>'),
      $value); 
    return filter_xss($value);
  }
}

/**
 * @}
 */
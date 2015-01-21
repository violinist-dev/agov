<?php

/**
 * @file
 * Contains SearchApiFunnelbackService.
 */

/**
 * Searches items using the Funnelback.
 */
abstract class SearchApiFunnelbackService extends SearchApiAbstractService {

//  /**
//   * Multiplier for scores to have precision when converted from float to int.
//   */
//  const SCORE_MULTIPLIER = 1000;

  /**
   * URL of the Funnelback service.
   *
   * @var string
   */
  protected $url;

  /**
   * The keywords ignored during the current search query.
   *
   * @var array
   */
  protected $ignored = array();

  /**
   * All warnings for the current search query.
   *
   * @var array
   */
  protected $warnings = array();

  /**
   * {@inheritdoc}
   */
  public function __construct(SearchApiServer $server) {
    parent::__construct($server);
    if (isset($this->options['url'])) {
      $this->url = $this->options['url'];
    }
  }

  /**
   * {@inheritdoc}
   */
  public function configurationForm(array $form, array &$form_state) {
    $form['url'] = array(
      '#type' => 'textfield',
      '#title' => t('Funnelback service URL'),
      '#description' => t('The base URL of the Funnelback service.'),
      '#default_value' => empty($this->options['url']) ? NULL : $this->options['url'],
      '#required' => TRUE,
    );

//    $form['collection'] = array(
//      '#type' => 'textfield',
//      '#title' => t('Funnelback collection name'),
//      '#description' => t('The name of the Funnelback collection to be used.'),
//      '#default_value' => empty($this->options['collection']) ? NULL : $this->options['collection'],
//      '#required' => TRUE,
//    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function supportsFeature($feature) {
    $supported = array(
      'search_api_autocomplete' => FALSE,
      'search_api_facets' => FALSE,
      'search_api_facets_operator_or' => FALSE,
      'search_api_service_extra' => FALSE,
    );
    return isset($supported[$feature]);
  }

  /**
   * {@inheritdoc}
   */
  public function postUpdate() {
    // TODO clear request cache.
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function preDelete() {
    // TODO clear request cache.
  }

  /**
   * {@inheritdoc}
   */
  public function addIndex(SearchApiIndex $index) {
    if (!isset($this->options['indexes'][$index->machine_name])) {
      $this->options['indexes'][$index->machine_name] = array();
      $this->server->save();
    }
    elseif ($this->options['indexes'][$index->machine_name]) {
      $this->removeIndex($index);
      $this->options['indexes'][$index->machine_name] = array();
      $this->server->save();
    }
    // TODO clear request cache.
    return;
  }

  /**
   * {@inheritdoc}
   */
  public function removeIndex($index) {
    $id = is_object($index) ? $index->machine_name : $index;
    if (!isset($this->options['indexes'][$id])) {
      return;
    }
    unset($this->options['indexes'][$id]);
    $this->server->save();
    // TODO clear request cache.
    return;
  }

//  /**
//   * {@inheritdoc}
//   */
//  public function indexItems(SearchApiIndex $index, array $items) {
//  shouldn't be needed
//  }

//  /**
//   * {@inheritdoc}
//   */
//  public function deleteItems($ids = 'all', SearchApiIndex $index = NULL) {
//  shouldn't be needed
//  }

  /**
   * {@inheritdoc}
   */
  public function search(SearchApiQueryInterface $query) {
    $time_method_called = microtime(TRUE);
    $this->ignored = $this->warnings = array();
    $index = $query->getIndex();
    if (empty($this->options['indexes'][$index->machine_name])) {
      throw new SearchApiException(t('Unknown index @id.', array('@id' => $index->machine_name)));
    }
    $fields = $this->getFieldInfo($index);

    $db_query = $this->createDbQuery($query, $fields);

    // Allow subclasses and other modules to alter the query (before a count
    // query is constructed from it).
    drupal_alter('search_api_db_query', $db_query, $query);

    $time_processing_done = microtime(TRUE);
    $results = array();

    $skip_count = $query->getOption('skip result count');
    if (!$skip_count) {
      $count_query = $db_query->countQuery();
      $results['result count'] = $count_query->execute()->fetchField();
    }

    if ($skip_count || $results['result count']) {
      if ($query->getOption('search_api_facets')) {
        $results['search_api_facets'] = $this->getFacets($query, clone $db_query);
      }

      $query_options = $query->getOptions();
      if (isset($query_options['offset']) || isset($query_options['limit'])) {
        $offset = isset($query_options['offset']) ? $query_options['offset'] : 0;
        $limit = isset($query_options['limit']) ? $query_options['limit'] : 1000000;
        $db_query->range($offset, $limit);
      }

      $this->setQuerySort($query, $db_query, $fields);

      $result = $db_query->execute();
      $time_queries_done = microtime(TRUE);

      foreach ($result as $row) {
        $results['results'][$row->item_id] = array(
          'id' => $row->item_id,
          'score' => $row->score / self::SCORE_MULTIPLIER,
        );
      }
      if ($skip_count) {
        $results['result count'] = !empty($results['results']);
      }
    }
    else {
      $time_queries_done = microtime(TRUE);
      $results['results'] = array();
    }

    $results['warnings'] = array_keys($this->warnings);
    $results['ignored'] = array_keys($this->ignored);

    $this->postQuery($results, $query);

    $time_end = microtime(TRUE);
    $results['performance'] = array(
      'complete' => $time_end - $time_method_called,
      'preprocessing' => $time_processing_done - $time_method_called,
      'execution' => $time_queries_done - $time_processing_done,
      'postprocessing' => $time_end - $time_queries_done,
    );

    return $results;
  }

}

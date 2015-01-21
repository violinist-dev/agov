<?php

/**
 * @file
 */


namespace Funnelback;

/**
 * Funnelback client.
 */
class Client implements ClientInterface {

  /**
   * The http result object.
   *
   * @var stdClass
   */
  protected $httpResult;

  /**
   * The base url.
   *
   * @var string
   */
  protected $baseUrl;

  /**
   * The response format.
   *
   * Valid values are XML, JSON, and HTML.
   *
   * @var string
   *  The response format.
   */
  protected $format;

  /**
   * The search collection.
   *
   * @var string
   */
  protected $collection;

  /**
   * Creates a new Funnelback client.
   *
   * @param array $config
   *   The funnelback config.
   */
  public function __construct(array $config) {
    $this->baseUrl = $config['base_url'];
    $this->subPath = isset($config['sub_path']) ? $config['sub_path'] : '';
    $format = isset($config['format']) ? $config['format'] : self::JSON_FORMAT;
    $this->setFormat($format);
    $this->collection = $config['collection'];
    $this->client = NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function getBaseUrl() {
    return $this->baseUrl;
  }

  /**
   * {@inheritdoc}
   */
  public function getSubPath() {
    return $this->subPath;
  }

  /**
   * {@inheritdoc}
   */
  public function getCollection() {
    return $this->collection;
  }

  /**
   * Set the format to use.
   *
   * @param string $format
   *   The format.
   */
  protected function setFormat($format) {
    $format = trim(strtolower($format));
    if (!$this->isValidFormat($format)) {
      throw new \InvalidArgumentException(sprintf('Invalid format: %s. Allowed formats are %s',
        $format,
        implode(',', $this->allowedFormats())
      ));
    }
    $this->format = $format;
  }

  /**
   * {@inheritdoc}
   */
  public function getFormat() {
    return $this->format;
  }

  /**
   * {@inheritdoc}
   */
  public function allowedFormats() {
    return [
      $this::XML_FORMAT,
      $this::JSON_FORMAT,
      $this::HTML_FORMAT,
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function search($query, $params = []) {
    $params = array_merge(['collection' => $this->collection], $params);
    $params = array_merge(['query' => $query], $params);

    $url_query = drupal_http_build_query($params);
    $url = $this->getBaseUrl() . '/s/search.' . $this->getFormat() . '?' . $url_query;

    $this->httpResult = drupal_http_request($url);

    return new Response($this->httpResult);
  }

  /**
   * Checks if the format is allowed.
   *
   * @param string $format
   *   The response format.
   *
   * @return bool
   *   TRUE if the format is allowed.
   */
  protected function isValidFormat($format) {
    return in_array($format, $this->allowedFormats());
  }
}

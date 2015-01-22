Feature: 403 to 404

  Prevent disclosure of access denied pages by returning a Not Found (404) response

  Scenario: Access a protected page
    When I visit "/admin"
    Then the response status code should be 404

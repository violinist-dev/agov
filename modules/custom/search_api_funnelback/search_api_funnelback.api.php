<?php

/**
 * @file
 * Hooks provided by the Funnelback Search module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Preprocesses a search's funnelback query before it is executed.
 *
 * @param SelectQueryInterface $db_query
 *   The funnelback query to be executed for the search. Will have "item_id" and
 *   "score" columns in its result.
 * @param SearchApiQueryInterface $query
 *   The search query that is being executed.
 *
 * @see SearchApiDbService::preQuery()
 */
function hook_search_api_funnelback_query_alter(SelectQueryInterface &$db_query, SearchApiQueryInterface $query) {
}

/**
 * @} End of "addtogroup hooks".
 */

/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../smart_calc.h"

/// @brief
/// @param s_phead
/// @param q_phead
/// @return
int end_of_expression_processing(node_t** s_phead, node_t** q_phead) {
  int error = OK;
  while (*s_phead != NULL && !error) {
    if ((*s_phead)->token_type == OPEN_BRACKET) {
      error = UNBALANCED_BRACKETS;
    } else {
      move_node_from_stack_to_queue(s_phead, q_phead);
    }
  }
  return error;
}

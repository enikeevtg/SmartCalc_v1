/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../smart_calc.h"

/// @brief
/// @param address_ptr
/// @param current_str
/// @param s_phead
/// @param q_phead
/// @param pcontainer
/// @return
int token_processing(int* address_ptr, char** current_str, node_t** s_phead,
                     node_t** q_phead, node_t* pcontainer) {
  int error = OK;

  error = container_packing(*address_ptr, current_str, s_phead, pcontainer);
  if (error == OK) {
    error = container_sending(address_ptr, s_phead, q_phead, pcontainer);
  }
  return error;
}

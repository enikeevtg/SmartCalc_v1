/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../smart_calc.h"

/// @brief
/// @param prev_address
/// @param s_phead
/// @param pcontainer
void create_mult(int prev_address, node_t** s_phead, node_t* pcontainer) {
  char* mult_char_str = "*";
  operator_packer(prev_address, s_phead, &mult_char_str, pcontainer);
}

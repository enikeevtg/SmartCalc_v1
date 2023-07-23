#include "tests.h"

START_TEST(close_bracket_error_EMPTY_BRACKETS) {
  // Arrange
  int address = STACK;
  node_t* s_head = NULL;
  node_t s_node = {NULL, OPEN_BRACKET, PRIOR_1, 0.0};
  push(address, &s_head, &s_node);

  node_t* q_root = NULL;

  // Act
  int error_code = close_bracket_processing(address, &s_head, &q_root);

  // Assert
  ck_assert_int_eq(error_code, EMPTY_BRACKETS);
  ck_assert_ptr_eq(q_root, NULL);

  remove_struct(&s_head);
}
END_TEST

START_TEST(close_bracket_error_INCORRECT_INPUT) {
  // Arrange
  int address = STACK;
  node_t* s_head = NULL;
  node_t s_node = {NULL, POW, PRIOR_6, 0.0};
  push(address, &s_head, &s_node);

  node_t* q_root = NULL;

  // Act
  int error_code = close_bracket_processing(address, &s_head, &q_root);

  // Assert
  ck_assert_int_eq(error_code, INCORRECT_INPUT);
  ck_assert_ptr_eq(q_root, NULL);

  remove_struct(&s_head);
}
END_TEST

START_TEST(close_bracket_error_UNBALANCED_BRACKETS) {
  // Arrange
  //         |                |           |--------|-----
  // STACK:  |                |   QUEUE:  | NUMBER | ->
  //         |______PLUS______|           |--------|-----

  int address = QUEUE;
  node_t* s_head = NULL;
  node_t s_node = {NULL, PLUS, PRIOR_1, 0.0};
  push(STACK, &s_head, &s_node);

  node_t q_root_node = {NULL, NUMBER, PRIOR_1, 3.1415};
  node_t* q_root = NULL;
  push(QUEUE, &q_root, &q_root_node);
  node_t* q_head = q_root;

  // Act
  int error_code = close_bracket_processing(address, &s_head, &q_head);

  // Assert
  ck_assert_int_eq(error_code, UNBALANCED_BRACKETS);

  remove_struct(&q_root);
}
END_TEST


START_TEST(close_bracket_processing_1) {
  // Arrange
  //         |      PLUS      |           |--------|-----
  // STACK:  |       \|/      |   QUEUE:  | NUMBER | ->
  //         |__OPEN_BRACKET__|           |--------|-----

  int address = QUEUE;
  node_t* s_head = NULL;
  node_t s_node_1 = {NULL, OPEN_BRACKET, PRIOR_1, 0.0};
  node_t s_node_2 = {NULL, PLUS, PRIOR_2, 0.0};
  push(STACK, &s_head, &s_node_1);
  push(STACK, &s_head, &s_node_2);

  node_t q_root_node = {NULL, NUMBER, PRIOR_1, 3.1415};
  node_t* q_root = NULL;
  push(address, &q_root, &q_root_node);
  node_t* q_head = q_root;

  // Act
  int error_code = close_bracket_processing(address, &s_head, &q_head);
  node_t q_node_1 = {0};
  node_t q_node_2 = {0};
  pop(&q_root, &q_node_1);
  pop(&q_root, &q_node_2);

  // Assert
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(q_node_1.token_type, NUMBER);
  ck_assert_int_eq(q_node_2.token_type, PLUS);
}
END_TEST

Suite* test_close_bracket_processing(void) {
  Suite* s = suite_create("close_bracket_processing function tests suite");

  TCase* close_bracket_errors_tc =
      tcase_create("close_bracket_processing errors");
  tcase_add_test(close_bracket_errors_tc, close_bracket_error_EMPTY_BRACKETS);
  tcase_add_test(close_bracket_errors_tc, close_bracket_error_INCORRECT_INPUT);
  tcase_add_test(close_bracket_errors_tc, close_bracket_error_UNBALANCED_BRACKETS);
  suite_add_tcase(s, close_bracket_errors_tc);

  TCase* close_bracket_tc = tcase_create("close_bracket_processing");
  tcase_add_test(close_bracket_tc, close_bracket_processing_1);
  suite_add_tcase(s, close_bracket_tc);

  return s;
}

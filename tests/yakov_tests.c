#include "tests.h"

START_TEST(test_smart_calc_1) {
  char input[255] = "3+4*2/(1-5)^(2-1+1)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);

  ck_assert_double_eq(result, 3.5);
}
END_TEST

START_TEST(test_smart_calc_2) {
  char input[255] = "1+2+3+4*5*6^7";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq((int)result, 5598726);
}
END_TEST

START_TEST(test_smart_calc_3) {
  char input[255] = "123.456+2*3^4";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq(result, 285.456);
}
END_TEST

START_TEST(test_smart_calc_4) {
  char input[255] = "(8+2*5)/(1+3*2-4)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq(result, 6);
}
END_TEST

START_TEST(test_smart_calc_5) {
  char input[255] =
      "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq(result, 10);
}
END_TEST

START_TEST(test_smart_calc_6) {
  char input[255] = "cos(1*2)-1";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, -1.41614683655, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_7) {
  char input[255] =
      "cos(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/"
      "2)))-1";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, -1.83907152908, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_8) {
  char input[255] = "sin(2)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 0.909297, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_9) {
  char input[255] = "2%2";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq(result, 0);
}
END_TEST

START_TEST(test_smart_calc_10) {
  char input[255] = "3+4*2/1-5+2^2";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 10, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_11) {
  char input[255] = "3+4*2/1-5+2^2";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 10, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_12) {
  char input[255] = "asin(2*x)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0.0003;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 0.0006, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_13) {
  char input[255] = "acos(2*x)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0.0019;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 1.567, 1e-03);
}
END_TEST

START_TEST(test_smart_calc_14) {
  char input[255] = "atan(2*x)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0.0019;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 0.00379998, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_15) {
  char input[255] = "tan(2*x)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0.004;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 0.00800017, 1e-06);
}
END_TEST

START_TEST(test_smart_calc_16) {
  char input[255] = "sqrt(2*x)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 25;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq_tol(result, 7.07107, 1e-05);
}
END_TEST

START_TEST(test_smart_calc_17) {
  char input[255] = "2.3+5.5";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_double_eq(result, 7.8);
}
END_TEST

START_TEST(test_smart_calc_18) {
  char input[255] = "-(-3+2)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq((int)result, 1);
}
END_TEST

START_TEST(test_smart_calc_19) {
  char input[255] = "(-2-3+1)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq((int)result, -4);
}
END_TEST

START_TEST(test_smart_calc_20) {
  char input[255] = "(+2-6)+(-4-10)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq((int)result, -18);
}

START_TEST(test_smart_calc_21) {
  char input[255] = "-2-3+1";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq((int)result, -4);
}
END_TEST

START_TEST(test_smart_calc_22) {
  char input[255] = "5%3";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(test_smart_calc_23) {
  char input[255] = "(132+sin(asin(sqrt(ln(log(228.11)))))-4*5^6*(123))";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(result, -7687367.073);
}
END_TEST

START_TEST(test_smart_calc_24) {
  char input[255] =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(result, -30.07);
}
END_TEST

START_TEST(test_smart_calc_25) {
  char input[255] = "sin(-1)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(result, 0.84);
}
END_TEST

START_TEST(test_smart_calc_26) {
  char input[255] = "(/)3";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  int error = convert_infix_to_RPN(input, &q_root);
  if (!error) error = evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(error, INCORRECT_INPUT);
}
END_TEST

START_TEST(test_smart_calc_27) {
  char input[255] = "3%";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  int error = convert_infix_to_RPN(input, &q_root);
  if (!error) error = evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(error, INCORRECT_INPUT);
}
END_TEST

START_TEST(test_smart_calc_28) {
  char input[255] = "(/3)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  int error = convert_infix_to_RPN(input, &q_root);
  if (!error) error = evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(error, INCORRECT_INPUT);
}
END_TEST

START_TEST(test_smart_calc_29) {
  char input[255] = "((-2-3+x))";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 2;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq((int)result, -3);
}
END_TEST

START_TEST(test_smart_calc_30) {
  char input[255] = "((-2-3+X))";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  int error = convert_infix_to_RPN(input, &q_root);
  if (!error) error = evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(error, UNDEFINED_TOKEN);
}
END_TEST

START_TEST(test_smart_calc_31) {
  char input[255] = "((-2-3+x)*3)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  int error = convert_infix_to_RPN(input, &q_root);
  if (!error) error = evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_smart_calc_32) {
  char input[255] = "4((-2+x))3)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  int error = convert_infix_to_RPN(input, &q_root);
  if (!error) error = evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(error, UNBALANCED_BRACKETS);
}
END_TEST

START_TEST(test_smart_calc_33) {
  char input[255] = "4((-3++x)2)";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  int error = convert_infix_to_RPN(input, &q_root);
  if (!error) error = evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq(error, INCORRECT_INPUT);
}
END_TEST

START_TEST(test_smart_calc_34) {
  char input[255] = "2^2^3";
  node_t* q_root = NULL;
  double result = 0;
  double variable = 0;

  convert_infix_to_RPN(input, &q_root);
  evaluate_expression(q_root, variable, &result);
  ck_assert_int_eq((int)result, 256);
}
END_TEST

Suite* yakov_tests() {
  Suite* s = suite_create("yakov tests ");

  TCase* tc1_1 = tcase_create("all test cases ");
  tcase_add_test(tc1_1, test_smart_calc_1);
  tcase_add_test(tc1_1, test_smart_calc_2);
  tcase_add_test(tc1_1, test_smart_calc_3);
  tcase_add_test(tc1_1, test_smart_calc_4);
  tcase_add_test(tc1_1, test_smart_calc_5);
  tcase_add_test(tc1_1, test_smart_calc_6);
  tcase_add_test(tc1_1, test_smart_calc_7);
  tcase_add_test(tc1_1, test_smart_calc_8);
  tcase_add_test(tc1_1, test_smart_calc_9);
  tcase_add_test(tc1_1, test_smart_calc_10);
  tcase_add_test(tc1_1, test_smart_calc_11);
  tcase_add_test(tc1_1, test_smart_calc_12);
  tcase_add_test(tc1_1, test_smart_calc_13);
  tcase_add_test(tc1_1, test_smart_calc_14);
  tcase_add_test(tc1_1, test_smart_calc_15);
  tcase_add_test(tc1_1, test_smart_calc_16);
  tcase_add_test(tc1_1, test_smart_calc_17);
  tcase_add_test(tc1_1, test_smart_calc_18);
  tcase_add_test(tc1_1, test_smart_calc_19);
  tcase_add_test(tc1_1, test_smart_calc_20);
  tcase_add_test(tc1_1, test_smart_calc_21);
  tcase_add_test(tc1_1, test_smart_calc_22);
  tcase_add_test(tc1_1, test_smart_calc_23);
  tcase_add_test(tc1_1, test_smart_calc_24);
  tcase_add_test(tc1_1, test_smart_calc_25);
  tcase_add_test(tc1_1, test_smart_calc_26);
  tcase_add_test(tc1_1, test_smart_calc_27);
  tcase_add_test(tc1_1, test_smart_calc_28);
  tcase_add_test(tc1_1, test_smart_calc_29);
  tcase_add_test(tc1_1, test_smart_calc_30);
  tcase_add_test(tc1_1, test_smart_calc_31);
  tcase_add_test(tc1_1, test_smart_calc_32);
  tcase_add_test(tc1_1, test_smart_calc_33);
  tcase_add_test(tc1_1, test_smart_calc_34);
  suite_add_tcase(s, tc1_1);

  return s;
}

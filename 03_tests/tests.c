#include "tests.h"

int main() {
  int tests_count = 0;
  int failed = 0;

  Suite* smart_calc_tests[] = {
      test_push(), test_fill_node(), test_move_node(), NULL};

  for (int i = 0; smart_calc_tests[i] != NULL; i++) {
    SRunner* runner = srunner_create(smart_calc_tests[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    printf("\n");
    srunner_run_all(runner, CK_NORMAL);
    tests_count += srunner_ntests_run(runner);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n");
  }
  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n\033[0m", failed);
  return failed ? 1 : 0;


}

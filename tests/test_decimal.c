#include "test_decimal.h"

static void run_test(Suite *s, int *failed) {
  SRunner *sr = srunner_create(s);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  *failed += srunner_ntests_failed(sr);
  srunner_free(sr);
}

int main() {
  int failed = 0;
  Suite *s21_decimal_test[] = {test_add(),
                               test_sub(),
                               test_is_equal(),
                               test_is_not_equal(),
                               test_is_greater(),
                               test_is_greater_or_equal(),
                               test_is_less(),
                               test_is_less_or_equal(),
                               test_from_decimal_to_int(),
                               test_from_decimal_to_float(),
                               test_from_int_to_decimal(),
                               test_from_float_to_decimal(),
                               test_negate(),
                               test_truncate(),
                               test_floor(),
                               test_round(),
                               NULL};

  printf("\n" color_start("====== TESTING ======") "\n\n");

  for (Suite **s = s21_decimal_test; *s != NULL; s++) {
    run_test(*s, &failed);
  }

  printf("\n" color_start("====== FAILED: %d ======") "\n", failed);

  return (failed) ? 1 : 0;
}

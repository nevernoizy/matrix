#include "test_matrix.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      test_eq(),          test_create(),    test_sumsub(),
      test_mult(),        test_transpose(), test_calc_complements(),
      test_determinant(), test_inverse(),   NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}

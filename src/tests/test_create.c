#include "test_matrix.h"

START_TEST(create_1) {
  int rows = 10;
  int columns = 10;
  matrix_t matrix = {0};
  int status1 = s21_create_matrix(rows, columns, &matrix);

  if (matrix.matrix) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        ck_assert(fabs(matrix.matrix[i][j]) < 0.0000001);
      }
    }
    ck_assert_int_eq(matrix.rows, rows);
    ck_assert_int_eq(matrix.columns, columns);
    ck_assert_int_eq(status1, 0);
  } else {
    ck_assert_int_eq(status1, 2);
  }

  if (status1 == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_2) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), 1);
}
END_TEST

START_TEST(create_3) {
  const int rows = 10;
  const int cols = 0;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), 1);
}
END_TEST

Suite *test_create(void) {
  Suite *s = suite_create("s21_create");
  TCase *tc = tcase_create("create_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  suite_add_tcase(s, tc);
  return s;
}
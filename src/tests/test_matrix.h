#ifndef SRC_TEST_MATRIX_H
#define SRC_TEST_MATRIX_H

#include <check.h>

#include "../s21_matrix.h"

Suite *test_eq(void);
Suite *test_create(void);
Suite *test_sumsub(void);
Suite *test_mult(void);
Suite *test_transpose(void);
Suite *test_calc_complements(void);
Suite *test_determinant(void);
Suite *test_inverse(void);

#endif  // SRC_TEST_MATRIX_H

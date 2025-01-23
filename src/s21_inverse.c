#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (A == NULL || result == NULL || A->rows < 1 || A->columns < 1) {
    res = 1;
  } else if (A->rows != A->columns) {
    res = 2;
  } else {
    double det = 0.0;
    s21_determinant(A, &det);
    if (fabs(det - 0) > 0.0000001) {
      matrix_t buff = {0};
      res = s21_calc_complements(A, &buff);
      if (res == 0) {
        matrix_t bufftrans = {0};
        res = s21_transpose(&buff, &bufftrans);
        if (res == 0) {
          s21_mult_number(&bufftrans, 1 / det, result);
          s21_remove_matrix(&bufftrans);
        }
        s21_remove_matrix(&buff);
      }
    } else {
      res = 2;
    }
  }
  return res;
}
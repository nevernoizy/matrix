#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A == NULL || B == NULL) {
    res = FAILURE;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res = FAILURE;
  } else {
    for (int i = 0; i < A->rows && res == SUCCESS; i++) {
      for (int j = 0; j < A->columns && res == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 0.0000001) {
          res = FAILURE;
        }
      }
    }
  }
  return res;
}
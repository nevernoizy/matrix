#include "s21_matrix.h"

int s21_sumsub(matrix_t *A, matrix_t *B, matrix_t *result, int flag) {
  int res = 0;
  if (A == NULL || B == NULL || result == NULL) {
    res = 1;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res = 2;
  } else {
    int create_check = s21_create_matrix(A->rows, A->columns, result);
    if (create_check == 0) {
      for (int i = 0; i < A->rows && res == 0; i++) {
        for (int j = 0; j < A->columns && res == 0; j++) {
          if (flag) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          } else {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else {
      res = 1;
    }
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sumsub(A, B, result, 1);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sumsub(A, B, result, 0);
}

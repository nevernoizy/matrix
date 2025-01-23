#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 0;
  if (A == NULL || result == NULL) {
    res = 1;
  } else {
    int create_check = s21_create_matrix(A->rows, A->columns, result);
    if (create_check == 0) {
      for (int i = 0; i < A->rows && res == 0; i++) {
        for (int j = 0; j < A->columns && res == 0; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      res = create_check;
    }
  }
  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (A == NULL || B == NULL || result == NULL) {
    res = 1;
  } else if (A->rows != B->columns || A->columns <= 0 || A->rows <= 0 ||
             B->columns <= 0 || B->rows <= 0) {
    res = 2;
  } else {
    int create_check = s21_create_matrix(A->rows, B->columns, result);
    if (create_check == 0) {
      for (int i = 0; i < A->rows && res == 0; i++) {
        for (int j = 0; j < B->columns && res == 0; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      res = create_check;
    }
  }
  return res;
}
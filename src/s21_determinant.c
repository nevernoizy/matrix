#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL) {
    return 1;
  }
  if (A->rows != A->columns || A->rows < 1 || A->columns < 1) {
    return 2;
  }
  int create_code = 0;
  double d = 0.0;
  matrix_t minor = {0};
  if (A->rows == 1) {
    d = A->matrix[0][0];
  } else if (A->rows == 2) {
    d = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int k = 0; k < A->rows; k++) {
      create_code = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      if (create_code == 0) {
        for (int i = 1; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            if (j == k) {
              continue;
            } else if (j < k) {
              minor.matrix[i - 1][j] = A->matrix[i][j];
            } else {
              minor.matrix[i - 1][j - 1] = A->matrix[i][j];
            }
          }
        }
        double minor_det = 0.0;
        s21_determinant(&minor, &minor_det);
        d += pow(-1, k + 2) * A->matrix[0][k] * minor_det;
        if (create_code == 0) {
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  *result = d;
  return 0;
}

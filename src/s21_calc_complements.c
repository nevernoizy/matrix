#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (A == NULL || result == NULL) {
    res = 1;
  } else if (A->rows != A->columns) {
    res = 2;
  } else {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (res == 0) {
      if (A->rows == 1) {
        result->matrix[0][0] = 1;
      } else {
        matrix_t minor = {0};
        int create_code =
            s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        res = create_code;
        double det = 0;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            if (create_code == 0) {
              make_minor(A, &minor, i, j);
              s21_determinant(&minor, &det);
              result->matrix[i][j] = det * pow(-1, i + j);
            }
          }
        }
        if (create_code == 0) {
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  return res;
}

void make_minor(matrix_t *A, matrix_t *minor, int i, int j) {
  int iminor = 0;
  for (int i1 = 0; i1 < A->rows; i1++) {
    if (i1 == i) {
      continue;
    }
    int jminor = 0;
    for (int j1 = 0; j1 < A->columns; j1++) {
      if (j1 == j) {
        continue;
      }
      minor->matrix[iminor][jminor] = A->matrix[i1][j1];
      jminor++;
    }
    iminor++;
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void matrix_init(matrix *mat, int rows, int cols)
void set_matrix_element(matrix A);

typedef struct {
int rows;
int cols;
double **data;
} matrix;

int main(void){
    matrix *A;
    matrix_init(&A,3,4);
}

void matrix_init(matrix *mat, int rows, int cols) {
int i;
mat->rows = rows;
mat->cols = cols;
mat->data = (double **)malloc(rows * sizeof(double *));
for (i = 0; i < rows; i++) {
mat->data[i] = (double *)malloc(cols * sizeof(double));
}
}

void set_matrix_element()


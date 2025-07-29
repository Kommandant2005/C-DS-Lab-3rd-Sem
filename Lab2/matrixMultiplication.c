#include <stdio.h>
#include <stdlib.h>
int** allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void readMatrix(int **matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", *(matrix + i) + j);
        }
    }
}
void displayMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}
int** multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int **result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            *(*(result + i) + j) = 0;
            for (int k = 0; k < cols1; k++) {
                *(*(result + i) + j) += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
            }
        }
    }
    return result;
}
int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible!\n");
        return 1;
    }

    int **matrix1 = allocateMatrix(rows1, cols1);
    int **matrix2 = allocateMatrix(rows2, cols2);

    printf("Enter elements for the first matrix:\n");
    readMatrix(matrix1, rows1, cols1);

    printf("Enter elements for the second matrix:\n");
    readMatrix(matrix2, rows2, cols2);

    printf("First matrix:\n");
    displayMatrix(matrix1, rows1, cols1);

    printf("Second matrix:\n");
    displayMatrix(matrix2, rows2, cols2);

    int **product = multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2);

    printf("Product of the two matrices:\n");
    displayMatrix(product, rows1, cols2);

    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(product, rows1);

    return 0;
}

/*
*  main.c
*  In this file, I tested the functions in the matrixLib.c file.
*  First Project
*  Created by Ahmet Kaşka on 29.11.2022.
*  Ahmet Kaska ahmet.kaska@stu.fsm.edu.tr
*/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h"
#include <time.h>

// Macros
#define Size 5
#define Row 3
#define Col 4

// Testing...
int main(int argc, const char *argv[])
{
    printf("\nReturn Vector..\n");
    float *ptr = returnVector(Size);
    addElementVector(ptr, Size);
    printVector(ptr, Size);
    free(ptr);

    printf("\n*************************************************\n\n");
    printf("\nReturn Matrix..\n");
    float **mat = returnMatrix(Row, Col);
    addElementMatrix(mat, Row, Col);
    printMatrix(mat, Row, Col);
    freeMatrix(mat, Row);

    printf("\n*************************************************\n\n");

    float *vec = returnVector(Size);
    addElementVector(vec, Size);
    printVector(vec, Size);
    printf("\n\nMean of Vector = %f\n", mean(vec, Size));
    free(vec);

    printf("\n*************************************************\n\n");

    float *vec1 = returnVector(Size);
    addElementVector(vec1, Size);
    printf("Vec1 is = ");
    printVector(vec1, Size);
    puts("");
    printf("Variance = %.2f\n", variance(vec1, Size));
    free(vec1);

    printf("\n*************************************************\n\n");

    float *vector = returnVector(Size);
    float *vector2 = returnVector(Size);
    addElementVector(vector, Size);
    addElementVector(vector2, Size);
    printf("vector : ");
    printVector(vector, Size);
    puts("");
    printf("vector2 : ");
    printVector(vector2, Size);
    puts("");
    // printf("The variance2 of vector : %.f\n",variance2(vector, Size)); This test include value of alternative variance2 functions.
    printf("The variance of vector : %.f\n", variance(vector, Size));
    printf("The variance of vector2 : %.f\n", variance(vector2, Size));
    printf("The correlation of vector and vector2 is : %.f\n", correlation(vector, vector2, Size));
    free(vector);
    free(vector2);

    printf("\n*************************************************\n\n");

    // Covariance
    float *vector3 = returnVector(Size);
    float *vector4 = returnVector(Size);
    addElementVector(vector3, Size);
    addElementVector(vector4, Size);
    printf("Vector3 : ");
    printVector(vector3, Size);
    puts("");
    printf("Vector4 : ");
    printVector(vector4, Size);
    puts("");
    printf("Covariance of the vector3 and vector4 is : %.2f\n", covariance(vector3, vector4, Size));
    free(vector3);
    free(vector4);

    printf("\n*************************************************\n\n");
    printf("\nMatrix Multiplication..\n");
    float **firstMatrix = returnMatrix(Row, Col);
    float **secondMatrix = returnMatrix(Col, Row);
    float **multiplyMatrix = matrixMultiplication(firstMatrix, secondMatrix, Row, Col, Col, Row);
    printMatrix(multiplyMatrix, Row, Col);
    freeMatrix(firstMatrix, Row);
    freeMatrix(secondMatrix, Row);
    freeMatrix(multiplyMatrix, Row);
    printf("\n******************************\n\n");

    printf("\nTranspose\n\n");
    float **matrix = returnMatrix(Row, Col);
    addElementMatrix(matrix, Row, Col);
    printMatrix(matrix, Row, Col);
    float **transpose = matrixTranspose(matrix, Row, Col);
    printf("\n------------\n\n");
    printMatrix(transpose, Col, Row);
    freeMatrix(matrix, Row);
    freeMatrix(transpose, Col);

    printf("\n*************************************************\n\n");
    printf("\n Mean of Rows..\n");
    float **matrix1 = returnMatrix(Row, Col);
    addElementMatrix(matrix1, Row, Col);
    printMatrix(matrix1, Row, Col);
    puts("");
    float *rowMeanVector = rowMeans(matrix1, Row, Col);
    printf("Row Means : ");
    printVector(rowMeanVector, Col);
    freeMatrix(matrix1, Row);
    free(rowMeanVector);
    puts("");

    printf("\n*************************************************\n\n");

    printf("\n Mean of Columns..\n");
    float **matrix2 = returnMatrix(Row, Col);
    addElementMatrix(matrix2, Row, Col);
    printMatrix(matrix2, Row, Col);
    puts("");
    float *colMeanVector = columnMeans(matrix2, Row, Col);
    printf("Column Means : ");
    printVector(colMeanVector, Row);
    freeMatrix(matrix2, Row);
    free(colMeanVector);
    puts("");

    printf("\n*************************************************\n\n");

    printf("\nCovariance Matrix Column\n\n");

    float **matrix3 = returnMatrix(Row, Col);
    addElementMatrix(matrix3, Row, Col);
    printMatrix(matrix3, Row, Col);
    printf("\n---------------------------\n\n");
    covarianceMatrix(matrix3, Row, Col);
    freeMatrix(matrix3, Row);

    printf("\n*************************************************\n\n");

    printf("\nDeterminant of Matrix..\n");
    float **matrix4 = returnMatrix(Row, Col);
    addElementMatrix(matrix4, Row, Row);
    printMatrix(matrix4, Row, Row);
    printf("\n-----------------------------\n\n");
    determinant(matrix4, Row);
    freeMatrix(matrix4, Row);

    return 0;
}

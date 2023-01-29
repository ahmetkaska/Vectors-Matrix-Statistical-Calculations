/*
*  matrixLib.h
*  matrix Lib is my own library. There are prototypes of the functions we use in this file.
*  First Project
*  Created by Ahmet Kaşka on 29.11.2022.
*  Ahmet Kaska ahmet.kaska@stu.fsm.edu.tr
*/

#ifndef matrixLib_h
#define matrixLib_h

float *returnVector(int size);

void addElementVector(float *vec, int size);

float **returnMatrix(int row, int col);

void addElementMatrix(float **matrix, int row, int col);

void freeMatrix(float **mat, int row);

float mean(float *vec, int size);

float variance(float *vec1, int size);

float variance2(float *vector, int size);

float correlation(float *vec, float *vec2, int size);

float covariance(float *vec1, float *vec2, int size);

float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2);

float **matrixTranspose(float **mat, int row, int col);

float *rowMeans(float **mat, int row, int col);

float *columnMeans(float **mat, int row, int col);

float **covarianceMatrix(float **mat, int row, int col);

float determinant(float **mat, int row);

void printVector(float *vec, int N);

void printMatrix(float **mat, int row, int col);

#endif /* matrixLib_h */

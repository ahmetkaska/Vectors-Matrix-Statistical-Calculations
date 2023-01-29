/*
*  matrixLib.c
*  In this file, there are function bodies belonging to the function prototypes in the matrixLib.h file. Furthermore, in fact, I allocated dynamic memory and I did it using pointers.
*  First Project
*  Created by Ahmet Kaşka on 29.11.2022.
*  Ahmet Kaska ahmet.kaska@stu.fsm.edu.tr
*/

// I add some libraries for use the functions and variables of libraries.
#include "matrixLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// With *returnVector function, we can easily allocate space for a vector from ram. I use malloc function.
float *returnVector(int size)
{
    return (float *)malloc(sizeof(float) * size);
}

// This is my function. I used the srand() function from the time library for assignment random value element of vectors.
void addElementVector(float *vec, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        *(vec + i) = rand() % 10;
    }
}

// With **returnMatrix function, we can easily allocate space for a matrix from ram. I use malloc function separately for rows and columns.
float **returnMatrix(int row, int col)
{
    float **matrix;
    matrix = (float **)malloc(row * sizeof(float));
    for (int i = 0; i < row; i++)
    {
        *(matrix + i) = (float *)malloc(col * sizeof(float));
    }
    return matrix;
}

// This is my function. I used the srand() function from the time library for assignment random value element of matrix.
void addElementMatrix(float **matrix, int row, int col)
{
    srand(time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*matrix + (i * col) + j) = rand() % 10;
        }
    }
}

// With freeMatrix function, we can empty the values ​​in ram. It is similar to garbage collector in Java.
void freeMatrix(float **mat, int row)
{

    for (int i = 0; i < row; i++)
    {
        free(*(mat + i));
    }
    free(mat);
}

// With mean function, we can easily calculate mean of vectors.
float mean(float *vec, int size)
{
    float sum = 0;
    int sayac = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(vec + i);
        sayac++;
    }
    return sum / sayac;
}

//  With variance function, we can easily calculate variance of vectors.
float variance(float *vec1, int size)
{
    float sumOfSquare1 = 0;
    float sum1 = 0;
    float squareOfSum1 = 0;

    for (int i = 0; i < size; i++)
    {
        sumOfSquare1 += pow(*(vec1 + i), 2);
        sum1 += *(vec1 + i);
    }
    squareOfSum1 = pow(sum1, 2);

    float varianceVec1 = ((size * sumOfSquare1) - squareOfSum1) / (size * (size - 1));
    return varianceVec1;
}

// Variance2 function is an alternative function of variance function.
float variance2(float *vector, int size)
{
    float meanVector = mean(vector, size);
    float deviation;
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        deviation = *(vector + i) - meanVector;
        sum += powf(deviation, 2); // Variance is square of standard deviation.
    }
    return sum / (size - 1);
}

// With correlation function, we can easily calculate correlation of two vectors.
float correlation(float *vec, float *vec2, int size)
{
    float sumMuxXY = 0;             // the sum of the products
    float sumX = 0, sumY = 0;       // sum of X and Y
    float sumPowX = 0, sumPowY = 0; // sum of square X and sum of square Y

    for (int i = 0; i < size; i++)
    {
        sumMuxXY += (*(vec + i)) * (*(vec2 + i));
        sumX += *(vec + i);
        sumY += *(vec2 + i);
        sumPowX += (*(vec + i)) * (*(vec + i));
        sumPowY += (*(vec2 + i)) * (*(vec2 + i));
    }

    // r = pay-> (N Σ xy – Σx Σy) / payda -> ([[N Σ x2 – (Σx)2] [N Σy2 – (Σy)2]]1/2) The formula of correlation.

    float pay = sumMuxXY - (sumX * sumY / size);
    float payda = sqrtf(((sumPowX - (pow(sumX, 2) / size)) * (sumPowY - (pow(sumY, 2) / size))));
    float r = pay / payda;
    return r;
}

// With covariance function, we can easily calculate covariance of two vectors.
float covariance(float *vec1, float *vec2, int size)
{
    float meanVec1 = mean(vec1, size); // Mean of first vector.
    float meanVec2 = mean(vec2, size); // Mean of second vector.
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ((*(vec1 + i) - meanVec1) * (*(vec2 + i) - meanVec2)); // Values of sending as parameter vectors minus mean of vectors.
    }
    return sum / (size - 1);
}

// With **matrixMultiplication function, we can easily calculate matrix multiplication of two matrix. Matrix multiplication has some rules.
float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2)
{

    float **newMatrix = returnMatrix(row1, col2); // The dimensions of the new matrix, which is formed as a result of matrix multiplication, which provides the product rule, are the number of rows of the first matrix x the number of columns of the second matrix.
    int sum;
    if (col1 == row2) // For a matrix to be a product, the number of columns in the first matrix must be equal to the number of rows in the second matrix.
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                sum = 0;
                // newMatrix[i][j] = 0;
                for (int z = 0; z < col1; z++)
                {
                    // *(*newMatrix+(i*col2)+j) += (*(*mat1+(i*col1)+z)) * (*(*mat2+(z*col1)+j));
                    // newMatrix[i][j] = newMatrix[i][j] + mat1[i][z] * mat2[z][j];
                    sum += (*(*(mat1 + i) + z)) * (*(*(mat2 + z) + j));
                }

                (*(*(newMatrix + i) + j)) = sum;
            }
        }
        return newMatrix;
    }
    else
    {
        printf("Yanlis sutun sayisi\n");
        return 0;
    }

    return 0;
}

// With **matrixTranspose function, we can easily find transpose a matrix. The reverse cross of a matris can be obtained in the following ways.
float **matrixTranspose(float **mat, int row, int col)
{
    int temp = row;
    row = col;
    col = temp;

    float **transpose = returnMatrix(row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*transpose + (i * col) + j) = *(*mat + (j * col) + i);
            //  transpose[j][i] = mat[i][j];
        }
    }
    return transpose;
}

// With *rowMeans function, we can easily calculate mean of all rows. After that, we can keep mean of rows in a vector.
float *rowMeans(float **mat, int row, int col)
{
    float *rowMatrix = returnVector(col);
    float sum = 0;
    float rowMean = 0;

    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            sum += *(*mat + (i * col) + j);
        }
        rowMean = sum / row;
        *(rowMatrix + j) = rowMean;
        sum = 0;
    }
    return rowMatrix;
}

// With *columnMeans function, we can easily calculate mean of all columns. After that, we can keep mean of columns in a vector.
float *columnMeans(float **mat, int row, int col)
{
    float *colMatrix = returnVector(row);
    float sum = 0;
    float colMean = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += *(*mat + (i * col) + j);
        }
        colMean = sum / col;
        *(colMatrix + i) = colMean;
        sum = 0;
    }
    return colMatrix;
}

// With **covarianceMatrix function, It will take the matrix and its dimensions as parameters, and return the covariance matrix of this matrix by column.
float **covarianceMatrix(float **mat, int row, int col)
{
    float *column = returnVector(row);
    float *varianceVector = returnVector(col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(column + i) = *(*mat + i * col + j);
        }
        *(varianceVector + i) = variance2(column, row);
        //printVector(column, col);
    }
    // printVector(varianceVector, row);
    return varianceVector;
}

// With determinant function, we can easily calculate determinant of matrix.
float determinant(float **mat, int row)
{
    for (int i = 0; i < row; i++)
    {
        mat[i] = (float *)realloc(mat[i], sizeof(float) * (row + row - 1));  // Reallocating matrix.
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row - 1; j++)
        {
            mat[i][row + j] = mat[i][j];
        }
    }
    float *negativeVector = returnVector(row); // negative values
    float *positiveVector = returnVector(row); // positive values

    for (int i = 0; i < row; i++)
    {
        negativeVector[i] = mat[0][(i + 2) % row] * mat[1][(i + 1) % row] * mat[2][i];
    }
    for (int i = 0; i < row; i++)
    {
        positiveVector[i] = mat[0][i] * mat[1][(i + 1) % row] * mat[2][(i + 2) % row];
    }
    float sum = 0;
    for (int i = 0; i < row; i++)
    {
        sum += positiveVector[i];
        printf("%f \n", sum);
    }
    for (int i = 0; i < row; i++)
    {
        sum -= negativeVector[i];
        printf("%f \n", sum);
    }

    return sum;
}

// With printVector function, we can easily write our vectors.
void printVector(float *vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%.f\t", *(vec + i));
    }
}

// With printMatrix function, we can easily write our matrix.
void printMatrix(float **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.f\t", *(*mat + (i * col) + j));
        }
        puts("");
    }
}

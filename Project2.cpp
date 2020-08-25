/* Project2.cpp
 * Kevin Li
 * kal3552
 * EE312, Spring 2020
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void printMatrix(double a[], const uint32_t rows, const uint32_t cols);
void printMatrixPtr(double **a, const uint32_t rows, const uint32_t cols);

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
        uint32_t loop1=0;
        uint32_t loop2=0;
        uint32_t index=0;
        while(loop1 < a_rows)
        {
            while(loop2 < b_cols)
            {
                uint32_t counter = 0;
                double sum = 0.0;
                while(counter < a_cols)
                {
                    sum += a[loop1 * a_cols + counter] * b[counter * b_cols + loop2];
                    counter++;
                }
                c[index] = sum;
                loop2++;
                index++;
            }
            loop2 = 0;
            loop1++;
        }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
    double **matrix= (double**) malloc(a_rows * sizeof(double*)); //allocation of new matrix
    for(int i=0;i<a_rows;i++)
    {
        matrix[i]= (double*) malloc(b_cols * sizeof(double));
    } //allocation done
    uint32_t loop1=0;
    uint32_t loop2=0;
    while(loop1 < a_rows)
    {
        while(loop2 < b_cols)
        {
            uint32_t counter=0;
            double sum=0.0;
            while(counter<a_cols)
            {
                sum += a[loop1][counter] * b[counter][loop2];
                counter++;
            }
            matrix[loop1][loop2] = sum;
            loop2++;
        }
        loop2=0;
        loop1++;
    }
    return matrix;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {
    double **matrix=(double**)malloc(a_cols * sizeof(double*)); //start allocating
    for(int i=0; i<a_cols; i++)
    {
        matrix[i] = (double*)malloc(a_rows * sizeof(double));
    } //finished allocating
    uint32_t loop1=0;
    uint32_t loop2=0;
    while(loop1<a_rows)
    {
        while(loop2<a_cols)
        {
            matrix[loop2][loop1]=a[loop1][loop2];
            loop2++;
        }
        loop2=0;
        loop1++;
    }
    return matrix;
}

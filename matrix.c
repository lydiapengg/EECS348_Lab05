#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE]){
    for (int row=0; row<SIZE; row++){
        for (int column=0; column<SIZE; column++){
            result[row][column] = matrix1[row][column] + matrix2[row][column];
        }
    }
    
}
void multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++ ){
        for (int column = 0; column < SIZE; column++){
            result[row][column] = 0;
            for(int index = 0; index < SIZE; index++){
                result[row][column] += matrix1[row][column]*matrix2[row][column];
            }
        }
    }
}
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]){
    for (int row=0; row<SIZE; row++) {
        for (int column=0; column<SIZE; column++ ){
            result[column][row] = matrix[row][column];
        }
    }
}
void printMatrix(int matrix[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++){
        for (int column=0; column < SIZE; column++){
            printf("%d", matrix[row][column]);
        }
        printf("\n");
    }
}

int main(){
    int m1[SIZE][SIZE] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    int m2[SIZE][SIZE] = {
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10,9,8,7,6},
        {5,4,3,2,1}
    };
    int result[SIZE][SIZE];
    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("\nMatrix 2:\n");
    printMatrix(m2);

    addMatrices(m1, m2, result);
    printf("\nSum of Matrix 1 and Matrix 2");
    printMatrix(result);

    multiplyMatrices(m1, m2, result);
    printf("\nProduct of Matrices:\n");
    printMatrix(result);

    transposeMatrix(m1, result);
    printf("Transpose Matrix:\n");
    printMatrix(result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*
 *  Copy values from matrix a to matrix b.
 */
void arratCopy(char a[10][10], char b[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            b[i][j] = a[i][j];
        }
    }
}

/*
 *  This function takes a 10 by 10 matrix of characters and rotates
 *  it 90 degrees clockwise, updating the matrix that was passed in.
 */
void rotate(char matrix[10][10]) {
    char copy[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            copy[j][10 - 1 - i] = matrix[i][j];
        }
    }
    arratCopy(copy, matrix);
}

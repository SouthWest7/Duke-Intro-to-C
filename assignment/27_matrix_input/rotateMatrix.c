#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  Copy values from matrix a to matrix b.
 */
void arrayCopy(char a[10][10], char b[10][10]) {
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
    arrayCopy(copy, matrix);
}

void printMatrix(char matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

#define LINE_SIZE 12

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: rotateMatrix inputFileName\n");
        return EXIT_FAILURE;
    }

    FILE* f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "Could not open file\n");
        return EXIT_FAILURE;
    }
    
    char buffer[LINE_SIZE];
    char matrix[10][10];
    int n_line = 0;
    while (fgets(buffer, LINE_SIZE, f) != NULL) {
    if (n_line >= 10) {
        fprintf(stderr, "Too many lines!\n");
        return EXIT_FAILURE;
    }
    if (strchr(buffer, '\n') == NULL) {
        fprintf(stderr, "Line is too long!\n");
        return EXIT_FAILURE;
    }
    if ((strchr(buffer, '\n') - buffer) < 10) {
        fprintf(stderr, "Line is too short!\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 10; i++) {
        matrix[n_line][i] = buffer[i];
    }
    n_line++;
    }

    if (n_line != 10) {
        fprintf(stderr, "Not enough number of lines\n");
        return EXIT_FAILURE;
    }

    rotate(matrix);
    printMatrix(matrix);
    return EXIT_SUCCESS;
}
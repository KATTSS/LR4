#include <stdio.h>
#include <stdlib.h>

void nechetny(int n) {
    int **magicSquare = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        magicSquare[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }
    int num = 1;
    int i = 0, j = n / 2;
    while (num <= n * n) {
        magicSquare[i][j] = num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (magicSquare[newi][newj]) {
            i++;
        } else {
            i = newi;
            j = newj;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", magicSquare[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(magicSquare[i]);
    }
    free(magicSquare);
}

int other(int n) {
    int **other = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i) {
        other[i] = (int *)calloc(n, sizeof(int));
    }

    int half = n / 2;

    int **pal = (int **)calloc(half, sizeof(int *));
    for (int i = 0; i < half; ++i) {
        pal[i] = (int *)calloc(half, sizeof(int));
    }

    nechetny(half);
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            other[i][j] = pal[i][j];
            other[i + half][j] = pal[i][j] + half * half * 2;
            other[i][j + half] = pal[i][j] + half * half * 3;
            other[i + half][j + half] = pal[i][j] + half * half;
        }
    }

    // Перемещение колонок
    int k = (n - 2) / 4;
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < k; ++j) {
            int temp = other[i][j];
            other[i][j] = other[i + half][j];
            other[i + half][j] = temp;
        }
        for (int j = n - k + 1; j < n; ++j) {
            int temp = other[i][j];
            other[i][j] = other[i + half][j];
            other[i + half][j] = temp;
        }
    }
}
    // Перемещение централь
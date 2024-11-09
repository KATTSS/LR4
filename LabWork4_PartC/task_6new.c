#include <stdio.h>
#include <stdlib.h>

int chetny(int n, int **square);
int nechetny(int n, int **square, int rad, int stolbik, int num);


int main()
{
    int n;
    printf("\nВведите порядок магического квадрата: ");
    scanf("%d", &n);
     // создание массива с нулями для заполнения элементами
    int **square = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        square[i] = (int *)calloc(n, sizeof(int));
    }
    
    if (n % 4 == 0)
    {
        chetny(n, square);
    }
    else
    {
        nechetny(n, square, n/2, n-1, 1);
    }

    return 0;
}

inline int chetny(int n, int **square)
{
   
    // заполнение натуральными числами по порядку
    int num = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            square[i][j] = num;
            num++;
        }
    }
    // перестройка до магического квадрата
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3))
            {
                square[i][j] = n * n + 1 - square[i][j];
            }
        }
    }
    // экранный вывод
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%5d", square[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}

inline int nechetny(int n, int **square, int rad, int stolbik, int num)
{
    
   // int num = 1, stolbik = n - 1, rad = n / 2;

    while (num <= n * n)
    {
        square[rad][stolbik] = num;

        ++num;
        ++stolbik;
        --rad;

        if (rad == -1 && stolbik == n)
        {
            rad = 0;
            stolbik = n - 2;
        }
        else if (rad < 0)
            rad = n - 1;
        else if (stolbik == n)
            stolbik = 0;
        if (square[rad][stolbik])
        {
            ++rad;
            stolbik -= 2;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%5d", square[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < n; ++i)
    {
        free(square[i]);
    }
    free(square);
    square = NULL;

    return 0;
}

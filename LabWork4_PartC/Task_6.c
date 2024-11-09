#include <stdio.h>
#include <stdlib.h>

int chetny(int n);
int nechetny(int n);
int other(int n);

int main()
{
    int n;
    printf("\nВведите порядок магического квадрата: ");
    scanf("%d", &n);
    if((n-2)%4==0) {
        other(n);
    }
    if (n % 4 == 0)
    {
        chetny(n);
    }
    else
    {
        nechetny(n);
    }

    return 0;
}

inline int chetny(int n)
{
    // создание массива с нулями для заполнения элементами
    int **square = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        square[i] = (int *)calloc(n, sizeof(int));
    }
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

inline int nechetny(int n)
{
    // создание массива с нулями для заполнения элементами
    int **squaren = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        squaren[i] = (int *)calloc(n, sizeof(int));
    }

    int num = 1, stolbik = n - 1, rad = n / 2;

    while (num <= n * n)
    {
        squaren[rad][stolbik] = num;

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
        if (squaren[rad][stolbik])
        {
            ++rad;
            stolbik -= 2;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%5d", squaren[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < n; ++i)
    {
        free(squaren[i]);
    }
    free(squaren);
    squaren = NULL;

    return 0;
}
inline int other(int n)
{

    int **other = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        other[i] = (int *)calloc(n, sizeof(int));
    }

    int half=n/2;

    int** pal=(int**)calloc(half, sizeof(int*));
    for (int i=0; i<half; ++i) {
        pal[i]=(int*)calloc(half, sizeof(int));
    }

    nechetny(half);
     for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            int x = i * 2;
            int y = j * 2;
            other[i][j] = pal[i][j];
            other[i + half][j] = pal[i][j] + half*half * 2;
            other[i][j + half] = pal[i][j] + half*half* 3;
            other[i + half][j + half] = pal[i][j] + half;
        }
    }
     for (int i = 0; i < n; ++i)
    {
        free(pal[i]);
    }
    free(pal);
    pal = NULL;

   
        for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%5d", other[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < n; ++i)
    {
        free(other[i]);
    }
    free(other);
    other = NULL;

    return 0;
}

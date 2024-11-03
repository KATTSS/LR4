#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    // создание динамического трёхмерного массива
    int ***kub = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; ++i)
    {
        kub[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; ++j)
        {
            kub[i][j] = (int *)malloc(n * sizeof(int));
        }
    }

    // заполнение массива
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                printf("Введите элемент массива: ");
                scanf("%d", &kub[i][j][k]);
                // printf("%d ", kub[i][j][k]);
            }
        }
    }

    // диагонали: главная(левый верхний передний)
    int summain = 0;
    for (int i = 0; i < n; ++i)
    {
        summain += kub[i][i][i];
    }
    printf("\nsummain=%d ", summain);

    // диагонали: побочная 1(правый верхний передний)
    int j = n - 1, sum1 = 0;
    for (int i = 0; i < n; ++i)
    {
        sum1 += kub[i][j][i];
        --j;
    }
    printf("\nsum1=%d ", sum1);

    // диагонали: побочная 2(правый верхний задний)
    int k = n - 1, sum2 = 0;
    for (int i = 0; i < n; ++i)
    {
        sum2 += kub[i][k][k];
        --k;
    }
    printf("\nsum2=%d ", sum2);

    // диагонали: побочная 3(левый верхний задний)
    int l = n - 1, sum3 = 0;
    for (int i = 0; i < n; ++i)
    {
        sum3 += kub[i][i][l];
        --l;
    }
    printf("\nsum3=%d ", sum3);

    if (summain > sum1 && summain > sum2 && summain > sum3)
        printf("\nСумма элементов диагонали из лвого переднего верхнего угла максимальная");
    else if (sum1 > summain && sum1 > sum2 && sum1 > sum3)
        printf("\nСумма элементов диагонали из правого переднего верхнего угла максимальная");
    else if (sum2 > summain && sum2 > sum1 && sum2 > sum3)
        printf("\nСумма элементов диагонали из правого заднего верхнего угла максимальная");
    else if (sum3 > summain && sum3 > sum1 && sum3 > sum2)
        printf("\nСумма элементов диагонали из левого заднего верхнего угла максимальная");
    else
        printf("\nЕсть равные значения сумм элементов диагоналей");
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int *kub = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        printf("Введите элемент массива: ");
        scanf("%d", &kub[i]);
        printf("%d ", kub[i]);
    }
    printf("kub :");
    for (int k = 0; k < n; ++k)
    {
        printf("%d ", kub[k]);
    }

    free(kub);
    kub=NULL;
    return 0;
}
//all working
#include <stdio.h>
#include <stdlib.h>

int chetny(int n, int **square);
int nechetny(int n, int **square, int rad, int stolbik, int num);
int other(int **square, int n);
void freemem(int **square, int n);
void printsq(int **square, int n);
void menuc();
int task6();

int main()
{
    menuc();
    int exit=0;
    while (exit!=1) {
    char *s=NULL;
    size_t ssize = 0;
    __ssize_t stringsize;
    const char* valid_chars = "12345";
    int x;
   
    do
    {
        
        printf("\nВведите номер желаемой операции: ");
        stringsize=getline(&s, &ssize, stdin);
        if(stringsize==-1){
            perror("Ошибка ввода");
            return 1;
        }
        x=atoi(s);
        free(s);   
    }while ( x < 1 || x > 5);
   // free(s); 
    switch (x)
        {
        case 1:
            printf("Магический квадрат");
            break;

        case 2:
            printf("Буткевич Екатерина, группа 453501");
            break;

        case 3:
            task6();
            getline(&s, &ssize, stdin);
            break;

        case 4:
             menuc();
            break;

        case 5:
        exit= 1;
        break;
        }
    }
    
    return 0;
}

void menuc()
{
    printf("\nСуть программы - 1\nКто выполнил задание? - 2\nЗапуск программы - 3\nМеню - 4\nЗавершить программу - 5\n");
}

int task6()
{
    int n;
    printf("\nВведите порядок магического квадрата: ");
    scanf("%d", &n);

    // Cпроверка на существование
        if (n==1)
    {
        printf("%d", 1);
        return 1;
    }
    if (n < 3 && n!=1)
    {
        printf("NO");
        return 1;
    }

    // создание массива с нулями для заполнения элементами
    int **square = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        square[i] = (int *)calloc(n, sizeof(int));
    }

    if ((n - 2) % 4 == 0)
    {
        other(square, n);
    }
    else if (n % 4 == 0)
    {
        chetny(n, square);
    }
    else
    {
        nechetny(n, square, 0, n / 2, 1);
    }

    printsq(square, n);
    freemem(square, n);

    return 0;
}

int chetny(int n, int **square)
{
    // заполнение натуральными числами по порядку
    int num = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            square[i][j] = num++;
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

    return 0;
}

int nechetny(int n, int **square, int rad, int stolbik, int num)
{
    while (num <= n * n)
    {
        square[rad][stolbik] = num++;

        // переход к след позиции
        stolbik++;
        rad--;

        if (rad == -1 && stolbik == n)
        {
            rad += 2;
            stolbik--;
        }
        if (rad < 0)
        {
            rad = n - 1;
        }
        if (stolbik == n)
        {
            stolbik = 0;
        }
        if (square[rad][stolbik])
        {
            rad += 2;
            stolbik--;
        }
    }

    return 0;
}

int other(int **square, int n)
{
    int halfN = n / 2;
    int **subSquare = (int **)calloc(halfN, sizeof(int *));
    for (int i = 0; i < halfN; ++i)
    {
        subSquare[i] = (int *)calloc(halfN, sizeof(int));
    }

    // заполнение первой 1/4 нечётным методом
    nechetny(halfN, subSquare, 0, halfN / 2, 1);

    // корректное заполнение четвертинок
    for (int i = 0; i < halfN; ++i)
    {
        for (int j = 0; j < halfN; ++j)
        {
            square[i][j] = subSquare[i][j];
            square[i][j + halfN] = subSquare[i][j] + 2 * halfN * halfN;
            square[i + halfN][j + halfN] = subSquare[i][j] + halfN * halfN;
            square[i + halfN][j] = subSquare[i][j] + 3 * halfN * halfN;
        }
    }
    printsq(square, n);
    printf("\n");

    // рядовые(столбичные) замены
    for (int i = 0; i < halfN; ++i)
    {
        for (int j = 0; j < halfN / 2; ++j)
        {
            if (i == halfN / 2)
            {
                int temp = square[i][j + 1];
                square[i][j + 1] = square[i + halfN][j + 1];
                square[i + halfN][j + 1] = temp;
            }
            else
            {
                int temp = square[i][j];
                square[i][j] = square[i + halfN][j];
                square[i + halfN][j] = temp;
            }
        }
    }

    for (int i = 0; i < halfN; ++i)
    {
        for (int j = halfN + halfN / 2 + 2; j < n; ++j)
        {
            int temp = square[i][j];
            square[i][j] = square[i + halfN][j];
            square[i + halfN][j] = temp;
        }
    }

    // свободу дополнительно заданной памяти!!!!
    freemem(subSquare, halfN);

    return 0;
}

void freemem(int **square, int n)
{
    // освобождение памяти
    for (int i = 0; i < n; ++i)
    {
        free(square[i]);
    }
    free(square);
}

void printsq(int **square, int n)
{
    // экранный вывод
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%5d ", square[i][j]);
        }
        printf("\n");
    }
}

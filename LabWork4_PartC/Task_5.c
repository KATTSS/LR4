#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void menuc();
int task5();
int provnanatural(const char *str);

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
        
    }while ( x < 1 || x > 5);
    free(s);  
    switch (x)
        {
        case 1:
            printf("Сапёр");
            break;

        case 2:
            printf("Буткевич Екатерина, группа 453501");
            break;

        case 3:
            task5();
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

int task5()
{
    int n, m, q=0;
    char vvod[1000];

    do {
    printf("Введите размер поля(n): ");

    scanf("%s", vvod);
    if(provnanatural(vvod)) {
        n=atoi(vvod);
        q=1;
    }
    else {
        printf("Размер должен быть натуральным числом. ");
    } } while (q!=1);
    //printf("Введите размеры поля(n*m): ");
    
    q=0;

    do {
    printf("Введите размер поля(m): ");

    scanf("%s", vvod);
    if(provnanatural(vvod)) {
        m=atoi(vvod);
        q=1;
    }
    else {
        printf("Размер должен быть натуральным числом. ");
    } } while (q!=1);


    // создание массива-поля для сапёра
    int **map = (int **)malloc((n + 2) * sizeof(int *));
    for (int i = 0; i < n + 2; ++i)
    {
        map[i] = (int *)malloc((m + 2) * sizeof(int));
    }
    int bomb;
    q=0;
    do {
    printf("Укажите желаемое число бомб(не превышает n*m): ");

    scanf("%s", vvod);
    if(provnanatural(vvod)) {
        bomb=atoi(vvod);
        q=1;
    }
    else {
        printf("Вы не можете поставить не натуральное число бомб!");
    } } while (q!=1 || bomb >= m * n);
    // printf("Укажите желаемое число бомб: ");
    // scanf("%d", &bomb); 
    // if (bomb >= m * n)
    // {
    //     printf("Число бомб не может превышать размеры поля. Повторите ввод: ");
    //     scanf("%d", &bomb);
    // }
    // while (bomb >= m * n)
    //     ;

    // создание массива-поля для записи цифровых подсказок по поиску бомбы
    int **num = (int **)malloc((n + 2) * sizeof(int *));
    for (int i = 0; i < n + 2; ++i)
    {
        num[i] = (int *)malloc((m + 2) * sizeof(int));
    }

    // постановка бомб используя генератор случайности основанный на текущем времени
    srand(time(NULL));

    for (int i = 0; i < n + 2; ++i) // заполнение массива нулями
    {
        for (int j = 0; j < m + 2; ++j)
        {
            map[i][j] = 0;
            num[i][j] = 0;
        }
    }

    for (int b = 0; b < bomb; ++b) // непосредственно постановка бомб
    {
        int i, j;
        do
        {
            i = rand() % n + 1;
            j = rand() % m + 1;
        } while (map[i][j] == 1);
        map[i][j] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // printf("%d", map[i][j]);
            if (map[i][j] == 1)
                printf("%s", "*");
            else
                printf("%s", ".");
            printf(" ");
        }
        printf("\n");
    }
    // проходка по ячейкам и подсчёт бомбочек
    printf("%s", "\nПодсчёт бомбочек:\n");
    // неопсредственно проходка
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            num[i][j] = map[i - 1][j - 1] + map[i - 1][j] + map[i - 1][j + 1] + map[i][j - 1] + map[i][j + 1] + map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
            printf("%d", num[i][j]);
            printf("%s", " ");
        }
        printf("\n");
    }

    // освобождение памяти
    for (int i = 0; i < n + 2; i++)
    {
        free(map[i]);
        free(num[i]);
    }
    free(map);
    free(num);
    map=NULL;
    num=NULL;
    return 0;
}

int provnanatural(const char *str)
{
    for (int i = 0; i < strlen(str); ++i)
    {
        if (!isdigit((unsigned char)str[i]))
        {
            return 0; // Не является натуральным числом
        }
    }
    return 1; // Является натуральным числом
}

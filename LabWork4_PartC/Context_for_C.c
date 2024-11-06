#include <stdio.h>
#include <stdlib.h>

void menuc();

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
    free(s); 
    switch (x)
        {
        case 1:
            printf("описание задания");
            break;

        case 2:
            printf("Буткевич Екатерина, группа 453501, вариант  7");
            break;

        case 3:
        
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
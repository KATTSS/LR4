#include <iostream>
#include <limits>
#include <string>

void menu();
int vvod();
int task3();

int main()
{
    bool exit = false;

    menu();

    while (!exit)
    {
        int x;
        std::string s;

        do
        {
            std::cout << "Введите номер желаемой операции: ";
            std::getline(std::cin, s);
            x = std::atoi(s.c_str());
        } while (s.find_first_not_of("12345") != std::string::npos || x < 1 || x > 5);

        switch (x)
        {
        case 1:
            std::cout << "Найти скалярное произведение строки с максимальным членом и столбца с минимальным членом матрицы" << std::endl;
            break;

        case 2:
            std::cout << "Буткевич Екатерина, группа 453501, вариант  7" << std::endl;
            break;

        case 3:
            task3();
            std::getline(std::cin, s);
            break;

        case 4:
            exit = true;
            break;

        case 5:
            menu();
            break;
        }
    }

    return 0;
}

void menu()
{

    std::cout << "\nСуть программы - 1" << std::endl;
    std::cout << "Кто выполнил задание? - 2" << std::endl;
    std::cout << "Запуск программы - 3" << std::endl;
    std::cout << "Завершить программу - 4" << std::endl;
    std::cout << "Меню - 5\n"
              << std::endl;
}

int task3()
{
    int n;
    std::string s;
    do
    {
        std::cout << "Введите размер матрицы: ";
        std::getline(std::cin, s);
        n = std::atoi(s.c_str());
    } while (s.find_first_not_of("1234567890") != std::string::npos);

    float **matrix = new float *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new float[n];
    }
    std::cout << "\nВведите элементы матрицы: ";

    float min, max;
    // ввод элементов матрицы в одномерный массив и проверка из на совпадение
    float *a = new float[n * n];
    for (int i = 0; i < n * n; ++i)
    {
        a[i] = vvod();
        for (int k = i - 1; k >= 0; --k)
        {

            while (a[i] == a[k])
            {
                std::cout << "Значения не должны дублироваться, повторите ввод :";
                a[i] = vvod();
            }
        }
    }
    // поиск минимального и маскимального значений
    max = a[0];
    min = a[0];
    for (int i = 0; i < n * n; ++i)
    {

        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    std::cout << "min= " << min << '\n'
              << "max= " << max << '\n';

    // преобразование из одномерного массива в матрицу
    int k = 0, jmin, imax;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = a[k];
            if (a[k] == min)
                jmin = j;
            if (a[k] == max)
                imax = i;
            k++;
        }
    }
    std::cout << "jmin=" << jmin << " " << "imax=" << imax << '\n';

    delete [] a;

    // вывод матрицы в терминал
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    float *sum = new float[n];

    // вычисление скалярного произведения
    std::cout << "Скалярное произведение равно: ";
    for (int k = 0; k < n; ++k)
    {
        sum[k] = matrix[imax][k] * matrix[k][jmin];
        std::cout << sum[k] << " ";
    }

    //очистка памяти
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i]; // Удаление строк
    }
    delete[] matrix; // Удаление массива указателей
    delete[] sum;
    return 0;
}

int vvod()
{
    std::string s;
    int x;
    do
    {
        std::cout << "a[i][j]=";
        std::getline(std::cin, s);
        x = std::atoi(s.c_str());
    } while (s.find_first_not_of("1234567890") != std::string::npos);
    return x;
}
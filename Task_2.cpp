#include <iostream>

void menu();
int task2();
int vvod(int y, int b);

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
            std::cout << "Найти минимальный элемент матрицы, лежащий ниже побочной диагонали" << std::endl;
            break;

        case 2:
            std::cout << "Буткевич Екатерина, группа 453501, вариант 7" << std::endl;
            break;

        case 3:
            task2();
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

int task2()
{
    int m, n;
    n = vvod(1, 1);
    m = vvod(1, 2);

    int matrix[n][m];
    std::cout << "\nВведите элементы матрицы: ";
    for (int i = 0; i < n; ++i) // ввод элементов матрицы
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = vvod(2, 0);
        }
    }
    int min = matrix[1][m - 1];

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = m - 1; j >= m - i; --j)
        {

            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    std::cout << "min = " << min << std::endl;
    // вывод матрицы в терминал
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         std::cout << matrix[i][j] << "\t";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}

int vvod(int y, int b)
{
    std::string s;
    int x;
    if (y == 1)
    {
        do
        {
            if (b == 1)
                std::cout << "Введите размеры строки матрицы(>1): ";
            else if (b == 2)
                std::cout << "Введите размеры столбца матрицы(>1): ";
            std::getline(std::cin, s);
            x = std::atoi(s.c_str());
        } while (s.find_first_not_of("1234567890") != std::string::npos || x <= 1);
    }
    else if (y == 2)
    {
        std::cout << "a[i][j]: ";
        std::getline(std::cin, s);
        x = std::atoi(s.c_str());
    }
    while (s.find_first_not_of("1234567890") != std::string::npos);

    return x;
}
#include <iostream>

void menu();
int task2();

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
    std::cout << "Введите количество строк матрицы: ";
    do
    {
        std::cin >> n;
        if (n <= 1)
            std::cout << "Количество строк должно быть >1, чтобы существовали элементы,\nлежащие ниже побочной диагонали.\nПопробуйте ещё раз: " << '\n';
    } while (n <= 1);
    std::cout << "Введите количество столбцов матрицы: ";
    do
    {
        std::cin >> m;
        if (m <= 1)
            std::cout << "Количество столбцов должно быть >1, чтобы существовали элементы,\nлежащие ниже побочной диагонали.\nПопробуйте ещё раз: " << '\n';
    } while (m <= 1);

    int matrix[n][m];
    std::cout << "\nВведите элементы матрицы: ";
    for (int i = 0; i < n; ++i) // ввод элементов матрицы
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
    int min = matrix[1][m - 1];
    // std::cout << "min = " << min << std::endl;
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = m - 1; j >= m - i; --j)
        {
            // std::cout << matrix[i][j] << " ";
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
#include <iostream>

void menu();
int task1();

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
            std::cout << "Задать статический массив из k элементов,\nсдвинуть элементы циклично на n позиций вправо " << std::endl;
            break;

        case 2:
            std::cout << "Буткевич Екатерина, группа 453501" << std::endl;
            break;

        case 3:
            task1();
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

int task1()
{
    int k;
    std::cout << "Введите количество элементов массива: ";
    std::cin >> k;

    int array[k];

    std::cout << "\nВведите элементы массива: ";
    for (int i = 0; i < k; ++i) // ввод элементов массива
    {
        std::cin >> array[i];
    }

    int sdvig;
    std::cout << "Введите количество позиций, на которые хотите сдвинуть элементы массива: ";
    std::cin >> sdvig;

    for (int i = 0; i < sdvig; ++i)
    {
        int prev;

        for (int i = k - 1; i > 0; --i)
        {
            prev = array[i];
            array[i] = array[i - 1];
            array[i - 1] = prev;
        }
    }

    std::cout << "Массив после сдвига: ";
    for (int i = 0; i < k; ++i)
    {
        std::cout << array[i] << " ";
    }

    return 0;
}
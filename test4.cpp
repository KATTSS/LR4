#include <gtest/gtest.h>
#include <string>
#include <sstream>

extern "C"
{
    std::string task4(int n, int ***kub)
    {

        // диагонали: главная(левый верхний передний)
        int summain = 0;
        for (int i = 0; i < n; ++i)
        {
            summain += kub[i][i][i];
        }
        // printf("\nsummain=%d ", summain);

        // диагонали: побочная 1(правый верхний передний)
        int j = n - 1, sum1 = 0;
        for (int i = 0; i < n; ++i)
        {
            sum1 += kub[i][j][i];
            --j;
        }
        // printf("\nsum1=%d ", sum1);

        // диагонали: побочная 2(правый верхний задний)
        int k = n - 1, sum2 = 0;
        for (int i = 0; i < n; ++i)
        {
            sum2 += kub[i][k][k];
            --k;
        }
        // printf("\nsum2=%d ", sum2);

        // диагонали: побочная 3(левый верхний задний)
        int l = n - 1, sum3 = 0;
        for (int i = 0; i < n; ++i)
        {
            sum3 += kub[i][i][l];
            --l;
        }
        // printf("\nsum3=%d ", sum3);

        std::ostringstream output;
        if (summain > sum1 && summain > sum2 && summain > sum3)
            output << "\nСумма элементов диагонали из лвого переднего верхнего угла максимальная";
        else if (sum1 > summain && sum1 > sum2 && sum1 > sum3)
            output << "\nСумма элементов диагонали из правого переднего верхнего угла максимальная";
        else if (sum2 > summain && sum2 > sum1 && sum2 > sum3)
            output << "\nСумма элементов диагонали из правого заднего верхнего угла максимальная";
        else if (sum3 > summain && sum3 > sum1 && sum3 > sum2)
            output << "\nСумма элементов диагонали из левого заднего верхнего угла максимальная";
        else
            output << "\nЕсть равные значения сумм элементов диагоналей";


        return output.str();
    }
}

TEST(AdditionTest, HandlesAllTheSame)
{
    int ***array = new int **[3];
    for (int i = 0; i < 3; ++i)
    {
        array[i] = new int *[3];
        for (int j = 0; j < 3; ++j)
        {
            array[i][j] = new int[3];
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                array[i][j][k] = 2;
            }
        }
    }

    EXPECT_EQ(task4(3, array), "\nЕсть равные значения сумм элементов диагоналей");
    //Очистка памяти
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
}
// Основная функция
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
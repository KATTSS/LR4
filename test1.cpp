#include <gtest/gtest.h>
#include <string>
#include <sstream>

std::string task1(int k, int *array, int sdvig)
{

    for (int i = 0; i < sdvig; ++i)
    {
        int prev;

        for (int j = k - 1; j > 0; --j)
        {
            prev = array[j];
            array[j] = array[j - 1];
            array[j - 1] = prev;
        }
    }

    // std::cout << "Массив после сдвига: ";
    std::ostringstream output;
    for (int i = 0; i < k; ++i)
    {
        output << array[i] << " ";
    }

    return output.str();
}

// Тестовый случай для функции
TEST(AdditionTest, HandlesPositiveInputs)
{
    int array[4] = {1, 2, 3, 4};
    EXPECT_EQ(task1(4, array, 1), "4 1 2 3 ");
}
TEST(AdditionTest, HandlesBiggerSdvig)
{
    int array[8] = {120, 78, 1, 45, 0, 2, 4, 7};
    EXPECT_EQ(task1(8, array, 3), "2 4 7 120 78 1 45 0 ");
}

// Основная функция
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

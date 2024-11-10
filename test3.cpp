#include <gtest/gtest.h>
#include <string>
#include <sstream>

std::string task3(int n, float *a)
{
   
    float **matrix = new float *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new float[n];
    }

    // поиск минимального и маскимального значений
    float max = a[0];
    float min = a[0];
    for (int i = 0; i < n * n; ++i)
    {

        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

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
   

    float *sum = new float[n];
    std::ostringstream output;
    // вычисление скалярного произведения
    output << "Скалярное произведение равно: ";
    for (int k = 0; k < n; ++k)
    {
        sum[k] = matrix[imax][k] * matrix[k][jmin];
        output << sum[k] << " ";
    }

    //очистка памяти
    // for (int i = 0; i < n; ++i)
    // {
    //     delete[] matrix[i]; // Удаление строк
    // }
    // delete[] matrix; // Удаление массива указателей
    // delete[] sum;
    return output.str();
}

TEST(AdditionTest, HandlesCount)
{
    float array[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    EXPECT_EQ(task3(4, array), "Скалярное произведение равно: 13 70 135 208 ");
}
TEST(AdditionTest, HandlesCountPointable)
{
    float array[4] = {0.5,4,18,0.7};
    EXPECT_EQ(task3(2, array), "Скалярное произведение равно: 9 12.6 ");
}
// Основная функция
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

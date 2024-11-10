#include <gtest/gtest.h>
#include <string>
#include <sstream>

// Объявление функции task2
std::string task2(int n, int m, int **matrix){

    int min = matrix[1][m - 1];

    for (int i = 1; i <= n - 1; ++i) {
        for (int j = m - 1; j >= m - i; --j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    std::ostringstream output;
    output << "min = " << min;
    return output.str();
}


TEST(AdditionTest, HandlesPositiveInputs) {
    int n = 4, m = 4;
    int** array = new int*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[m];
    }

    int initArray[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array[i][j] = initArray[i][j];
        }
    }

    EXPECT_EQ(task2(n, m, array), "min = 8");

    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

TEST(AdditionTest, HandlesNegative) {
    int n = 4, m = 4;
    int** array = new int*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[m];
    }

    int initArray[4][4] = {
        {8, 3, 1, 2},
        {0, 15, 36, 4},
        {3, -2, 40, -1},
        {0, 16, 2, 8}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array[i][j] = initArray[i][j];
        }
    }

    EXPECT_EQ(task2(n, m, array), "min = -1");

    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

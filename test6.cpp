#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

extern "C" {
    std::string task6(int n);
    int chetny(int n, int **square);
    int nechetny(int n, int **square, int rad, int stolbik, int num);
    int other(int **square, int n);
    void freemem(int **square, int n);
    std::string printsq(int **square, int n);

    std::string task6(int n)
    {
        std::ostringstream output;
        // проверка на существование
        if (n == 1) {
            output << "1";
            return output.str();
        }
        if (n < 3 && n != 1) {
            output << "NO";
            return output.str();
        }

        // создание массива с нулями для заполнения элементами
        int **square = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; ++i) {
            square[i] = (int *)calloc(n, sizeof(int));
        }

        if ((n - 2) % 4 == 0) {
            other(square, n);
        } else if (n % 4 == 0) {
            chetny(n, square);
        } else {
            nechetny(n, square, 0, n / 2, 1);
        }

        output << printsq(square, n);
        freemem(square, n);

        return output.str();
    }

    int chetny(int n, int **square)
    {
        int num = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                square[i][j] = num++;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3)) {
                    square[i][j] = n * n + 1 - square[i][j];
                }
            }
        }

        return 0;
    }

    int nechetny(int n, int **square, int rad, int stolbik, int num)
    {
        while (num <= n * n) {
            square[rad][stolbik] = num++;

            stolbik++;
            rad--;

            if (rad == -1 && stolbik == n) {
                rad += 2;
                stolbik--;
            }
            if (rad < 0) {
                rad = n - 1;
            }
            if (stolbik == n) {
                stolbik = 0;
            }
            if (square[rad][stolbik]) {
                rad += 2;
                stolbik--;
            }
        }

        return 0;
    }

    int other(int **square, int n)
    {
        int halfN = n / 2;
        int **subSquare = (int **)calloc(halfN, sizeof(int *));
        for (int i = 0; i < halfN; ++i) {
            subSquare[i] = (int *)calloc(halfN, sizeof(int));
        }

        nechetny(halfN, subSquare, 0, halfN / 2, 1);

        for (int i = 0; i < halfN; ++i) {
            for (int j = 0; j < halfN; ++j) {
                square[i][j] = subSquare[i][j];
                square[i][j + halfN] = subSquare[i][j] + 2 * halfN * halfN;
                square[i + halfN][j + halfN] = subSquare[i][j] + halfN * halfN;
                square[i + halfN][j] = subSquare[i][j] + 3 * halfN * halfN;
            }
        }

        for (int i = 0; i < halfN; ++i) {
            for (int j = 0; j < halfN / 2; ++j) {
                if (i == halfN / 2) {
                    int temp = square[i][j + 1];
                    square[i][j + 1] = square[i + halfN][j + 1];
                    square[i + halfN][j + 1] = temp;
                } else {
                    int temp = square[i][j];
                    square[i][j] = square[i + halfN][j];
                    square[i + halfN][j] = temp;
                }
            }
        }

        for (int i = 0; i < halfN; ++i) {
            for (int j = halfN + halfN / 2 + 2; j < n; ++j) {
                int temp = square[i][j];
                square[i][j] = square[i + halfN][j];
                square[i + halfN][j] = temp;
            }
        }

        freemem(subSquare, halfN);

        return 0;
    }

    void freemem(int **square, int n)
    {
        for (int i = 0; i < n; ++i) {
            free(square[i]);
        }
        free(square);
    }

    std::string printsq(int **square, int n)
    {
        std::ostringstream output;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                output << std::setw(5) << square[i][j] << " ";
            }
            output << "\n";
        }
        return output.str();
    }
}

TEST(TestingSquare, TestForOne) {
    EXPECT_EQ(task6(1), "1");
}
TEST(TestingSquare, TestForTwo) {
    EXPECT_EQ(task6(2), "NO");
}
TEST(TestingSquare, TestForThree) {
    EXPECT_EQ(task6(3), "    8     1     6 \n    3     5     7 \n    4     9     2 \n");
}
TEST(TestingSquare, TestForFour) {
    EXPECT_EQ(task6(4), "   16     2     3    13 \n    5    11    10     8 \n    9     7     6    12 \n    4    14    15     1 \n");
}
TEST(TestingSquare, TestForSix) {
    EXPECT_EQ(task6(6), "   35     1     6    26    19    24 \n    3    32     7    21    23    25 \n   31     9     2    22    27    20 \n    8    28    33    17    10    15 \n   30     5    34    12    14    16 \n    4    36    29    13    18    11 \n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
# Укажите минимально необходимую версию CMake
cmake_minimum_required(VERSION 3.10)

# Название вашего проекта
project(LR4)

# Установите стандарт C++
set(CMAKE_CXX_STANDARD 11)

# Добавьте поддиректорию, где находится Google Test
# Путь к googletest должен быть указан правильно
add_subdirectory(googletest)

# Укажите исходные файлы вашего проекта
# Подключите библиотеки Google Test к вашему проекту

add_executable(Tests1 test1.cpp)
target_link_libraries(Tests1 gtest gtest_main)

add_executable(Tests2 test2.cpp)
target_link_libraries(Tests2 gtest gtest_main)

add_executable(Tests3 test3.cpp)
target_link_libraries(Tests3 gtest gtest_main)

add_executable(Tests4 test4.cpp)
target_link_libraries(Tests4 gtest gtest_main)

add_executable(Tests6 test6.cpp)
target_link_libraries(Tests6 gtest gtest_main)

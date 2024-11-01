#include <iostream>
int sum (int x, int y) {
    return x+y;
}
int add (int x, int y) {
    return x+y+2;
}
int main () {
    int (*a[2])(int, int);
    a[0]=sum;
    a[1]=add;
    std::cout << a[0](5,6) << " " << a[1](4,8);
    return 0;
}
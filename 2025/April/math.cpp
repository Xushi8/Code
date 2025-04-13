#include <cmath>
#include <iostream>
int main()
{
    double x = 3.9;
    double y = 5.9;
    std::cout << atan(y / x) << ' ' << atan2(y, x) << '\n';
}
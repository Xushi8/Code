#include <iostream>

int func1(int val, int m, int dec)
{
    return (val - m + 1 + (dec - 1)) / dec;
}

int func2(int val, int m, int dec)
{
    return (val - m + (dec - 1)) / dec + ((val - m) % dec == 0);
}

int main()
{
    using namespace std;
    int val = 3;
    int m = 2;
    int dec = 1;
}
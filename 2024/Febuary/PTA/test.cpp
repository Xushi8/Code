#include <iostream>
#include <memory>
using namespace std;

bool isLucky(int number) noexcept; // 原始版本
bool isLucky(char) = delete;       // 拒绝char
bool isLucky(bool) = delete;       // 拒绝bool
bool isLucky(double) = delete;     // 拒绝float和double

bool isLucky(int a) noexcept
{
    return a & 1;
}

struct free_deleter
{
    void operator()(void* p) noexcept
    {
        free(p);
    }
};

int main()
{
    int a = 5;
    int* b = &a;
    advance(b, 3);

    cout << isLucky(2) << endl;

    unique_ptr<int, free_deleter> p((int*)malloc(sizeof(int)));


    int i = 0x7fffffff;
    i++;

    int* p1 = nullptr;
    cout << *p1 << endl;

    cout << "klsd" << endl;

    return 0;
}
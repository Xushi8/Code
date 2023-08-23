// 2023/08/22 10:31:09
#include <iostream>
#include <cstdio>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;


constexpr long long func(int n)
{
    long long ret = 0;
    for (int i = 0; i <= n; i++)
    {
        ret += i;
    }

    return ret;
}

void func1(int* __restrict a, int* __restrict b, int* __restrict c)
{
    *c = *b;
    *c = *a;
}

void func2(int* a)
{
    a[0] = 1;
    a[1] = 2;
    a[2] = 2;
    a[3] = 2;
    a[4] = 2;
    a[5] = 2;
    a[6] = 2;
    a[7] = 2;
}

void func3(int* __restrict a, int* __restrict b)
{
#pragma omp simd
    for (int i = 0; i < 16 * 1024; i++)
    {
        a[i] = b[i] + 5;
    }
}

void func4(int* a, int n)
{
    n = n / 4 * 4;
#pragma omp simd
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

void func5(float a, const float* __restrict x, const float* __restrict y, float* __restrict z, size_t n)
{
    
#pragma omp simd
    for (size_t i = 0; i < n; i++)
    {
        z[i] = a * x[i] + y[i];
    }
}

size_t func6(const float* x, size_t n, float y)
{
    size_t ret = 0;
#pragma omp simd
    for (size_t i = 0; i < n; i++)
    {
        ret += x[i] > y;
    }
    return ret;
}

void func7(float* x, size_t n)
{
#pragma omp simd
    for (size_t i = 0; i < n; i++)
    {
        x[i] = sinf((float)i);
    }
}

int main()
{

    printf("%lld\n", func(1000000000));

    int a = 10, b = 20, c = 30;
    func1(&a, &b, &c);

    cout << abs(1.4f) << '\n';

    return 0;
}
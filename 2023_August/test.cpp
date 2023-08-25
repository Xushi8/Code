// 2023/08/22 10:31:09
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>
#include <cmath>
#include <memory>
#include <string>
#include <cstring>

#if defined(_MSC_VER)
     /* Microsoft C/C++-compatible compiler */
#include <intrin.h>
#elif defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__))
     /* GCC-compatible compiler, targeting x86/x86-64 */
#include <x86intrin.h>
#elif defined(__GNUC__) && defined(__ARM_NEON__)
     /* GCC-compatible compiler, targeting ARM with NEON */
#include <arm_neon.h>
#elif defined(__GNUC__) && defined(__IWMMXT__)
     /* GCC-compatible compiler, targeting ARM with WMMX */
#include <mmintrin.h>
#elif (defined(__GNUC__) || defined(__xlC__)) && (defined(__VEC__) || defined(__ALTIVEC__))
     /* XLC or GCC-compatible compiler, targeting PowerPC with VMX/VSX */
#include <altivec.h>
#elif defined(__GNUC__) && defined(__SPE__)
     /* GCC-compatible compiler, targeting PowerPC with SPE */
#include <spe.h>
#endif

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
#pragma omp simd
    for (int i = 0; i < 8 * 1024; i += 8)
    {
        a[0 + i] = 1;
        a[1 + i] = 2;
        a[2 + i] = 2;
        a[3 + i] = 2;
        a[4 + i] = 2;
        a[5 + i] = 2;
        a[6 + i] = 2;
        a[7 + i] = 2;
    }
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

void func8(std::vector<int>& a, const std::vector<int>& b)
{
#pragma omp simd
    for (size_t i = 0; i < a.size(); i++)
    {
        a[i] = b[i] + 10;
    }
}

constexpr long long fib(size_t n)
{
    if (n <= 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    printf("%lld\n", func(1000000000));

    printf("%lld\n", fib(50));

    return 0;
}
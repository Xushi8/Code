// #include<stdio.h>
// #include<iostream>
// #include<deque>
// #include <fstream>
// using namespace std;

// deque<int> de;

// int main() {
//     int n, a, b;
//     ifstream ifs("pour.in");
//     ofstream ofs("pour.out");
//     // scanf("%d%d%d", &n, &a, &b);
//     ifs >> n >> a >> b;
//     int flag = 2;
//     for (int i = 0;i < n;i++) {
//         de.push_back(a);
//     }
//     int count = 0;
//     while (de.size() != 1) {
//         int num1, num2;
//         num1 = de.front();
//         de.pop_front();
//         num2 = de.front();
//         de.pop_front();
//         if (num1 + num2 > b) {
//             // printf("%d\n", flag);
//             ofs << flag << '\n';
//             count = 1;
//             break;
//         }
//         else {
//             if (flag == 1) {
//                 flag = 2;
//             }
//             else {
//                 flag = 1;
//             }
//             de.push_back(num1 + num2);
//         }
//     }
//     if (de.size() == 1 && count == 0) {
//         // printf("%d\n", flag);
//         ofs << flag << '\n';
//     }

//     ifs.close();
//     ofs.close();

//     return 0;
// }


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
#include <chrono>
using namespace std;

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

void func1(const int* a, const int* b, int* __restrict c)
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

void func9(float* a)
{
    #pragma GCC unroll 16
    for (size_t i = 0; i < 1024; i++)
    {
        a[i] = 1;
    }
}

void func10()
{
    auto t0 = chrono::steady_clock::now();
    for (volatile size_t i = 0; i < 10000000000; i++) {}
    auto t1 = chrono::steady_clock::now();
    auto dt = t1 - t0;
    int64_t used_time = chrono::duration_cast<chrono::milliseconds>(dt).count();
    cout << "Time elapsed: " << used_time << "ms" << endl;
}

void func11(int* a)
{
    for (int i = 0; i < 128; i++)
    {
        a[i] = 0;
    }
}

constexpr long long fib(size_t n)
{
    if (n <= 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}


constexpr size_t n = 3000000000;
int arr[n];

int main()
{
    // printf("%lld\n", func(1000000000));

    // printf("%lld\n", fib(12));

#pragma omp simd
    for (volatile size_t i = 0; i < n; i += 1)
    {
        arr[i] = 13093198;
    }

    time_t use_time = clock();
    cout << "memory speed: " << (n * sizeof(int)) / (use_time * 1000.0) << "gb/s" << endl;


    // func10();

    cerr << "Time elapsed: " << use_time / 1000 << "ms" << endl;
    return 0;
}
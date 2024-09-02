#include <algorithm>
#include <cstddef>
#include <random>
#include <vector>
#include <chrono>
#include <fmt/format.h>
using fmt::print;
using namespace std;

template <typename F>
std::chrono::duration<double, std::milli> time_test(F&& f)
{
    auto first = std::chrono::steady_clock::now();
    f();
    auto last = std::chrono::steady_clock::now();
    return last - first;
}

using float_type = double;
using int_type = uint64_t;

__attribute__((noinline)) void float_div(float_type* a, size_t n, float_type x)
{
    for (size_t i = 0; i < n; i++)
    {
        a[i] /= x;
    }
}

__attribute__((noinline)) void int_div(int_type* a, size_t n, int_type x)
{
    for (size_t i = 0; i < n; i++)
    {
        a[i] /= x;
    }
}

int main()
{
    constexpr size_t n = 10000000;
    mt19937 rng(random_device{}());
    vector<float_type> a(n);
    vector<int_type> b(n);
    uniform_real_distribution<float_type> unf(-1e9, 1e9);
    uniform_int_distribution<int_type> uni;
    generate_n(a.begin(), n, [&]
        {
            return unf(rng);
        });
    generate_n(b.begin(), n, [&]
        {
            return uni(rng);
        });

    float_type x = unf(rng);
    while (abs(x - 0) < 1e-6)
        x = unf(rng);
    auto time_use = time_test([&]
        {
            float_div(a.data(), n, x);
        });
    print("float div: {:.3f}ms\n", time_use.count());
    time_use = time_test([&]
        {
            int_div(b.data(), n, x);
        });
    print("int div: {:.3f}ms\n", time_use.count());

    print("{} {}\n", a[(uni(rng) % n + n) % n], b[(uni(rng) % n + n) % n]);
}
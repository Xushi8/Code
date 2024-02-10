#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <cstdint>
#include <climits>
#include <numeric>
using namespace std;

template <class T, class ...Args>
unique_ptr<T> func(Args...args)
{
    return unique_ptr<T>(new T(args...));
}

int main()
{
    random_device seed;
    mt19937 rng(seed());
    uniform_int_distribution<uint64_t> uni(0, UINT64_MAX);
    constexpr size_t n = 100;
    for (size_t i = 0; i < n; i++)
    {
        // cout << uni(rng) << '\n';
    }

    normal_distribution<double> nd(0, 1);
    for (size_t i = 0; i < n; i++)
    {
        // cout << nd(rng) << '\n';
    }

    vector<float> gailv = {0.5, 0.2, 0.1, 0.2};
    vector<float> gailv_scanned;
    inclusive_scan(gailv.begin(), gailv.end(), back_inserter(gailv_scanned));
    for (auto x : gailv_scanned)
    {
        cout << x << ' ';
    }
    vector<string> lian = {"mushi", "she", "enlosi", "wuya"};
    uniform_real_distribution<float> unf(0, 1);

    auto get_lian = [&]() -> string
    {
        auto it = lower_bound(gailv_scanned.begin(), gailv_scanned.end(), unf(rng));
        return lian[it - gailv_scanned.begin()];
    };

    for (size_t i = 0; i < n; i++)
    {
        cout << get_lian() << '\n';
    }
}
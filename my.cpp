#include <algorithm>
#include <random>
#include <vector>
#include <thread>
#include <mutex>
#include <fstream>
#include <numeric>
#include <format>
#include <iostream>

static constexpr double min_value = 0.0;
static constexpr double max_value = 1e9;

// [l, r)
std::pair<size_t, size_t> get_neighbor_random(size_t l, size_t r)
{
    thread_local std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> uni(l, r - 1);
    while (1)
    {
        size_t x = uni(rng);
        size_t y = uni(rng);
        if (x != y)
        {
            return std::make_pair(x, y);
        }
    }
}

std::pair<size_t, std::vector<double>> iteration(size_t node_size)
{
    std::vector<std::mutex> mutexs(node_size);
    std::vector<double> values(node_size);
    std::mt19937 rng(std::random_device{}());
    auto check = [&](size_t iteration_count)
    {
        std::uniform_real_distribution<double>
            und(min_value, max_value);
        std::generate_n(values.begin(), values.size(), [&]
            { return und(rng); });

        static const size_t thread_num = std::thread::hardware_concurrency();
        std::vector<std::jthread> threads;
        threads.reserve(thread_num);
        for (size_t i = 0; i < thread_num; i++)
        {
            threads.emplace_back(
                [&mutexs, &values, iteration_count]
                {
                    const size_t cnt = iteration_count / thread_num; // 每个线程迭代次数
                    for (size_t j = 0; j < cnt; j++)
                    {
                        auto [x, y] = get_neighbor_random(0, values.size());
                        std::scoped_lock lock(mutexs[x], mutexs[y]);
                        double average = std::midpoint(values[x], values[y]);
                        values[x] = values[y] = average;
                    }
                });
        }

        threads.clear(); // std::jthread 析构时会 join

        double average = std::reduce(values.begin(), values.end()) / values.size();
        double variance = std::transform_reduce(values.begin(), values.end(), 0., std::plus<>(), [&](double val)
            { return (val - average) * (val - average); });

        std::cerr << std::format("{}\n", variance);
        return variance < 1e-2; // 方差小于 1e-3 记为收敛
    };

    size_t l = node_size, r = node_size, ans = node_size;
    while (!check(r))
    {
        l = r;
        r *= 2;
        std::cerr << "node_size = " << node_size << " r = " << r << '\n';
    }
    
    while (l <= r)
    {
        size_t mid = l + (r - l) / 2;
        std::cerr << mid << '\n';
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return std::pair{ans, values};
}

int main(int argc, char** argv)
{
    std::ofstream ofs("data.txt");
    for (size_t node_size = 128; node_size < static_cast<size_t>(1e6); node_size *= 2)
    {
        std::cerr << node_size << '\n';
        auto [count, values] = iteration(node_size);
        ofs << node_size << ' ' << count << '\n';
        using namespace std::string_literals;
        if (argc == 2 && argv[1] == "--print"s)
        {
            for (auto x : values)
            {
                ofs << std::format("{} ", x);
            }
            ofs << '\n';
        }
    }
}
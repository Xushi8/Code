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
static constexpr double eps = 1e-3;
static constexpr size_t fixed = 1e4; // 对于 k 值与收敛次数的关系对比, 这里使用固定值

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

// [l, r)
std::pair<size_t, size_t> get_neighbor_k(size_t l, size_t r, double k)
{
    thread_local std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> uni(l, r - 1);
    std::uniform_real_distribution<double> dist(0, 1);
    static std::mutex mtx;

    // 下面的几个 static 变量为共有的资源, 因此不能使用thread_local, 加锁确保正确性
    static double old_k{};
    static std::array<std::array<double, fixed>, fixed> weights; // 权重

    {
        std::scoped_lock lock(mtx);
        if (std::abs(old_k - k) > 1e-6) // 更换了 k 值
        {
            old_k = k;
            for (size_t i = 0; i < fixed; i++)
            {
                weights[i].fill(1.0);
                weights[i][i] = 0.0;
            }
        }
    }

    size_t x = uni(rng);
    size_t y = SIZE_MAX;
    double total_weight = std::reduce(weights[x].begin(), weights[x].end());
    double target = total_weight * dist(rng);

    double sum_weight = 0.0;
    for (size_t i = 0; i < fixed; i++)
    {
        sum_weight += weights[x][i];
        if (sum_weight >= target)
        {
            y = i;
            break;
        }
    }

    if (y == SIZE_MAX) [[unlikely]]
    {
        if (x == 0)
            y = fixed - 1;
        else
            y = 0;
    }

    weights[x][y] *= k;
    return std::pair{x, y};
}

std::pair<size_t, std::vector<double>> iteration(size_t node_size, size_t begin_count, size_t add_count, double k = 0.0)
{
    std::vector<std::mutex> mutexs(node_size);
    std::vector<double> values(node_size);
    std::mt19937 rng(std::random_device{}());
    size_t iteration_count;
    for (iteration_count = begin_count;; iteration_count += add_count)
    {
        std::uniform_real_distribution<double> und(min_value, max_value);
        std::generate_n(values.begin(), values.size(), [&]
            { return und(rng); });

        static const size_t thread_num = std::thread::hardware_concurrency();
        std::vector<std::jthread> threads;
        threads.reserve(thread_num);
        for (size_t i = 0; i < thread_num; i++)
        {
            threads.emplace_back(
                [&mutexs, &values, iteration_count, k]
                {
                    const size_t cnt = iteration_count / thread_num; // 每个线程迭代次数
                    for (size_t j = 0; j < cnt; j++)
                    {
                        std::pair<size_t, size_t> neighbor;
                        if (k == 0.0)
                        {
                            neighbor = get_neighbor_random(0, values.size());
                        }
                        else
                        {
                            neighbor = get_neighbor_k(0, values.size(), k);
                        }
                        std::scoped_lock lock(mutexs[neighbor.first], mutexs[neighbor.second]);
                        double average = std::midpoint(values[neighbor.first], values[neighbor.second]);
                        values[neighbor.first] = values[neighbor.second] = average;
                    }
                });
        }

        threads.clear(); // std::jthread 析构时会 join

        double average = std::reduce(values.begin(), values.end()) / values.size();
        double variance = std::transform_reduce(values.begin(), values.end(), 0., std::plus<>(), [&](double val)
            { return (val - average) * (val - average); });

        if (variance < eps) // 方差小于 eps 记为收敛
        {
            break;
        }
    }

    return std::pair{iteration_count, values};
}

int main(int argc, char** argv)
{
    std::ofstream ofs("data_random.txt");
    // for (size_t node_size = 100; node_size < static_cast<size_t>(1e6); node_size *= 1.5)
    // {
    //     auto [count, values] = iteration(node_size, node_size * 40, node_size / 10);
    //     ofs << node_size << ' ' << count << std::endl;
    //     using namespace std::string_literals;
    //     if (argc == 2 && argv[1] == "--print"s)
    //     {
    //         for (auto x : values)
    //         {
    //             ofs << std::format("{} ", x);
    //         }
    //         ofs << '\n';
    //     }
    // }

    ofs.close();
    ofs.open("data_k.txt");
    for (double k = 1.0; k > 0.01; k -= 0.01)
    {
        static constexpr size_t node_size = fixed;
        auto [count, values] = iteration(node_size, node_size, node_size / 10, k);

        ofs << node_size << ' ' << count << std::endl;
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
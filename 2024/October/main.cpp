#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

// 随机选择邻居的辅助函数
int getRandomNeighbor(int currentNode, int nodeCount)
{
    static std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<> dist(0, nodeCount - 1);

    int neighbor;
    do
    {
        neighbor = dist(gen); // 确保邻居不是当前节点
    } while (neighbor == currentNode);

    return neighbor;
}

// 模拟 Gossip 协议的平均数计算
void gossipAverage(std::vector<double>& values, int iterations)
{
    int nodeCount = values.size();

    for (int i = 0; i < iterations; ++i)
    {
        for (int node = 0; node < nodeCount; ++node)
        {
            // 随机选择一个邻居节点
            int neighbor = getRandomNeighbor(node, nodeCount);

            // 使用 std::midpoint 计算中点值
            double avg = std::midpoint(values[node], values[neighbor]);

            // 更新两个节点的值
            values[node] = avg;
            values[neighbor] = avg;
        }
    }
}

int main()
{
    // 初始化节点值
    std::vector<double> values = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0};
    int iterations = 3; // 迭代次数

    std::cout << "Initial values: ";
    for (const auto& v : values)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 模拟 Gossip 协议
    gossipAverage(values, iterations);

    std::cout << "Final values after gossip: ";
    for (const auto& v : values)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 计算最终的平均数
    double realAverage = std::reduce(values.begin(), values.end()) / values.size();

    double piancha = std::transform_reduce(values.begin(), values.end(), 0.0, std::plus<>(), [&](double x)
                         { return (realAverage - x) * (realAverage - x); })
                     / values.size();

    std::cout << "Global average: " << realAverage << std::endl;
    std::cout << "方差: " << piancha << std::endl;

    return 0;
}

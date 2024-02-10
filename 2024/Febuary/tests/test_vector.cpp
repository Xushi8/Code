#include <chrono>
#include <functional>
#include <iostream>
#include <vector>
int const num = 1000000000;
struct AdItem
{
    AdItem()
    {
    }
    AdItem(int x, int y, int z)
    {
        x_ = x;
        y_ = y;
        z_ = z;
    }
    int x_;
    int y_;
    int z_;
};
void time_report(const std::function<void()>& f1, const std::function<void()>& f2)
{
    auto start = std::chrono::high_resolution_clock::now();
    f1();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "allocation done in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    f2();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "assignment done in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
}
void uninitialized_performance()
{
    std::vector<AdItem> v;
    time_report([&v]()
        { v.resize(num); },
        [&v]()
        {
                   for (int i = 0; i < num; ++i) {
                     v[i] = {i + 2, i + 4, i + 6};
                   } });
}
void initialized_performance()
{
    std::vector<AdItem> v;
    time_report([&v]()
        { v.assign(num, AdItem{0, 0, 0}); },
        [&v]()
        {
                   for (int i = 0; i < num; ++i) {
                     v[i] = {i + 2, i + 4, i + 6};
                   } });
}
int main()
{
    uninitialized_performance();
    initialized_performance();
    return 0;
}
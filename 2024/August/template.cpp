#include <fmt/format.h>
#include <iostream>
#include <thread>
using fmt::print;

template <typename... Ts>
void func(Ts&&... ts)
{
    print("\n", std::forward<Ts>(ts)...);
    auto print_with_sapce = [](auto&& t)
    {
        std::cout << std::forward<decltype(t)>(t) << ' ';
    };
    (..., print_with_sapce(std::forward<Ts>(ts)));
    std::thread::hardware_concurrency();
}

struct A
{
    static int x;
    static inline int y = 999;
    static int get_x() noexcept
    {
        return x;
    }

    static int get_y() noexcept
    {
        return y;
    }

    static void set_x(int val) noexcept
    {
        x = val;
    }

    static void set_y(int val) noexcept
    {
        y = val;
    }

    const static int z;
};

int A::x = 123982319;
const int A::z = 123;

int main()
{
    func(1, 2, 3);
    func(1, "dsalkjkl", 34342.4);
}
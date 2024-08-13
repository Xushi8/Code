#include <boost/container/vector.hpp>
#include <iostream>
#include <vector>
using namespace std;
struct default_init_t
{
};
inline constexpr default_init_t default_init;

struct A
{
    int x;
    A() :
        x()
    {
        cout << "值初始化" << '\n';
    }
    A(default_init_t)
    {
        cout << "默认初始化" << '\n';
    }
};

void func()
{
    constexpr size_t n = 10;
    std::vector<A> a(n, default_init);
}

int main()
{
    constexpr size_t n = 1000000;
    std::vector<A> a(n, default_init);
    // boost::container::vector<A> a(n, default_init);
    // boost::container::vector<A> a(n, boost::container::default_init);
    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i].x != 0)
        {
            cnt++;
            cout << a[i].x << '\n';
        }
    }
    cout << cnt << '\n';
}
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
    int m_x;
    A() :
        m_x()
    {
        cout << "值初始化" << '\n';
    }

    A(default_init_t)
    {
        cout << "默认初始化" << '\n';
    }

    A(int x) :
        m_x(x)
    {
        cout << "直接初始化" << '\n';
    }

    A(A const& that) :
        m_x(that.m_x)
    {
        cout << "A const&" << '\n';
    }

    A(A&& that) noexcept :
        m_x(std::move(that.m_x))
    {
        cout << "A&&" << '\n';
    }

    A& operator=(A const& that)
    {
        m_x = that.m_x;
        cout << "operator= const&" << '\n';
        return *this;
    }

    A& operator=(A&& that) noexcept
    {
        m_x = that.m_x;
        cout << "operator= &&" << '\n';
        return *this;
    }
};

void func()
{
    constexpr size_t n = 10;
    std::vector<A> a(n, default_init);
}

int main()
{
    constexpr size_t n = 10;
    // std::vector<A> a(n, default_init);
    // boost::container::vector<A> a(n, default_init);
    boost::container::vector<A> a(n, boost::container::default_init);
    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i].m_x != 0)
        {
            cnt++;
            cout << a[i].m_x << '\n';
        }
    }
    cout << cnt << '\n';
}
#include <iostream>

inline int func(int p, int q, int r)
{
    return (p & q) | (r & (p ^ q));
}

int main()
{
    ::std::ios::sync_with_stdio(false);
    ::std::cin.tie(0);

    ::std::cout << "请输入要表决的三个数:" << ::std::endl;
    int p, q, r;
    ::std::cin >> p >> q >> r;
    ::std::cout << "表决结果为: " << func(p, q, r) << ::std::endl;

    ::std::cout << ::std::flush;
    return 0;
}




// 2023/06/27 11:01:43
#include <bits/stdc++.h>
using namespace std;

#pragma pack(1)

struct A
{
    int i[4];
    char a;
    long double o;
};

using ll = long long;
using ull = unsigned long long;

int func()
{
    for (int i = 0; i < 1000; i++)
    {
        if (i == 390)
            return i;
    }


    return 0; // 避免警告
}

ll lem(ll m, ll n)
{
    return m * n / __gcd(m, n);
}

const long double PI = 3.1415926535897932384626433832795L;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cout << sizeof(size_t) << '\n';
    cout << sizeof(::std::size_t) << '\n';
    cout << sizeof(void*) << '\n';
    cout << sizeof(ll) << '\n';
    cout << sizeof(ull) << '\n';
    cout << (1LL << 22) << '\n';
    cout << sizeof(1 + 1 == 2) << '\n' << '\n';

    // int sum = 0;
    // for (int i = 1; i <= 1000; i++)
    // {
    //     if (i % 5 && i % 6 && i % 8)
    //     {
    //         sum++;
    //     }
    // }
    // cout << sum << '\n';

    ll A5 = (ll)2e18 / 5;
    ll A6 = (ll)2e18 / 6;
    ll A8 = (ll)2e18 / 8;
    ll A56 = (ll)2e18 / lem(5, 6);
    ll A58 = (ll)2e18 / lem(5, 8);
    ll A68 = (ll)2e18 / lem(6, 8);
    ll A568 = (ll)2e18 / lem(lem(5, 6), 8);
    cout << (ll)2e18 - (A5 + A6 + A8 - A56 - A58 - A68 + A568) << '\n';

    cout << tan(PI) << '\n';
    cout << sin(PI) << '\n';
    cout << cos(PI) << '\n';

    cout << flush;
    return 0;
}
// 2023/10/22 19:57:04
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

struct A
{
    int l, r;
    A(int a, int b)
    {
        l = a;
        r = b;
    }
};

bool operator<(A a, A b)
{
    if (a.l != b.l)
        return a.l < b.l;
    else
        return a.r < b.r;
}

struct B
{
    int l, r;
    B(int a, int b)
    {
        l = a;
        r = b;
    }
};

bool operator<(B a, B b)
{
    if (a.r != b.r)
        return a.r < b.r;
    else
        return a.l > b.l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    multiset<A> st1;
    multiset<B> st2;
    while (q--)
    {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        if (ch == '+')
        {
            st1.emplace(l, r);
            st2.emplace(l, r);
        }
        else
        {
            st1.erase(st1.find({ l, r }));
            st2.erase(st2.find({ l, r }));
        }

        if (st1.empty())
        {
            cout << "NO\n";
            continue;
        }

        auto it1 = --st1.end();
        auto it2 = st2.begin();
        cout << (it2->r < it1->l ? "YES\n" : "NO\n");
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
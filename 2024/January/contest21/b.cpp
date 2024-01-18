// 2024/01/17 10:22:46
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
    ll be, k, b;
    A(ll x, ll y, ll z)
    {
        be = x, k = y, b = z;
    }
};

bool operator<(A const& x, A const& y)
{
    return x.be < y.be;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<A> arr;
    while (q--)
    {
        char ch;
        ll L, R;
        cin >> ch >> L >> R;
        if (ch == 'R')
        {
            arr.emplace_back(L, 0, 1);
            arr.emplace_back(R + 1, 0, -1);
        }
        else if (ch == 'D')
        {
            arr.emplace_back(L, 0, -1);
            arr.emplace_back(R + 1, 0, 1);
        }
        else if (ch == 'H')
        {
            ll mid = (L + R) / 2;
            arr.emplace_back(L, 1, -(L - 1));
            arr.emplace_back(mid + 1, -1, (L - 1));
            arr.emplace_back(mid + 1, -1, (R + 1));
            arr.emplace_back(R + 1, 1, -(R + 1));
        }
        else
        {
            ll mid = (L + R) / 2;
            arr.emplace_back(L, -1, (L - 1));
            arr.emplace_back(mid + 1, 1, -(L - 1));
            arr.emplace_back(mid + 1, 1, -(R + 1));
            arr.emplace_back(R + 1, -1, (R + 1));
        }
    }

    sort(arr.begin(), arr.end());

    size_t now = 0;
    ll k = 0, b = 0;
    for (ll x = 1; x <= n; x++)
    {
        while (now < arr.size() && arr[now].be <= x)
        {
            k += arr[now].k;
            b += arr[now].b;
            now++;
        }
        cout << k * x + b << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
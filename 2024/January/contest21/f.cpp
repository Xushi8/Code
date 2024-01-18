// 2024/01/16 16:04:39
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
constexpr int N = 100005;
constexpr ll MOD = ll(1e9 + 7);

vector<vector<ll>> operator*(vector<vector<ll>> const& a, vector<vector<ll>> const& b)
{
    vector<vector<ll>> c(a.size(), vector<ll>(b[0].size(), 0));
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < b[0].size(); j++)
        {
            for (size_t k = 0; k < b.size(); k++)
            {
                c[i][j] += a[i][k] * b[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

vector<vector<ll>> fast_pow(vector<vector<ll>> a, size_t n)
{
    vector<vector<ll>> b(a.size(), vector<ll>(a[0].size()));
    for (size_t i = 0; i < a.size(); i++)
    {
        b[i][i] = 1;
    }

    while (n)
    {
        if (n & 1) b = b * a;
        a = a * a;
        n /= 2;
    }
    return b;
}

vector<vector<ll>> get_n_matrix(size_t n)
{
    vector<vector<ll>> tmp;
    tmp.push_back({0, 1});
    tmp.push_back({1, 1});
    return fast_pow(tmp, n);
}

ll fib(size_t n)
{
    auto tmp = get_n_matrix(n);
    vector<vector<ll>> x;
    x.push_back({0});
    x.push_back({1});
    auto y = tmp * x;
    return y[0][0];
}

ll a[N];
vector<vector<ll>> arr[N];
ll k[N];

void build(int l, int r, int p)
{
    if (l == r)
    {
        vector<vector<ll>> x;
        x.push_back({fib(a[l])});
        x.push_back({fib(a[l + 1])});
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // for (size_t i = 1; i < 10; i++)
    // {
    //     cerr << i << ' ' << fib(i) << endl;
    // }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
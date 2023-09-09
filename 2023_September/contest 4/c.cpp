// 2023/09/09 17:55:41
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 100005;
constexpr ll mod = 998244353;

class edge
{
public:
    int to, cost;
};

vector<edge> G[N];

ll ans = 0;

struct A
{
    ll a, b, cnt;
};

A dp[N]; // 记录0和1的数量, 与自身能形成的对数

A dfs(int u)
{
    if (dp[u].a != -1)
    {
        ans += dp[u].cnt; ans %= mod;
        return dp[u];
    }

    A res = { 0, 0, 0 };
    for (auto [v, cost] : G[u])
    {
        if (cost == 0)
        {
            res.a++;
            res.cnt += res.b;
            res.cnt %= mod;
            ans += res.b;
            ans %= mod;
        }
        else
        {
            res.b++;
        }

        auto tmp = dfs(v);
        // swap(res, tmp);
        res.a += tmp.a;
        ans += res.b * tmp.a; ans %= mod;
        res.cnt += res.b * tmp.a + tmp.cnt;
        res.cnt %= mod;
        res.b += tmp.b;
    }

    return dp[u] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V;
    cin >> V;
    for (int i = 1; i <= V; i++)
    {
        int n;
        cin >> n;
        int to, cost;
        for (int j = 0; j < n; j++)
        {
            cin >> to >> cost;
            G[i].push_back({ to, cost });
        }
    }

    memset(dp, -1, sizeof(dp));
    dfs(1);

    // auto ret = dfs(1);

    // vector<int> sum(ret.size(), 0);
    // sum[0] = (ret[0] == 0);
    // for (size_t i = 1; i < ret.size(); i++)
    // {
    //     sum[i] = sum[i - 1] + (ret[i] == 0);
    // }

    // for (int i = 0; i < ret.size(); i++)
    // {
    //     cerr << ret[i] << ' ';
    // }




    // for (size_t i = 0; i < sum.size(); i++)
    // {
    //     if (ret[i] == 1)
    //     {
    //         if (i == 0)
    //             ans += sum.back() - sum[0];
    //         else
    //             ans += sum.back() - sum[i - 1];
    //         ans %= mod;
    //     }
    // }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
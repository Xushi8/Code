// 2024/09/28 17:45:08
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    priority_queue<pii, deque<pii>, less<>> que;
    for (int i = 0; i < m; i++)
    {
        que.emplace(a[i], i + 1);
    }

    vector<int> ans;
    int now = 0;
    int pre = -1;
    while (ans.size() < n)
    {
        auto [cnt, x] = que.top();
        que.pop();
        if (now == k && pre == x)
        {
            if (que.empty())
            {
                cout << -1 << '\n';
                return;
            }
            auto [cnt1, x1] = que.top();
            que.pop();
            ans.emplace_back(x1);
            cnt1--;
            if (cnt1 > 0)
                que.emplace(cnt1, x1);
            pre = x1;
            now = 1;
            que.emplace(cnt, x);
            continue;
        }

        if (ans.empty() || x == pre)
            now++;
        else
            now = 1;
        pre = x;
        ans.emplace_back(x);
        cnt--;
        if (cnt > 0)
            que.emplace(cnt, x);
    }

    for (auto x : ans)
    {
        cout << x << ' ';
    }
}
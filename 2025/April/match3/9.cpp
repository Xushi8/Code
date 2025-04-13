// 2025/04/13 19:00:02
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    deque<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    stack<int> he;
    vector<vector<int>> ans;

    vector<int> now;
    while (1)
    {
        if (now.size() == k)
        {
            ans.emplace_back(std::move(now));
            now.clear();
            continue;
        }

        if (he.empty() && a.empty())
        {
            if (!now.empty())
            {
                ans.emplace_back(std::move(now));
                now.clear();
            }
            break;
        }

        if (now.empty())
        {
            if (!he.empty())
            {
                now.emplace_back(he.top());
                he.pop();
            }
            else
            {
                now.emplace_back(a.front());
                a.pop_front();
            }

            continue;
        }

        if (!he.empty() && he.top() <= now.back())
        {
            now.emplace_back(he.top());
            he.pop();
            continue;
        }

        if (!a.empty() && a.front() <= now.back())
        {
            now.emplace_back(a.front());
            a.pop_front();
            continue;
        }

        bool ok = false;
        while (!a.empty() && he.size() < m)
        {
            he.emplace(a.front());
            a.pop_front();

            if (!a.empty() && a.front() <= now.back())
            {
                now.emplace_back(a.front());
                a.pop_front();
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            if (!now.empty())
            {
                ans.emplace_back(std::move(now));
                now.clear();
            }
        }
    }

    for (auto const& vec : ans)
    {
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (i != 0)
            {
                cout << ' ';
            }
            cout << vec[i];
        }
        cout << '\n';
    }
}

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

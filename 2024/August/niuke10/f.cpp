// 2024/08/15 12:36:41
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
    int n;
    cin >> n;
    vector<pii> a(n * n);
    for (int i = 0; i < n * n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    vector<pii> in;

    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n * n; i++)
    {
        auto [x1, y1] = a[i];
        if (vis[x1][y1])
        {
            cout << 0;
        }
        else
        {
            cout << 1;
            for (auto [x2, y2] : in)
            {
                int dx = x2 - x1;
                int dy = y2 - y1;
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;
                for (int k = 0;; k++)
                {
                    int tx = x1 + dx * k;
                    int ty = y1 + dy * k;
                    if (!(1 <= tx && tx <= n && 1 <= ty && ty <= n))
                        break;
                    vis[tx][ty] = 1;
                }

                for (int k = 0;; k--)
                {
                    int tx = x1 + dx * k;
                    int ty = y1 + dy * k;
                    if (!(1 <= tx && tx <= n && 1 <= ty && ty <= n))
                        break;
                    vis[tx][ty] = 1;
                }
            }
            in.emplace_back(x1, y1);
        }
    }

    cout << '\n';
}
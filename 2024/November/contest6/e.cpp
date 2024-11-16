// 2024/11/16 14:04:26
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    for (int kk = 0; kk <= min({20, k}); kk++)
    {
        auto t = s;
        rotate(t.begin(), t.begin() + kk % n, t.end());

        string tar = "nanjing";
        size_t pos = 0;
        int t_ans = 0;
        while (1)
        {
            pos = t.find(tar, pos);
            if (pos != string::npos)
            {
                t_ans++;
                pos++;
            }
            else
            {
                break;
            }
        }

        ans = max(ans, t_ans);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

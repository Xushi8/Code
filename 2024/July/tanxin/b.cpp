// 2024/07/29 19:08:26
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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
    int cnt[2] = {};
    int n;
    cin >> n >> cnt[0] >> cnt[1];
    while (cnt[0] + cnt[1] > 0 && n > 0)
    {
        int dec1 = n - (n / 2 + 10);
        int dec2 = 10;
        if (n > 20 &&  cnt[0] > 0)
        {
            cnt[0]--;
            n -= dec1;
        }
        else if(cnt[1] > 0)
        {
            cnt[1]--;
            n -= dec2;
        }
        else
        {
            break;
        }
    }

    cout << (n <= 0 ? "YES" : "NO") << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pow3;
    for (int i = 3; i < N; i *= 3)
    {
        pow3.emplace_back(i);
    }
    vector<int> cnt(N);
    for (int i = 0; i < N; i++)
    {
        cnt[i] = upper_bound(pow3.begin(), pow3.end(), i) - pow3.begin() + 1;
    }

    vector<i64> sum(N + 1);
    inclusive_scan(cnt.begin(), cnt.end(), sum.begin());

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << i << ' ' << cnt[i] << ' ' << sum[i] << endl;
    // }

    int tt;
    cin >> tt;
    while (tt--)
    {
        int l, r;
        // l = 1, r = 200000;
        cin >> l >> r;
        i64 ans = 0;
        ans += cnt[l] * 2;
        ans += sum[r] - sum[l];
        cout << ans << '\n';
    }
}
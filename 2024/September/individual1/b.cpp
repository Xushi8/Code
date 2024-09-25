// 2024/09/25 13:12:41
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 2e5 + 5;
vector<int> pow3;
vector<int> cnt(N);
void init()
{
    for (int i = 3; i < static_cast<int>(1e6); i *= 3)
    {
        pow3.emplace_back(i);
    }
    auto get = [](int val)
    {
        return upper_bound(pow3.begin(), pow3.end(), val) - pow3.begin() + 1;
    };
    for (int i = 1; i < N; i++)
    {
        cnt[i] = get(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cout << clock() / 1000 << endl;
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



void solve()
{
    int l, r;
    // cin >> l >> r;
    l = 1, r = 200000;

    vector<int> a(r - l + 1);
    iota(a.begin(), a.end(), l);
    for (auto& x : a)
    {
        x = cnt[x];
    }


    int ans = 0;
    ans += a.front() * 2;
    for (size_t i = 1; i < a.size(); i++)
    {
        ans += a[i];
    }
    cout << ans << '\n';
}
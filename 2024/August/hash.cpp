// 2024/08/07 15:16:41
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
    auto hash = [&](string_view s) -> pair<size_t, size_t>
    {
        size_t res1 = 0, res2 = 0;
        constexpr size_t base1 = 13331, base2 = 131, mod2 = 1e9 + 7;
        for (auto ch : s)
        {
            res1 = res1 * base1 + (ch - 'a');
            res2 = (res2 * base2 + (ch - 'a')) % mod2;
        }
        return {res1, res2};
    };

    auto hash1 = [&](string_view s) -> size_t
    {
        size_t res = 0;
        constexpr size_t base1 = 13331;
        for (auto ch : s)
        {
            res = res * base1 + (ch - 'a');
        }
        return res;
    };

    int n;
    cin >> n;
    string s;
    s.reserve(10000);
    set<pair<size_t, size_t>> st;
    set<size_t> st1;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        // auto ret = hash(s);
        // st.emplace(ret);
        auto ret = hash1(s);
        st1.emplace(ret);
    }

    // cout << st.size() << '\n';
    cout << st1.size() << '\n';
}
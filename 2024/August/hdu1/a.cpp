// 2024/08/16 12:54:05
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
    string s, t;
    cin >> s >> t;
    i64 ans = 0;

    for (size_t i = 0; i + 1 < s.size(); i++)
    {
        string t1 = s.substr(0, i + 1);
        string t2 = s.substr(i + 1);
        string rev_t2(t2.rbegin(), t2.rend());
        auto st1 = boyer_moore_searcher{t1.begin(), t1.end()};

        auto it = t.begin();
        vector<decltype(it)> poss;
        while (1)
        {
            it = search(it, t.end(), st1);
            if (it == t.end())
                break;
            poss.emplace_back(it);
            it++;
        }

        for (auto pos : poss)
        {
            string_view sv2(max(pos - rev_t2.size(), t.begin()), pos);
            if (sv2 == t2)
                ans++;
        }
    }

    // 完整匹配
    boyer_moore_searcher s1{s.begin(), s.end()};
    auto it = t.begin();
    while (1)
    {
        it = search(it, t.end(), s1);
        if (it == t.end())
            break;
        ans++;
        it++;
    }
    
    cout << ans << '\n';
}
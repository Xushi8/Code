// 2024/08/16 13:41:47
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

vector<size_t> get_pmt(string_view s)
{
    vector<size_t> pmt(s.size());
    for (size_t i = 1, j = 0; i < s.size(); i++)
    {
        while (j != 0 && s[i] != s[j])
        {
            j = pmt[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pmt[i] = j;
    }
    return pmt;
}

void kmp(string_view s, string_view t)
{
    auto pmt = get_pmt(t);
    for (size_t i = 0, j = 0; i < s.size(); i++)
    {
        while (j != 0 && s[i] != t[j])
            j = pmt[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == t.size())
        {
            j = pmt[j - 1];
        }
    }
}

void solve()
{
    int ans = 0;
    string s, t;
    cin >> s >> t;
    swap(s, t);
    s += s;
    auto pmt = get_pmt(t);
    vector<array<size_t, 2>> poss;
    for (size_t i = 0, j = 0; i < s.size() / 2; i++)
    {
        while (j != 0 && s[i] != t[j])
        {
            j = pmt[j - 1];
        }
        if (s[i] == t[j])
        {
            j++;
        }
        if (j > 0)
        {
            poss.emplace_back()
        }
        if (j == t.size())
        {
            ans++;
            j = pmt[j - 1];
        }
    }

    string_view sv(s), tv(t);
    for (auto [pos, len] : poss)
    {
        auto s1 = sv.substr(min<size_t>(0, pos - len), len);
        auto s2 = tv.substr(tv.size() - len, len);
        if (s1 == s2)
            ans++;
    }
    cout << ans << '\n';
}
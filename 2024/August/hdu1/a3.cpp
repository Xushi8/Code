// 2024/08/16 16:41:01
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

constexpr size_t BASE = 1331;

pair<vector<u64>, vector<u64>> get_hash(string_view s)
{
    vector<u64> res(s.size() + 1);
    vector<u64> p(s.size() + 1);
    p[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        res[i + 1] = res[i] * BASE + s[i];
        p[i + 1] = p[i] * BASE;
    }
    return {res, p};
}

// [l, r]
u64 hash_val(vector<u64> const& hash, vector<u64> const& p, size_t l, size_t r)
{
    l++; r++;
    return hash[r] - hash[l - 1] * p[r - l + 1];
}

void solve()
{
    string s, t;
    cin >> s >> t;
    swap(s, t);
    s += s;

    auto [hash_s, p_s] = get_hash(s);
    auto [hash_t, p_t] = get_hash(t);

    map<u64, size_t> mp;

    for (size_t len = 1; len <= t.size(); len++)
    {
        for (size_t i = 0; i < s.size() / 2; i++)
        {
            mp[hash_val(hash_s, p_s, i, i + len - 1)]++;
        }
    }
}
// 2024/08/17 00:09:47
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
    constexpr size_t BASE1 = 1331, BASE2 = 13331, MOD1 = 1e9 + 7, MOD2 = 998244353;
    auto get_hash = [](string_view s, const size_t BASE, const size_t MOD)
    {
        vector<u64> hash(s.size() + 1), p(s.size() + 1);
        p[0] = 1;
        for (size_t i = 0; i < s.size(); i++)
        {
            hash[i + 1] = hash[i] * BASE + s[i] - 'a' + 1;
            p[i + 1] = p[i] * BASE;
            hash[i + 1] %= MOD;
            p[i + 1] %= MOD;
        }
        return std::pair{hash, p};
    };
    auto query = [](int l, int r, vector<u64> const& hash, vector<u64> const& p, const size_t MOD)
    {
        const u64 res = (hash[r] - hash[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
        return res;
    };

    string s;
    cin >> s;

    auto [hash1, p1] = get_hash(s, BASE1, MOD1);
    auto [hash2, p2] = get_hash(s, BASE2, MOD2);

    int q;
    cin >> q;
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        bool ok1 = query(l1, r1, hash1, p1, MOD1) == query(l2, r2, hash1, p1, MOD1);
        bool ok2 = query(l1, r1, hash2, p2, MOD2) == query(l2, r2, hash2, p2, MOD2);
        cout << (ok1 && ok2 ? "Yes" : "No") << '\n';
    }
}
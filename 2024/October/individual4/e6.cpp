// 2024/10/23 17:15:58
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

// BASE 要大于 s[i], 最好远大于
// BASE 与 MOD 最好都是质数, 冲突概率小
constexpr u64 BASE1 = 1063, BASE2 = 13331, MOD1 = 1e9 + 7, MOD2 = 998244353;
auto get_hash(string_view s, const u64 BASE, const u64 MOD)
{
    vector<u64> hash(s.size() + 1), p(s.size() + 1);
    p[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[i + 1] = hash[i] * BASE + s[i];
        p[i + 1] = p[i] * BASE;
        hash[i + 1] %= MOD;
        p[i + 1] %= MOD;
    }
    return std::pair{hash, p};
}

void update_hash(string_view s, vector<u64>& hash, vector<u64>& p, const u64 BASE, const u64 MOD)
{
    const size_t old_size = hash.size();
    hash.resize(s.size() + 1);
    p.resize(s.size() + 1);

    for (size_t i = old_size - 1; i < s.size(); i++)
    {
        hash[i + 1] = hash[i] * BASE + s[i];
        p[i + 1] = p[i] * BASE;
        hash[i + 1] %= MOD;
        p[i + 1] %= MOD;
    }
}

u64 query(int l, int r, vector<u64> const& hash, vector<u64> const& p, const u64 MOD)
{
    u64 res = (hash[r] - hash[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    string ans = a[0];
    auto [hash1, p1] = get_hash(ans, BASE1, MOD1);
    auto [hash2, p2] = get_hash(ans, BASE2, MOD2);
    hash1.reserve(N);
    p1.reserve(N);
    hash2.reserve(N);
    p2.reserve(N);

    for (int i = 1; i < n; i++)
    {
        string s2 = a[i];
        update_hash(ans, hash1, p1, BASE1, MOD1);
        update_hash(ans, hash2, p2, BASE2, MOD2);

        auto [hash11, p11] = get_hash(s2, BASE1, MOD1);
        auto [hash22, p22] = get_hash(s2, BASE2, MOD2);

        int cnt = 0;
        for (int j = 0; j < min<int>(ans.size(), s2.size()); j++)
        {
            u64 h1 = query(ans.size() - j, ans.size(), hash1, p1, MOD1);
            u64 h11 = query(1, 1 + j, hash11, p11, MOD1);

            u64 h2 = query(ans.size() - j, ans.size(), hash2, p2, MOD2);
            u64 h22 = query(1, 1 + j, hash22, p22, MOD2);

            if (h1 == h11 && h2 == h22)
            {
                cnt = j + 1;
            }
        }

        ans.insert(ans.end(), s2.begin() + cnt, s2.end());
    }

    cout << ans << '\n';
}

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

// 2024/11/06 18:50:15
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

using u64 = uint64_t;

// BASE 要大于 s[i], 最好远大于
// BASE 与 MOD 最好都是质数, 冲突概率小
constexpr u64 BASE1 = 1063, BASE2 = 13331, MOD1 = 1e9 + 7, MOD2 = 998244353;
__attribute__((always_inline)) auto get_hash(string_view s, const u64 BASE, const u64 MOD)
{
    vector<vector<u64>> hash(s.size() + 1, vector<u64>(26));
    vector<u64> p(s.size() + 1);
    p[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            hash[i + 1][j] = hash[i][j] * BASE + (s[i] == 'a' + j ? s[i] : '*');
            hash[i + 1][j] %= MOD;
        }
        p[i + 1] = p[i] * BASE;
        p[i + 1] %= MOD;
    }
    return std::pair{hash, p};
}

// [l, r] 最大为 [1, s.size()]
__attribute__((always_inline)) u64 query(int l, int r, int j, vector<vector<u64>> const& hash, vector<u64> const& p, const u64 MOD)
{
    u64 res = (hash[r][j] - hash[l - 1][j] * p[r - l + 1] % MOD + MOD) % MOD;
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    auto [hash1, p1] = get_hash(s, BASE1, MOD1);
    auto [hash2, p2] = get_hash(s, BASE2, MOD2);

    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        vector<char> res;
        for (int j = 0; j < 26; j++)
        {
            u64 h1a = query(l1, r1, j, hash1, p1, MOD1);
            u64 h1b = query(l2, r2, j, hash1, p1, MOD1);

            u64 h2a = query(l1, r1, j, hash2, p2, MOD2);
            u64 h2b = query(l2, r2, j, hash2, p2, MOD2);

            if (h1a != h1b || h2a != h2b)
            {
                res.emplace_back(j + 'a');
            }
        }

        cout << res.size() << '\n';
        for (auto ch : res)
        {
            cout << ch;
        }
        cout << '\n';
    }
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

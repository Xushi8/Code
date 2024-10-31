// 2024/10/23 15:23:25
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

constexpr size_t BASE1 = 211, BASE2 = 13331, MOD1 = 1e9 + 7, MOD2 = 998244353;
auto get_hash = [](string_view s, const size_t BASE, const size_t MOD)
{
    vector<u64> hash(s.size() + 1), p(s.size() + 1);
    p[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[i + 1] = hash[i] * BASE + s[i] - 'a' + 1;
        p[i + 1] = p[i] * BASE;
        // hash[i + 1] %= MOD;
        // p[i + 1] %= MOD;
    }
    return std::pair{hash, p};
};

auto update_hash = [](string_view s, const size_t BASE, const size_t MOD, vector<u64>& hash, vector<u64>& p)
{
    const size_t old_size = hash.size();
    hash.resize(s.size() + 1);
    p.resize(s.size() + 1);

    for (size_t i = old_size - 1; i < s.size(); i++)
    {
        hash[i + 1] = hash[i] * BASE + s[i] - 'a' + 1;
        p[i + 1] = p[i] * BASE;
        // hash[i + 1] %= MOD;
        // p[i + 1] %= MOD;
    }
};

auto query = [](int l, int r, vector<u64> const& hash, vector<u64> const& p, const size_t MOD)
{
    // const u64 res = (hash[r] - hash[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    const u64 res = hash[r] - hash[l - 1] * p[r - l + 1];
    return res;
};

void solve()
{
    auto split = [](string_view s)
    {
        deque<string> res;
        for (size_t i = 0; i < s.size();)
        {
            size_t j;
            for (j = i; j < s.size() && s[j] != ' '; j++) {}
            size_t len = j - i;
            if (len != 0)
            {
                res.emplace_back(s.substr(i, len));
            }
            i = j + 1;
        }
        return res;
    };

    int n;
    cin >> n;
    cin.ignore(1111, '\n');
    string s;
    getline(cin, s);
    auto a = split(s);

    auto top = a.front();
    auto [hash1, p1] = get_hash(top, BASE1, MOD1);
    // auto [hash11, p11] = get_hash(top, BASE2, MOD2);
    // hash1.reserve(N);
    // p1.reserve(N);
    // hash11.reserve(N);
    // p11.reserve(N);

    while (a.size() >= 2)
    {
        auto s1 = std::move(a.front());
        a.pop_front();
        auto s2 = std::move(a.front());
        a.pop_front();

        update_hash(s1, BASE1, MOD1, hash1, p1);
        // update_hash(s1, BASE2, MOD2, hash11, p11);
        auto [hash2, p2] = get_hash(s2, BASE1, MOD1);
        // auto [hash22, p22] = get_hash(s2, BASE2, MOD2);

        // cerr << a.size() << '\n';
        // for (auto x : hash1)
        // {
        //     cerr << x << ' ';
        // }
        // cerr << '\n';

        const int len1 = s1.size(), len2 = s2.size();
        int cnt = 0;
        for (int i = 0; i < min(len1, len2); i++)
        {
            u64 h1 = query(len1 - i, len1, hash1, p1, MOD1);
            u64 h2 = query(1, 1 + i, hash2, p2, MOD1);
            // u64 h11 = query(len1 - i, len1, hash11, p11, MOD2);
            // u64 h22 = query(1, 1 + i, hash22, p22, MOD2);
            if (h1 == h2)
            {
                cnt = i + 1;
            }
        }

        string tmp = std::move(s1);
        tmp.insert(tmp.end(), s2.begin() + cnt, s2.end());
        a.emplace_front(std::move(tmp));
    }

    cout << a.front() << '\n';
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

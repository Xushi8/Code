#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

constexpr size_t BASE1 = 1331, BASE2 = 13331, MOD1 = 1e9 + 7, MOD2 = 998244353;
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
    return std::pair{hash, p};
};

auto query = [](int l, int r, vector<u64> const& hash, vector<u64> const& p, const size_t MOD)
{
    // const u64 res = (hash[r] - hash[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    const u64 res = hash[r] - hash[l - 1] * p[r - l + 1];
    return res;
};

int main()
{
    string res = "asdjd";
    auto [hash1, p1] = get_hash(res, BASE1, MOD1);
    string s;
    while (cin >> s)
    {
        // cout << s.size() << '\n';
        auto [hash, p] = get_hash(s, BASE1, MOD1);
        if (s.size() > 10)
        {
            cout << query(1, 10, hash, p, MOD1) << '\n';
        }

        res += s;

        update_hash(res, BASE1, MOD1, hash1, p1);
        if (res.size() > 1000000)
        {
            cout << query(1, 1000, hash1, p1, MOD1) << '\n';
        }
    }
}
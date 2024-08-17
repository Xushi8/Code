#include <string>
#include <cstdint>
#include <vector>
#include <iostream>
using namespace std;
using u64 = uint64_t;

void func(string_view zifuchuan, vector<pair<int, int>> const& queries)
{
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

    auto query = [](size_t l, size_t r, vector<u64> const& hash, vector<u64> const& p, const size_t MOD)
    {
        return (hash[r] - hash[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    };

    auto [hash, p] = get_hash(zifuchuan, 1331, 1e9 + 7);
    for (auto [l, r] : queries)
    {
        cout << query(l, r, hash, p, 1e9 + 7);
    }
}

#include <cstddef>
#include <cstdint>
#include <limits>
#include <string_view>
#include <string>
#include <utility>
#include <vector>
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
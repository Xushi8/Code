#include <bits/stdc++.h>

using namespace std;

using u64 = uint64_t;

constexpr u64 BASE1 = 1063, BASE2 = 13331, MOD1 = 1e9 + 7, MOD2 = 998244353;

constexpr pair<vector<u64>, vector<u64>> get_hash(string_view s, u64 base, u64 mod)
{
    vector<u64> hash(s.size() + 1);
    auto p = hash;
    p[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[i + 1] = hash[i] * base + s[i];
        p[i + 1] = p[i] * base;
        hash[i + 1] %= mod;
        p[i + 1] %= mod;
    }

    return {hash, p};
}

constexpr u64 query(u64 l, u64 r, vector<u64> const& hash, vector<u64> const& p, u64 mod)
{
    return (hash[r] - hash[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

class Solution
{
public:
    string longestDupSubstring(string s)
    {
        auto [hash1, p1] = get_hash(s, BASE1, MOD1);
        auto [hash2, p2] = get_hash(s, BASE2, MOD2);

        string ans;

        auto check = [&](u64 len) -> string
        {
            unordered_set<u64> st1, st2;
            for (size_t i = 0; i + len <= s.size(); i++)
            {
                u64 h1 = query(i + 1, i + len, hash1, p1, MOD1);
                u64 h2 = query(i + 1, i + len, hash2, p2, MOD2);

                if (st1.count(h1) && st2.count(h2))
                {
                    return s.substr(i, len);
                }
                else
                {
                    st1.emplace(h1);
                    st2.emplace(h2);
                }
            }

            return {};
        };

        u64 l = 1, r = s.size();
        while (l <= r)
        {
            u64 mid = l + (r - l) / 2;
            string tmp = check(mid);
            if (!tmp.empty())
            {
                if (tmp.size() > ans.size())
                {
                    ans = std::move(tmp);
                }

                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    string s = "banana";

    Solution so;
    string ans = so.longestDupSubstring(s);
    cout << ans << endl;
}
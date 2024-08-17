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

constexpr size_t BASE = 1331;

pair<vector<u64>, vector<u64>> get_hash(string_view s)
{
    vector<u64> hash(s.size() + 1), p(s.size() + 1);
    p[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[i + 1] = hash[i] * BASE + s[i] - 'a' + 1;
        p[i + 1] = p[i] * BASE;
    }
    return {hash, p};
}

void solve()
{
    string s;
    cin >> s;
    auto [hash, p] = get_hash(s);
    auto query = [&](int l1, int r1)
    {
        u64 res = hash[r1] - hash[l1 - 1] * p[r1 - l1 + 1];
        return res;
    };

    int q;
    cin >> q;
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // l1++;
        // r1++;
        // l2++;
        // r2++;
        cout << (query(l1, r1) == query(l2, r2) ? "Yes" : "No") << '\n';
    }
}
// 2024/08/09 14:04:58
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
    vector<array<int, 3>> trie(1);
    trie[0].fill(-1);
    vector<int> cnt;
    trie.reserve(5 * N);
    cnt.reserve(5 * N);
    auto insert = [&](string_view s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if()
        }
    };
    
}
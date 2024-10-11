// 2024/10/09 15:07:06
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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n != 0)
    {
        map<string, vector<string>> G;
        for (int i = 0; i < n; i++)
        {
            string win, lose;
            cin >> win >> lose;
            G.try_emplace(win);
            G[lose].emplace_back(win);
        }

        int cnt = 0;
        for (auto const& [u, vec] : G)
        {
            if (vec.empty())
            {
                cnt++;
            }
        }

        cout << (cnt == 1 ? "Yes" : "No") << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

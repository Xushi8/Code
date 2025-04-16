// 2025/04/16 19:40:54
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

void solve()
{
    string s;
    cin >> s;
    if (s.size() == 6)
    {
        cout << s.substr(0, 4) << '-' << s.substr(4) << '\n';
    }
    else
    {
        int x = stoi(s.substr(0, 2));
        if (x < 22)
        {
            cout << "20";
        }
        else
        {
            cout << "19";
        }
        cout << s.substr(0, 2) << '-' << s.substr(2) << '\n';
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

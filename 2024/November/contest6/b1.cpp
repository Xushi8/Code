// 2024/11/16 15:11:35
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

void solve()
{
    string s;
    cin >> s;
    deque<int> a(s.begin(), s.end());
    for (auto& ch : a)
    {
        ch -= '0';
    }

    // 清空连续的 0 和 1
    auto func1 = [&]
    {
        for (int i = 0; i < int(a.size());)
        {
            int j;
            for (j = 0; j < int(a.size()) && a[j] == a[i]; j++) {}
            int cnt = j - i;
            if (cnt > 1 && a[i] != 2)
            {
                int old = a[i];
                a.erase(a.begin() + i, a.begin() + j);
                if (cnt % 2 == 1)
                {
                    a.insert(a.begin() + i, old);
                }
            }
        }
    };

    // 2 开始清除  去消非 2 数量较多的一边
    auto func2 = [&]
    {
        int cnt_2 = std::count(a.begin(), a.end(), 2);
        int nex_2 = int(s.size());

        for (int i = 0; i < int(a.size());)
        {
            if (a[i] != 2)
            {
                i++;
                continue;
            }
            int j;
            for (j = i + 1; j < int(a.size()) && a[j] == 2; j++) {}

            int l = i, r = j;
            int cnt = r - l;
            int cnt_l = i - 1;
            int cnt_r = int(s.size()) - cnt_l - cnt_2;

            for (; j < int(s.size()) && a[j] != 2; j++) {}
            nex_2 = j;

            
        }
    };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

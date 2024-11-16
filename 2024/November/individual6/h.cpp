// 2024/11/15 19:34:10
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
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum1{1}, sum2{1};
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            sum1++;
        else
            break;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            sum2++;
        else
            break;
    }

    bool win = 1;
    int last = -1;
    while (!a.empty())
    {
        if (a.front() <= last)
        {
            while (!a.empty())
            {
                if (a.back() <= last)
                    break;
                last = a.back();
                a.pop_back();
                win = !win;
            }
            win = !win;
            break;
        }

        if (a.back() <= last)
        {
            while (!a.empty())
            {
                if (a.front() <= last)
                    break;
                last = a.front();
                a.pop_front();
                win = !win;
            }
            win = !win;
            break;
        }
        
        if (a.front() >= a.back())
        {
            // choose front game over
            if (sum1 % 2 == 1)
                break;

            // choose back
            last = a.back();
            a.pop_back();
            sum2--;
        }
        else
        {
            // choos back game over
            if (sum2 % 2 == 1)
                break;

            // choose front
            last = a.front();
            a.pop_front();
            sum1--;
        }

        win = !win;
    }

    cout << (win ? "Alice" : "Bob") << '\n';
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

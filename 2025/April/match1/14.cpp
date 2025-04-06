#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using i64 = int64_t;

void solve()
{
    int tn, tm, tk;
    cin >> tn >> tm >> tk;
    string a;
    cin >> a;
    for (auto& ch : a)
    {
        ch -= '0';
    }

    auto check = [&](int tar) mutable -> int
    {
        int n = tn, m = tm, k = tk;
        i64 ans = 0;
        if (a[tar] == 1)
        {
            k--;
        }
        if (a[tar] == 0 && m > 0)
        {
            m--;
            k--;
        }
        for (int d = 1; d < n && tar - d >= 0 && tar + d < n && k > 0; d++)
        {
            int t = a[tar - d] + a[tar + d];
            if (k >= 2)
            {
                if (m > 0 && t < 2)
                {
                    m--;
                    t++;
                }
                if (m > 0 && t < 2)
                {
                    m--;
                    t++;
                }

                ans += d * t;
                k -= t;
            }
            else
            { // k == 1
                if (m > 0 && t < 1)
                {
                    m--;
                    t++;
                }
                if (t > 1)
                {
                    t--;
                }

                ans += d * t;
                k -= t;
            }
        }

        if (k == 0)
        {
            return ans;
        }

        if (tar < n / 2)
        {
            for (int d = tar + 1; d < n && k > 0; d++)
            {
                int t = a[tar + d];
                if (m > 0 && t < 1)
                {
                    m--;
                    t++;
                }
                ans += d * t;
                k -= t;
            }
        }
        else
        {
            for (int d = (n - tar); d < n && k > 0; d++)
            {
                int t = a[tar - d];
                if (m > 0 && t < 1)
                {
                    m--;
                    t++;
                }
                ans += d * t;
                k -= t;
            }
        }

        return ans;
    };

    for (int i = 0; i < tn; i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        i64 ans = check(i);
        cout << ans;
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int m, k, h;
int qpow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
        {
            res = (res * x);
        }
        x = (x * x);
        y >>= 1;
    }
    return res;
}
int sum(int x)
{
    if (x < m)
    {
        return x;
    }
    return (x / m) * m + sum((x / m) * k + x % m);
}
const int N = 31;
int K[N];
int M[N];
int SU[N];
void solve()
{
    cin >> m >> k >> h;
    if (h == 0 || h == 1)
    {
        cout << h << endl;
        return;
    }
    if (m == k || h <= m)
    {
        cout << min(m, h) << endl;
        return;
    }
    int l = min(m, h);
    int r = h;
    int t = h;
    for (int i = 0; i <= N; i++)
    {
        if (!i)
        {
            M[i] = K[i] = 1;
        }
        else
        {
            M[i] = K[i] = k * K[i - 1];
        }
    }
    for (int i = 0; qpow(m, i) <= h; i++)
    {
        if (!i)
        {
            SU[i] = 1;
            continue;
        }
        SU[i] = (m * SU[(i - 1)]) + K[i];
        int cnt = K[i];
        for (int j = i - 1; j >= 0; j--)
        {
            int sd = 0;
            sd = (cnt / M[j]) * SU[j];
            cnt -= sd;
            SU[i] += sd;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (h < SU[i])
        {
            l = M[i];
        }
    }
    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (sum(mid) > h)
        {
            r = mid - 1;
            t = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << t << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}
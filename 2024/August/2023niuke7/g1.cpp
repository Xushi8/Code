#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int read()
{
    int x;
    scanf("%d", &x);
    return x;
}

int n, m, k;
int a[1000005];
bool vis[1000005];
int b[1000005];
long long x[1000005];
bool calc()
{
    if (m & 1)
    {
        long long tot = accumulate(b + 1, b + m + 1, 0ll);
        if (tot & 1) { return 0; }
        tot /= 2;
        long long sm = 0;
        for(int i = 1; i <= m; i++)
        {
            sm += (i & 1) * b[i];
        }
        x[m] = sm - tot;
        for (int i = m; i >= 2; i--)
        {
            x[i - 1] = b[i] - x[i];
        }
        return *min_element(x + 1, x + m + 1) >= 0;
    }
    long long o = 0, e = 0;
    for(int i = 1; i <= m; i++)
    {
        if (i & 1) { o += b[i]; }
        else { e += b[i]; }
    }
    if (o ^ e) { return 0; }
    long long ulim = b[2], dlim = 0;
    long long cur = b[2];
    for (int i = 3; i <= m; i++)
    {
        if (i & 1)
        {
            cur -= b[i];
            dlim = max(dlim, cur);
        }
        else
        {
            cur += b[i];
            ulim = min(ulim, cur);
        }
    }
    return dlim <= ulim;
}
void solve()
{
    n = read(), k = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    if (k == n)
    {
        if (!(*max_element(a + 1, a + n + 1))) { puts("YES"); }
        else { puts("NO"); }
        return;
    }
    bool ok = 1;
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            m = 0;
            int cur = i;
            while (!vis[cur])
            {
                vis[cur] = 1;
                b[++m] = a[cur];
                if ((cur + k) % n == 0) { cur = n; }
                else { cur = (cur + k) % n; }
            }
            ok &= calc();
        }
    }
    puts((ok ? "YES" : "NO"));
}
signed main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}

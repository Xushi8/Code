#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 400005;

int a[N];
LL p[N];
LL ans0[N], ans[N];
int vis[N];
int main()
{
    int n, q, m;
    scanf("%d%d%d", &n, &q, &m);
    LL s = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s += a[i];
        a[i + n] = a[i];
    }
    for (int i = 0; i < 2 * n; i++)
    {
        p[i] = i == 0 ? a[i] : p[i - 1] + a[i];
    }
    memset(vis, 0, sizeof vis);
    int u = 0;
    for (int i = 0; i < n; i++)
    {
        ans0[i] = m / s * n;
        int k = m % s == 0 ? u - 1 : lower_bound(p + u, p + 2 * n, (u == 0 ? 0 : p[u - 1]) + m % s) - p;
        ans0[i] += k - u + 1;
        u = (k + 1) % n;
    }
    int tot = 0, wc = u;
    while (1)
    {
        ans[tot] = m / s * n;
        int k = m % s == 0 ? u - 1 : lower_bound(p + u, p + 2 * n, (u == 0 ? 0 : p[u - 1]) + m % s) - p;
        ans[tot++] += k - u + 1;
        u = (k + 1) % n;
        if (wc == u) break;
    }

    while (q--)
    {
        LL x;
        scanf("%lld", &x);
        x--;
        printf("%lld\n", x < n ? ans0[x] : ans[(x - n) % tot]);
    }
    return 0;
}

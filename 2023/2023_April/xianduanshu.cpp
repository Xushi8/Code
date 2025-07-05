#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
long long d[4 * maxn], b[4 * maxn], a[maxn];

void build(int l, int r, int p)
{
    if (l == r)
    {
        d[p] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

// l, r为要修改的区间, s, t为当前区间
void add(int l, int r, int val, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        d[p] += (t - s + 1) * val;
        b[p] += val;
        return;
    }

    int mid = s + (t - s) / 2;
    if (b[p] && s != t)
    {
        d[p * 2] += b[p] * (mid - s + 1);
        d[p * 2 + 1] += b[p] * (t - mid);
        b[p * 2] += b[p];
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }
    if (l <= mid) add(l, r, val, s, mid, p * 2);
    if (mid < r) add(l, r, val, mid + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

long long getsum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        return d[p];
    }
    int mid = s + (t - s) / 2;
    if (b[p])
    {
        d[p * 2] += b[p] * (mid - s + 1);
        d[p * 2 + 1] += b[p] * (t - mid);
        b[p * 2] += b[p];
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }
    long long sum = 0;
    if (l <= mid) sum = getsum(l, r, s, mid, p * 2);
    if (mid < r) sum += getsum(l, r, mid + 1, t, p * 2 + 1);
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, n, 1);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            int tmp;
            cin >> tmp;
            add(y, z, tmp, 1, n, 1);
        }
        else
        {
            cout << getsum(y, z, 1, n, 1) << '\n';
        }
    }

    cout << flush;
    system("pause");
    return 0;
}



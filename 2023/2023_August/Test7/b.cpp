// 2023/08/09 09:43:39
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 100005;

int arr[N];
ll d[N * 4], b[N * 4], k[N * 4];
int mod;

void build(int l, int r, int p)
{
    if (l == r)
    {
        d[p] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}

void mul_num(int l, int r, int nl, int nr, ll mul_val, int p)
{
    if (l <= nl && nr <= r)
    {
        d[p] *= mul_val;
        b[p] *= mul_val;
        k[p] *= mul_val;

        d[p] %= mod;
        b[p] %= mod;
        k[p] %= mod;
        return;
    }

    int mid = nl + (nr - nl) / 2;
    if (k[p] != 1)
    {
        d[p * 2] *= k[p];
        d[p * 2 + 1] *= k[p];
        b[p * 2] *= k[p];
        b[p * 2 + 1] *= k[p];
        k[p * 2] *= k[p];
        k[p * 2 + 1] *= k[p];

        d[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2] %= mod;
        b[p * 2 + 1] %= mod;
        k[p * 2] %= mod;
        k[p * 2 + 1] %= mod;

        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];

        d[p * 2] %= mod;
        b[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2 + 1] %= mod;

        b[p] = 0;
    }

    if (l <= mid)
        mul_num(l, r, nl, mid, mul_val, p * 2);
    if (mid + 1 <= r)
        mul_num(l, r, mid + 1, nr, mul_val, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}


void add_num(int l, int r, int nl, int nr, ll add_val, int p)
{
    if (l <= nl && nr <= r)
    {
        d[p] += add_val * (nr - nl + 1);
        b[p] += add_val;

        d[p] %= mod;
        b[p] %= mod;
        return;
    }

    int mid = nl + (nr - nl) / 2;
    if (k[p] != 1)
    {
        d[p * 2] *= k[p];
        d[p * 2 + 1] *= k[p];
        b[p * 2] *= k[p];
        b[p * 2 + 1] *= k[p];
        k[p * 2] *= k[p];
        k[p * 2 + 1] *= k[p];

        d[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2] %= mod;
        b[p * 2 + 1] %= mod;
        k[p * 2] %= mod;
        k[p * 2 + 1] %= mod;

        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];

        d[p * 2] %= mod;
        b[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2 + 1] %= mod;

        b[p] = 0;
    }

    if (l <= mid)
        add_num(l, r, nl, mid, add_val, p * 2);
    if (mid + 1 <= r)
        add_num(l, r, mid + 1, nr, add_val, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}

ll query(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        return d[p];
    }

    int mid = nl + (nr - nl) / 2;
    if (k[p] != 1)
    {
        d[p * 2] *= k[p];
        d[p * 2 + 1] *= k[p];
        b[p * 2] *= k[p];
        b[p * 2 + 1] *= k[p];
        k[p * 2] *= k[p];
        k[p * 2 + 1] *= k[p];

        d[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2] %= mod;
        b[p * 2 + 1] %= mod;
        k[p * 2] %= mod;
        k[p * 2 + 1] %= mod;

        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];

        d[p * 2] %= mod;
        b[p * 2] %= mod;
        d[p * 2 + 1] %= mod;
        b[p * 2 + 1] %= mod;

        b[p] = 0;
    }


    ll sum = 0;
    if (l <= mid)
    {
        sum += query(l, r, nl, mid, p * 2);
        sum %= mod;
    }
    if (mid + 1 <= r)
    {
        sum += query(l, r, mid + 1, nr, p * 2 + 1);
        sum %= mod;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    build(1, n, 1);
    fill(k, k + 4 * N, 1);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int op, l, r;
        ll val;
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> val;
            mul_num(l, r, 1, n, val, 1);
        }
        else if (op == 2)
        {
            cin >> val;
            add_num(l, r, 1, n, val, 1);
        }
        else
        {
            cout << query(l, r, 1, n, 1) << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
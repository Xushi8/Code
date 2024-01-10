// 2023/08/07 16:10:34
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
ll d[4 * N];
ll b[4 * N];
ll k[4 * N];
const int mod = 571373;

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
}

ll query(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
        return d[p];

    int mid = nl + (nr - nl) / 2;

    if (k[p] != 1)
    {
        k[p * 2] = k[p * 2] * k[p] % mod;
        k[p * 2 + 1] = k[p * 2 + 1] * k[p] % mod;
        b[p * 2] = b[p * 2] * k[p] % mod;
        b[p * 2 + 1] = b[p * 2 + 1] * k[p] % mod;
        d[p * 2] = d[p * 2] * k[p] % mod;
        d[p * 2 + 1] = d[p * 2 + 1] * k[p] % mod;
        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] = (d[p * 2] + (mid - nl + 1) * b[p]) % mod;
        b[p * 2] = (b[p * 2] + b[p]) % mod;
        d[p * 2 + 1] = (d[p * 2 + 1] + (nr - (mid + 1) + 1) * b[p]) % mod;
        b[p * 2 + 1] = (b[p * 2 + 1] + b[p]) % mod;
        b[p] = 0;
    }

    ll sum = 0;
    if (l <= mid)
        sum += query(l, r, nl, mid, p * 2) % mod, sum %= mod;
    if (mid + 1 <= r)
        sum += query(l, r, mid + 1, nr, p * 2 + 1) % mod;
    return sum % mod;
}

void add(int l, int r, int nl, int nr, int add_val, int p)
{
    if (l <= nl && nr <= r)
    {
        d[p] += (nr - nl + 1) * add_val;
        d[p] %= mod;
        b[p] += add_val;
        b[p] %= mod;
        return;
    }

    int mid = nl + (nr - nl) / 2;

    if (k[p] != 1)
    {
        k[p * 2] = k[p * 2] * k[p] % mod;
        k[p * 2 + 1] = k[p * 2 + 1] * k[p] % mod;
        b[p * 2] = b[p * 2] * k[p] % mod;
        b[p * 2 + 1] = b[p * 2 + 1] * k[p] % mod;
        d[p * 2] = d[p * 2] * k[p] % mod;
        d[p * 2 + 1] = d[p * 2 + 1] * k[p] % mod;
        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] = (d[p * 2] + (mid - nl + 1) * b[p]) % mod;
        b[p * 2] = (b[p * 2] + b[p]) % mod;
        d[p * 2 + 1] = (d[p * 2 + 1] + (nr - (mid + 1) + 1) * b[p]) % mod;
        b[p * 2 + 1] = (b[p * 2 + 1] + b[p]) % mod;
        b[p] = 0;
    }

    if (l <= mid)
        add(l, r, nl, mid, add_val, p * 2);
    if (mid + 1 <= r)
        add(l, r, mid + 1, nr, add_val, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
}

void mul(int l, int r, int nl, int nr, int mul_val, int p)
{
    if (l <= nl && nr <= r)
    {
        k[p] = k[p] * mul_val % mod;
        b[p] = b[p] * mul_val % mod;
        d[p] = d[p] * mul_val % mod;
        return;
    }

    int mid = nl + (nr - nl) / 2;

    if (k[p] != 1)
    {
        k[p * 2] = k[p * 2] * k[p] % mod;
        k[p * 2 + 1] = k[p * 2 + 1] * k[p] % mod;
        b[p * 2] = b[p * 2] * k[p] % mod;
        b[p * 2 + 1] = b[p * 2 + 1] * k[p] % mod;
        d[p * 2] = d[p * 2] * k[p] % mod;
        d[p * 2 + 1] = d[p * 2 + 1] * k[p] % mod;
        k[p] = 1;
    }

    if (b[p] != 0)
    {
        d[p * 2] = (d[p * 2] + (mid - nl + 1) * b[p]) % mod;
        b[p * 2] = (b[p * 2] + b[p]) % mod;
        d[p * 2 + 1] = (d[p * 2 + 1] + (nr - (mid + 1) + 1) * b[p]) % mod;
        b[p * 2 + 1] = (b[p * 2 + 1] + b[p]) % mod;
        b[p] = 0;
    }

    if (l <= mid)
        mul(l, r, nl, mid, mul_val, p * 2);
    if (mid + 1 <= r)
        mul(l, r, mid + 1, nr, mul_val, p * 2 + 1);

    d[p] = (d[p * 2] + d[p * 2 + 1]) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tt;
    int tmp;
    cin >> n >> tt >> tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    build(1, n, 1);
    fill(k, k + 4 * N, 1);
    while (tt--)
    {
        int op, l, r, add_val, mul_val;
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> mul_val;
            mul(l, r, 1, n, mul_val, 1);
        }
        else if (op == 2)
        {
            cin >> add_val;
            add(l, r, 1, n, add_val, 1);
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
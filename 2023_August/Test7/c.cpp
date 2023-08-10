// 2023/08/09 17:10:59
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
const int N = 200005;
int arr[N];
double ts[4 * N], tc[4 * N];
ll b[4 * N];
double sinx, cosx;

void build(int l, int r, int p)
{
    if(l == r)
    {
        ts[p] = sin(arr[l]);
        tc[p] = cos(arr[l]);
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);

    ts[p] = ts[p * 2] + ts[p * 2 + 1];
    tc[p] = tc[p * 2] + tc[p * 2 + 1];
}

void flag(int p, ll val, double sx, double cx)
{
    double si = ts[p], co = tc[p];
    ts[p] = (cx * si + sx * co);
    tc[p] = (cx * co - sx * si);
    b[p] += val;
}
void push_down(int p)
{
    double tmps = sin(b[p]), tmpc = cos(b[p]);
    flag(p * 2, b[p], tmps, tmpc);
    flag(p * 2 + 1, b[p], tmps, tmpc);
    b[p] = 0;
}

void add(int l, int r, int nl, int nr, int val, int p)
{
    if (l <= nl && nr <= r)
    {
        flag(p, val, sinx, cosx);
        return;
    }

    if (b[p] != 0)
    {
        push_down(p);
    }

    int mid = nl + (nr - nl) / 2;
    if (l <= mid)
        add(l, r, nl, mid, val, p * 2);
    if (mid + 1 <= r)
        add(l, r, mid + 1, nr, val, p * 2 + 1);

    ts[p] = ts[p * 2] + ts[p * 2 + 1];
    tc[p] = tc[p * 2] + tc[p * 2 + 1];
}

double query(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        return ts[p];
    }

    int mid = nl + (nr - nl) / 2;

    if (b[p] != 0)
    {
        push_down(p);
    }
    
    double sum = 0;
    if (l <= mid)
        sum += query(l, r, nl, mid, p * 2);
    if (mid + 1 <= r)
        sum += query(l, r, mid + 1, nr, p * 2 + 1);

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    build(1, n, 1);

    int tt;
    cin >> tt;
    cout << setprecision(1) << fixed;
    while (tt--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int val;
            cin >> val;
            sinx = sin(val);
            cosx = cos(val);
            add(l, r, 1, n, val, 1);
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
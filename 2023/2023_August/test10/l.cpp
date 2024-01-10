// 2023/08/17 11:21:27
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
const int N = 1000005;

int par[N];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
}

int find(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    else
        par[x] = y;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

bool cmp(const array<int, 3>& a, const array<int, 3>& b)
{
    return a[2] > b[2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][0]--; arr[i][1]--;
    }

    sort(arr.begin(), arr.end(), cmp);

    int ans = 0;
    init(n * 2);
    for (int i = 0; i < n; i++)
    {
        auto [a, b, c] = arr[i];
        if (!same(a, b) && !same(b + n, a + n))
        {
            unite(a, b + n);
            unite(b, a + n);
        }
        else
        {
            ans = c;
            break;
        }
    }

    cout << ans << '\n';


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
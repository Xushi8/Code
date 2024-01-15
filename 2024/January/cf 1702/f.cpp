// 2024/01/14 21:15:23
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
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 200005;

int bit[N * 31][2];
int vala[N], valb[N];
int all = 0;

void inserta(int x)
{
    int u = 0;
    int cnt = 31 - __builtin_clz(x);
    for (int i = cnt; i >= 0; i--)
    {
        int& v = bit[u][(x >> i) & 1];
        if (v == 0) v = ++all;
        u = v;
    }
    vala[u]++;
}

void insertb(int x)
{
    int u = 0;
    int cnt = 31 - __builtin_clz(x);
    for (int i = cnt; i >= 0; i--)
    {
        int& v = bit[u][(x >> i) & 1];
        if (v == 0) v = ++all;
        u = v;
    }
    valb[u]++;
}

void solve()
{
    for (int i = 0; i <= all; i++)
    {
        bit[i][0] = bit[i][1] = vala[i] = valb[i] = 0;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        inserta(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertb(x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int x = 5;
    // cout << bitset<32>(x) << endl;
    // cout << 32 - 1 - __builtin_clz(x) << endl;

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
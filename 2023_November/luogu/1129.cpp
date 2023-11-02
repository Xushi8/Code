// 2023/11/02 13:10:10
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
constexpr int N = 205;

int n;
int arr[N][N], p[N];
bool vis[N];

bool match(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (arr[i][j] != 0 && !vis[j])
        {
            vis[j] = 1;
            if (p[j] == -1 || match(p[j]))
            {
                p[j] = i;
                return true;
            }
        }
    }

    return false;
}

int func()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (match(i))
            res++;
    }

    return res;
}

void solve()
{
    cin >> n;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << (func() == n ? "Yes\n" : "No\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
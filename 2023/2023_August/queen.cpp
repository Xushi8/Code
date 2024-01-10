// 2023/08/04 20:50:40
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
int n;
int arr[30];

bool check(int x, int y)
{
    for (int i = 1; i < x; i++)
    {
        if (arr[i] == y)
            return false;
        if (i + arr[i] == x + y)
            return false;
        if (i - arr[i] == x - y)
            return false;
    }

    return true;
}

void dfs(int deep)
{
    if (deep > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check(deep, i))
        {
            arr[deep] = i;
            dfs(deep + 1);
            arr[deep] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    dfs(1);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
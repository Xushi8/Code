// 2023/08/05 20:35:42
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    set<int> s1, s2;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        s1.emplace(x);
        s2.emplace(y);
    }

    for (int p : s2)
    {
        if (s1.find(p) != s1.end())
        {
            s1.erase(s1.find(p));
        }
    }

    if (s1.size() > 1 || s2.size() != n - 1)
        cout << -1;
    else
        cout << *s1.begin();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
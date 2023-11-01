// 2023/10/31 20:46:36
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
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k);
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        vis[a[i]] = 1;
    }

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        x--;
        if (a[x] + 1 <= n && !vis[a[x] + 1])
        {
            vis[a[x]] = 0;
            vis[a[x] + 1] = 1;
            a[x]++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << a[i] << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
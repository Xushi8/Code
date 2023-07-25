// 2023/07/25 11:23:57
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1005;

int arr[N][N], row[N], col[N], cx[N], cy[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        for (int i = 0; i < n; i++)
            row[i] = i, cx[i] = 0;
        for (int i = 0; i < m; i++)
            col[i] = i, cy[i] = 0;

        while (q--)
        {
            int op, x, y;
            cin >> op >> x >> y;
            if (op == 1)
                swap(row[x - 1], row[y - 1]);
            else if (op == 2)
                swap(col[x - 1], col[y - 1]);
            else if (op == 3)
                cx[row[x - 1]] += y;
            else
                cy[col[x - 1]] += y;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cout << arr[row[i]][col[j]] + cx[row[i]] + cy[col[j]] << " \n"[j == m - 1];
    }

    cout << endl;
    return 0;
}
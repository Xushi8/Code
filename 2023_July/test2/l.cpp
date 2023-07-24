// 2023/07/21 15:52:20
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
const int N = 1000005;

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;

    return true;
}

int f(int x)
{
    int ret = 0;
    while (x > 0)
    {
        x /= 10;
        ret++;
    }

    return ret;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        int tot = 1;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = tot++;
            }
        }

        vector<vector<int>> ans(n);
        if (is_prime(m))
        {
            for (int i = 0, j = 1; i < n / 2; i++, j += 2)
            {
                ans[j] = move(arr[i]);
            }
            for (int i = n / 2, j = 0; i < n; i++, j += 2)
            {
                ans[j] = move(arr[i]);
            }
        }
        else
        {
            ans = move(arr);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%*d ", f(n * m), ans[i][j]);
            }
            putchar('\n');
        }
    }


    cout << endl;
    return 0;
}
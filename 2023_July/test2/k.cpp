// 2023/07/21 15:00:24
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

bool used[N];
int n;

int get_num()
{
    for (int i = 1; i <= 6 * n * n; i++)
        if (!used[i])
        {
            used[i] = 1;
            return i;
        }


    return 0; // no warning
}

int arr[7][105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    // vector<vector<int>> arr[7];
    // for (int i = 1; i <= 6; i++)
    // {
    //     arr[i].resize(n + 1, vector<int>(n + 1, 0));
    // }

    for (int k = 2; k <= 3; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[k][i][j] == 0)
                {
                    arr[k][i][j] = get_num();
                    arr[k + 2][i][n + 1 - j] = 6 * n * n + 1 - arr[k][i][j];
                    // cout << arr[k][i][j] << '\n';
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[1][i][j] == 0)
            {
                arr[1][i][j] = get_num();
                arr[6][n + 1 - i][j] = 6 * n * n + 1 - arr[1][i][j];
                // cout << arr[1][i][j] << '\n';
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[1][i][j] << " \n"[j == n];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int k = 2; k <= 5; k++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << arr[k][i][j] << ' ';
            }
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[6][i][j] << " \n"[j == n];
        }
    }

    cout << endl;
    return 0;
}
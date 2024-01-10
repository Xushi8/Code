// 2023/07/30 16:38:27
#ifndef DEBUG
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
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 55;

char s[N][N];

void solve()
{
    memset(s, '.', sizeof(s));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> (s[i] + 1);
    }

    int dx[] = { -1,-1,-1,0,1,1,1,0 };
    int dy[] = { -1,0,1,1,1,0,-1,-1 };
    int ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            int cnt = 0;

            for (int a = 0; a < 2; a++)
            {
                for (int b = 0; b < 2; b++)
                {
                    cnt += s[i + a][j + b] == '*';
                }
            }

            if (cnt == 3)
            {
                bool flag = 1;
                for (int a = 0; a < 2; a++)
                {
                    for (int b = 0; b < 2; b++)
                    {
                        if (s[i + a][j + b] == '*')
                        {
                            
                            for (int k = 0; k < 8; k++)
                            {
                                int tx = i + a + dx[k];
                                int ty = j + b + dy[k];
                                if (i <= tx && tx < i + 2 && j <= ty && ty < j + 2)
                                    continue;

                                if (s[tx][ty] == '*')
                                {
                                    flag = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
                
                if (flag)
                {
                    ans++;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cnt += s[i][j] == '*';

    if (ans * 3 == cnt)
        cout << "YES\n";
    else
        cout << "NO\n";

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

    cout << endl;
    return 0;
}
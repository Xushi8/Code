// 2023/08/19 20:55:24
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> va(n, 0), vb(m, 0);

    int ans = n * m;
    while (1)
    {
        int change = 0;
        for (int i = 0; i < n; i++)
        {
            if (va[i])
                continue;
            
            int cnt[26] = { 0 };
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 1)
                    continue;

                cnt[s[i][j] - 'a']++;
            }
            int index = -1;
            bool flag = 0;
            for (int k = 0; k < 26; k++)
            {
                if (cnt[k] != 0)
                {
                    if (index == -1)
                        index = k;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                continue;

            if (cnt[index] == 1)
                continue;

            va[i] = 1;
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 1)
                {
                    vis[i][j] = 2;
                    change++;
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (vb[j])
                continue;
            
            int cnt[26] = { 0 };
            for (int i = 0; i < n; i++)
            {
                if (vis[i][j] == 1)
                    continue;

                cnt[s[i][j] - 'a']++;
            }
            int index = -1;
            bool flag = 0;
            for (int k = 0; k < 26; k++)
            {
                if (cnt[k] != 0)
                {
                    if (index == -1)
                        index = k;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                continue;

            if (cnt[index] == 1)
                continue;

            vb[j] = 1;
            for (int i = 0; i < n; i++)
            {
                if (vis[i][j] != 1 && vis[i][j] != 2)
                {
                    vis[i][j] = 2;
                    change++;
                }
            }
        }

        if (change == 0)
            break;
        
        ans -= change;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = !!vis[i][j];
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
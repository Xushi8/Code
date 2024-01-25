// // 2024/01/25 10:08:09
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 6;
// vector<string> s;
// vector<int> siz;
// int dis[N][N];
// int direction[N];
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
// int n, k;
// vector<string> tmp;
// set<vector<string>> st;
// bool valid()
// {
//     tmp = s;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (tmp[i][j] != 'X')
//                 tmp[i][j] = '.';
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (dis[i][j] != -1)
//             {
//                 if (tmp[i][j] == 'X' || tmp[i][j] == 'O')
//                     return false;
//                 int x = i, y = j;
//                 for (int m = 0; m < siz[dis[i][j]]; m++)
//                 {
//                     if (0 <= x && x < n && 0 <= y && y < n && tmp[x][y] == '.')
//                     {
//                         tmp[x][y] = dis[i][j];
//                     }
//                     else
//                     {
//                         return false;
//                     }
//                     x += dx[direction[dis[i][j]]];
//                     y += dy[direction[dis[i][j]]];
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (s[i][j] == 'O' && tmp[i][j] == '.')
//                 return false;
//         }
//     }

//     return true;
// }

// void check(int deep)
// {
//     if (deep == k)
//     {
//         bool ret = valid();
//         if (ret)
//         {
//             st.emplace(tmp);
//         }

//         return;
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         direction[deep] = i;
//         check(deep + 1);
//         direction[deep] = -1;
//     }
// }

// void dfs(int deep)
// {
//     if (deep == k)
//     {
//         check(0);
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (dis[i][j] == -1)
//             {
//                 dis[i][j] = deep;
//                 dfs(deep + 1);
//                 dis[i][j] = -1;
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n >> k;
//     memset(dis, -1, sizeof(dis));
//     memset(direction, -1, sizeof(direction));
//     for (int i = 0; i < n; i++)
//     {
//         // cin >> s[i];
//         string x;
//         cin >> x;
//         s.emplace_back(move(x));
//     }
//     for (int i = 0; i < k; i++)
//     {
//         // cin >> siz[i];
//         int x;
//         cin >> x;
//         siz.emplace_back(x);
//     }

//     dfs(0);
//     // cout << ans << endl;
//     cout << st.size() << endl;

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }
// 2024/01/25 11:09:29
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
vector<string> s, tmp;
// set<vector<string>> st;
ll ans;
vector<vector<string>> ttt;
vector<int> siz;
int n, k;
int dx[] = {0, 1};
int dy[] = {1, 0};

bool check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == 'O' && tmp[i][j] == '.')
                return false;
        }
    }
    return true;
}

void dfs(int now)
{
    if (now == k)
    {
        if (check())
        {
            // st.emplace(tmp);
            // ans++;
            ttt.emplace_back(tmp);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                bool flag = 1;
                int x = i, y = j;
                for (int m = 0; m < siz[now]; m++)
                {
                    if (0 <= x && x < n && 0 <= y && y < n && tmp[x][y] == '.')
                    {
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                    x += dx[k];
                    y += dy[k];
                }
                if (flag)
                {
                    x = i, y = j;
                    for (int m = 0; m < siz[now]; m++)
                    {
                        tmp[x][y] = now;
                        x += dx[k];
                        y += dy[k];
                    }
                    dfs(now + 1);
                    x = i, y = j;
                    for (int m = 0; m < siz[now]; m++)
                    {
                        tmp[x][y] = '.';
                        x += dx[k];
                        y += dy[k];
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    s.resize(n);
    siz.resize(k);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> siz[i];
    }
    sort(siz.begin(), siz.end(), greater<>());
    tmp = s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] != 'X')
            {
                tmp[i][j] = '.';
            }
        }
    }
    dfs(0);
    // cout << st.size() << endl;
    // cout << ans << endl;
    sort(ttt.begin(), ttt.end());
    ttt.erase(unique(ttt.begin(), ttt.end()), ttt.end());
    cout << ttt.size() << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
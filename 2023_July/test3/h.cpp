// 2023/07/25 15:46:05
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


class Point
{
public:
    Point() {}
    Point(int x_, int y_)
    {
        x = x_;
        y = y_;
    }

    int x, y;
};

int n, m, maxn;
bool flag;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

char arr[25][25];
int beginx, beginy, endx, endy;

void dfs(Point p, int dis, set<char>& have)
{
    bool update = 0;
AGAIN:
    
    for (int i = 0; i < 4; i++)
    {
        int tx = p.x + dx[i];
        int ty = p.y + dy[i];
        if (0 <= tx && tx < n && 0 <= ty && ty < m)
        {
            if (arr[tx][ty] == '*')
                continue;

            if (arr[tx][ty] == '.')
            {
                dfs(Point(tx, ty), dis + 1, have);
            }

            if (isalpha(arr[tx][ty]))
            {
                if (islower(arr[tx][ty]))
                {
                    have.emplace(arr[tx][ty]);
                    update = 1;
                    dfs(Point(tx, ty), dis + 1, have);
                }
                else
                {
                    if (have.count(arr[tx][ty]) != 0)
                    {
                        dfs(Point(tx, ty), dis + 1, have);
                    }
                }
            }

            if (tx == endx && ty == endy && !flag)
            {
                if (dis + 1 < maxn)
                {
                    cout << dis + 1 << '\n';
                    flag = 1;
                }
            }
        }
    }

    if (update)
    {
        update = 0;
        goto AGAIN;
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    flag = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '@')
                beginx = i, beginy = j;
            if (arr[i][j] == '^')
                endx = i, endy = j;
        }
    }

    set<char> have;
    dfs(Point(beginx, beginy), 0, have);
    if (!flag)
        cout << -1 << '\n';

    // while (!que.empty())
    // {
    //     Point p = que.front(); que.pop();
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int tx = p.x + dx[i];
    //         int ty = p.y + dy[i];
    //         if (0 <= tx && tx < n && 0 <= ty && ty < m)
    //         {
    //             if (arr[tx][ty] == '*')
    //                 continue;

    //             if (arr[tx][ty] == '.')
    //             if (isalpha(arr[tx][ty]))
    //             {
    //                 if (islower(arr[tx][ty]))
    //                 {
    //                     Point tmp(tx, ty, p.dis + 1, p.have);
    //                     tmp.have.emplace(arr[tx][ty]);
    //                     que.emplace(tmp);
    //                 }
    //                 else
    //                 {
    //                     if (p.have.count(arr[tx][ty]) != 0)
    //                         que.emplace(tx, ty, p.dis + 1, p.have);
    //                 }
    //             }

    //             if (tx == endx && ty == endy)
    //             {
    //                 if (p.dis + 1 < maxn)
    //                     cout << p.dis + 1;
    //                 else
    //                     cout << -1;
    //                 cout << '\n';
    //                 break;
    //             }
    //         }
    //     }
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    while (cin >> n >> m >> maxn)
    {
        solve();
    }


    cout << endl;
    return 0;
}
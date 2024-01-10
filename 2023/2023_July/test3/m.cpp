// 2023/07/24 15:45:12
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;

typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int arr[5][5];
//     bool used[5][5] = { 0 };
//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//             cin >> arr[i][j];

//     vector<pii> ans;
//     queue<pii> que;
//     int dx[] = { 0,1,0,-1 };
//     int dy[] = { 1,0,-1,0 };
//     que.push({ 0, 0 });
//     while (!que.empty())
//     {
//         pii p = que.front(); que.pop();
//         ans.push_back(p);
//         int x = p.first, y = p.second;
//         bool update = 0;
//         for (int i = 0; i < 4; i++)
//         {
//             int tx = x + dx[i];
//             int ty = y + dy[i];
//             if (0 <= tx && tx < 5 && 0 <= ty && ty < 5 && arr[tx][ty] == 0 && !used[tx][ty])
//             {
//                 if (!update)
//                 {
//                     update = 1;
//                 }

//                 que.push({ tx, ty });
//                 used[tx][ty] = 1;

//                 if (tx == 4 && ty == 4)
//                 {
//                     for (size_t j = 0; j < ans.size(); j++)
//                     {
//                         printf("(%d, %d)\n", ans[j].first, ans[j].second);
//                     }

//                     printf("(4, 4)\n");

//                     exit(0);
//                 }
//             }
//         }
//         if (!update)
//             ans.pop_back();
//     }



//     cout << endl;
//     return 0;
// }


class Point
{
public:
    int x, y, dis;
    pair<int, int> par;

    Point() {}
    Point(int x_, int y_, int dis_, pii par_)
    {
        this->x = x_;
        this->y = y_;
        this->dis = dis_;
        this->par = par_;
    }
};

// 2023/07/24 16:11:05
vector<Point> tmp;

void func(pii p)
{
    if (p.first > 4 || p.first < 0 || p.second > 4 || p.second < 0)
        return;

    for (size_t i = 0; i < tmp.size(); i++)
    {
        if (p == make_pair(tmp[i].x, tmp[i].y))
        {
            func(tmp[i].par);
            break;
        }
    }

    printf("(%d, %d)\n", p.first, p.second);
}

int main()
{
    int arr[5][5];
    bool used[5][5] = { 0 };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];

    queue<Point> que;
    que.push({ 0, 0, 0, {-1, -1} });
    while (!que.empty())
    {
        bool flag = 0;
        Point p = que.front(); que.pop();
        tmp.push_back(p);
        int x = p.x, y = p.y;
        int dx[] = { 0,1,0,-1 };
        int dy[] = { 1,0,-1,0 };
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (0 <= tx && tx < 5 && 0 <= ty && ty < 5 && !used[tx][ty] && arr[tx][ty] == 0)
            {
                que.push({ tx, ty, p.dis + 1, {p.x, p.y} });
                used[tx][ty] = 1;
                if (tx == 4 && ty == 4)
                {
                    flag = 1;
                    tmp.push_back(Point(tx, ty, p.dis + 1, make_pair(x, y)));
                    break;
                }
            }
        }
        if (flag)
            break;
    }

    func({4, 4});

    return 0;
}
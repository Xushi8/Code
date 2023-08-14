// 2023/08/14 11:04:03
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

class Point
{
public:
    int x, y;
    pii par;
    Point(int x_, int y_, pii par_)
    {
        x = x_;
        y = y_;
        par = par_;
    }
};
vector<Point> tmp;

void print(int x, int y)
{
    if (x == 0 && y == 0)
    {
        printf("(%d, %d)\n", x, y);
        return;
    }
    for (int i = 0; i < (int)tmp.size(); i++)
    {
        Point p = tmp[i];
        if (p.x == x && p.y == y)
        {
            print(p.par.first, p.par.second);
            break;
        }
    }
    printf("(%d, %d)\n", x, y);

}

int main()
{
    int arr[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];

    queue<Point> que;
    que.push({ 0, 0, make_pair(-1, -1) });
    tmp.push_back({ 0, 0, make_pair(-1, -1) });
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    bool used[5][5] = { 0 };
    while (!que.empty())
    {
        Point p = que.front(); que.pop();
        tmp.push_back(p);
        for (int i = 0; i < 4; i++)
        {
            int tx = p.x + dx[i];
            int ty = p.y + dy[i];
            if (0 <= tx && tx < 5 && 0 <= ty && ty < 5 && !used[tx][ty] && arr[tx][ty] == 0)
            {
                used[tx][ty] = 1;
                que.push({ tx, ty, make_pair(p.x, p.y) });
                tmp.push_back({ tx, ty, make_pair(p.x, p.y) });
            }

            if (tx == 4 && ty == 4)
            {
                print(tx, ty);
                return 0;
            }
        }
    }
    return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

// //BFS

// class point
// {
// public:
//     int x, y, step;
// };
// queue<point> r;
// int a[100][100], v[100][100];
// int dx[4] = { 0,1,0,-1 };
// int dy[4] = { 1,0,-1,0 };
// int p, q, m, n, startx, starty;
// /*
// 5 4
// 1 1 2 1
// 1 1 1 1
// 1 1 2 1
// 1 2 1 1
// 1 1 1 2
// 1 1 4 3
// */

// int main()
// {
//     cin >> m >> n;
//     for (int i = 1; i <= m; i++)
//         for (int j = 1; j <= n; j++)
//             cin >> a[i][j];
//     cin >> startx >> starty >> p >> q;

//     v[startx][starty] = 1;
//     point start;
//     start.x = startx;
//     start.y = starty;
//     start.step = 0;
//     r.push(start);
//     int flag = 0;
//     while (!r.empty())
//     {
//         int x = r.front().x;
//         int y = r.front().y;
//         if (x == p && y == q)
//         {
//             cout << r.front().step;
//             flag = 1;
//             break;
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             int tx, ty;
//             tx = x + dx[i];
//             ty = y + dy[i];
//             if (v[tx][ty] == 0 && a[tx][ty] == 1)
//             {
//                 point tmp;
//                 tmp.x = tx;
//                 tmp.y = ty;
//                 tmp.step = r.front().step + 1;
//                 r.push(tmp);
//                 v[tx][ty] = 1;
//             }
//         }
//         r.pop();
//     }

//     if (flag == 0)
//     {
//         cout << "NO" << endl;
//     }

//     return 0;
// }

//DFS

int min_step = 2147483647;
int endx, endy, beginx,beginy;
int arr[100][100], v[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3
*/
void dfs(int x, int y, int step)
{
    if (x == endx && y == endy)
    {
        if (step < min_step)
        {
            min_step = step;
        }
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int tx, ty;
        tx = x + dx[k];
        ty = y + dy[k];
        if (arr[tx][ty] == 1 && v[tx][ty] == 0)
        {
            v[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            v[tx][ty] = 0;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    cin >> beginx >> beginy >> endx >> endy;
    dfs(beginx, beginy, 0);
    cout << min_step << endl;


    return 0;
}
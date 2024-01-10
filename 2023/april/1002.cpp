// 2023/04/26 20:32:21
#include <bits/stdc++.h>
using namespace std;


const int inf = 0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int endx, endy, mx, my;
    cin >> endx >> endy >> mx >> my;
    vector<vector<int>> arr(endx + 1, vector<int>(endy + 1, 0));
    arr[0][0] = 1;
    for (int i = 0; i < 8; i++)
    {
        int dx[] = { -1,-2,-2,-1,1,2,2,1 };
        int dy[] = { -2,-1,1,2,-2,-1,1,2 };
        int tx = mx + dx[i];
        int ty = my + dy[i];
        if (tx >= 0 && tx <= endx && ty >= 0 && ty <= endy)
        {
            arr[tx][ty] = inf;
        }
    }
    int dx[] = { 0,1 };
    int dy[] = { 1,0 };
        

    cout << endl;
    return 0;
}
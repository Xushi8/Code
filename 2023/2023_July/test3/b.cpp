// 2023/07/24 14:39:02
#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;

int ans = -1;
vector<string> arr(4);

bool check()
{
    char target = arr[0][0];    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (arr[i][j] != target)
                return false;
    return true;
}

void change(int x, int y)
{
    arr[x][y] = arr[x][y] == 'b' ? 'w' : 'b';
    if (0 <= x - 1 && x - 1 <= 3)
        arr[x - 1][y] = arr[x - 1][y] == 'b' ? 'w' : 'b';
    if (0 <= y - 1 && y - 1 <= 3)
        arr[x][y - 1] = arr[x][y - 1] == 'b' ? 'w' : 'b';
    if (0 <= y + 1 && y + 1 <= 3)
        arr[x][y + 1] = arr[x][y + 1] == 'b' ? 'w' : 'b';
    if (0 <= x + 1 && x + 1 <= 3)
        arr[x + 1][y] = arr[x + 1][y] == 'b' ? 'w' : 'b';
}

void dfs(int x, int y, int cnt)
{
    if (check())
    {
        if (ans == -1)
            ans = cnt;
        else if (ans > cnt)
            ans = cnt;
        return;
    }

    if (x == 4)
        return;

    change(x, y);

    if (y == 3)
        dfs(x + 1, 0, cnt + 1);
    else
        dfs(x, y + 1, cnt + 1);

    change(x, y);

    if (y == 3)
        dfs(x + 1, 0, cnt);
    else
        dfs(x, y + 1, cnt);


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    dfs(0, 0, 0);

    if (ans == -1)
        cout << "Impossible\n";
    else
        cout << ans << '\n';

    cout << endl;
    return 0;
}
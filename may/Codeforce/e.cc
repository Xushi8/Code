// 2023/05/06 23:26:03
#include <bits/stdc++.h>
using namespace std;

int n, m;
void find(int i, int j, const vector<vector<int>>& arr, vector<vector<int>>& used, int& tmp)
{
    int dx[] = { 0,1,0,-1 };
    int dy[] = { 1,0,-1,0 };
    if (arr[i][j] != 0)
    {
        tmp += arr[i][j];
        for (int k = 0; k < 4; k++)
        {
            int tx = i + dx[k];
            int ty = j + dy[k];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && !used[tx][ty])
            {
                used[tx][ty] = 1;
                find(tx, ty, arr, used, tmp);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        vector<vector<int>> used(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        int ans = 0;
        int dx[] = { 0,1,0,-1 };
        int dy[] = { 1,0,-1,0 };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!used[i][j])
                {
                    used[i][j] = 1;
                    if (arr[i][j] != 0)
                    {
                        int tmp = arr[i][j];
                        for (int k = 0; k < 4; k++)
                        {
                            int tx = i + dx[k];
                            int ty = j + dy[k];
                            if (0 <= tx && tx < n && 0 <= ty && ty < m && !used[tx][ty])
                            {
                                used[tx][ty] = 1;
                                find(tx, ty, arr, used, tmp);
                            }
                        }
                        ans = max(ans, tmp);
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    cout << endl;
    return 0;
}
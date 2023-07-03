// 2023/04/27 13:56:59
#include <bits/stdc++.h>
using namespace std;

pair<int, int> find(const vector<vector<int>>& arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == target)
            {
                return make_pair(i, j);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    arr[0][n / 2] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        pair<int, int> pos = find(arr, i - 1);
        if (pos.first == 0 && pos.second != n - 1)
        {
            arr[n - 1][pos.second + 1] = i;
        }
        else if (pos.first != 0 && pos.second == n - 1)
        {
            arr[pos.first - 1][0] = i;
        }
        else if (pos.first == 0 && pos.second == n - 1)
        {
            arr[pos.first + 1][pos.second] = i;
        }
        else
        {
            if (arr[pos.first - 1][pos.second + 1] == 0)
            {
                arr[pos.first - 1][pos.second + 1] = i;
            }
            else
            {
                arr[pos.first + 1][pos.second] = i;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << endl;
    return 0;
}
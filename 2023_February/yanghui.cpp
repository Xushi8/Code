#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int f(int x, int y)
{
    if (y == 0 || y == x)
    {
        return 1;
    }
    else
    {
        return f(x - 1, y) + f(x - 1, y - 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << ' ';
        }
            for (int j = 0; j <= i; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
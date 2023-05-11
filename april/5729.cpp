// 2023/04/27 13:47:34
#include <bits/stdc++.h>
using namespace std;


int arr[25][25][25];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                arr[i][j][k] = 1;
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        a--;b--;c--;d--;e--;f--;
        for (int i = a; i <= d; i++)
        {
            for (int j = b; j <= e; j++)
            {
                for (int k = c; k <= f; k++)
                {
                    arr[i][j][k] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                ans += arr[i][j][k];
            }
        }
    }
    cout << ans;

    cout << endl;
    return 0;
}
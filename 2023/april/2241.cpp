// 2023/04/26 19:34:53
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    long long a = 0, b = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a += min(i, j);
            b += i * j;
        }
    }
    cout << a << ' ' << b - a;

    cout << endl;
    return 0;
}
// 2023/06/06 20:45:31
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int a = -1, b, c = -1, d;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == 'o')
            {
                if (a == -1)
                {
                    a = i;
                    b = j;
                }
                else
                {
                    c = i;
                    d = j;
                    break;
                }
            }
        }
    }
    
    int ans = abs(a - c) + abs(b - d);
    cout << ans;

    cout << endl;
    return 0;
}
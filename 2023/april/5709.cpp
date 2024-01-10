// 2023/04/26 22:49:33
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    if (b == 0)
    {
        cout << 0;
    }
    else
    {
        int ans =  a - c / b - (c % b != 0);
        if (ans < 0) ans = 0;
        cout << ans;
    }

    cout << endl;
    return 0;
}
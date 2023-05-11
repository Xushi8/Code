// 2023/04/27 12:02:41
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i;
    }
    cout << ans;

    cout << endl;
    return 0;
}
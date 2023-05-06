// 2023/04/27 11:58:27
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int ans = 0;
    while (n != 1)
    {
        n /= 2;
        ans++;
    }
    cout << ++ans;

    cout << endl;
    return 0;
}
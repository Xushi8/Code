// 2023/06/06 20:38:55
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    if ((a <= b && b <= c) || (c <= b && b <= a))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    cout << endl;
    return 0;
}
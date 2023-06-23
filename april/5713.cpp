// 2023/04/26 22:39:14
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a, b;
    a = 5 * n;
    b = 3 * n + 11;
    if (a > b) cout << "Luogu";
    else cout << "Local";

    cout << endl;
    return 0;
}
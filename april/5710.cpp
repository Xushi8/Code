// 2023/04/26 22:45:03
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout << (n % 2 == 0 && 4 < n && n <= 12) << ' ' << ((n % 2 == 0) || (4 < n && n <= 12)) << ' ' << ((n % 2 == 0) ^ (4 < n && n <= 12)) << ' ' << (!(n % 2 == 0) && !(4 < n && n <= 12));

    cout << endl;
    return 0;
}
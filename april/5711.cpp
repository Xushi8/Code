// 2023/04/26 22:42:47
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
    {
        cout << 1;
    }
    else
        cout << 0;

    cout << endl;
    return 0;
}
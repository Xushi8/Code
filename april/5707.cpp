// 2023/04/26 22:21:30
#include <bits/stdc++.h>
using namespace std;



int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    int sum = a / b + (a % b != 0) + 10;
    int m = 8, n = 60;
    m -= 1 + sum / 60;
    if (sum % 60 == 0)
    {
        m++;
    }
    if (m < 0)
    {
        m += 24;
    }
    
    n -= sum % 60;
    if (sum % 60 == 0)
    {
        n = 0;
    }
    printf("%02d:%02d", m, n);

    cout << endl;
    return 0;
}
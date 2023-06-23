// 2023/04/26 22:35:38
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double a, b;
    cin >> a >> b;
    double ans = a / (b * b);
    if (ans >= 24.0)
    {
        cout << ans << '\n' << "Overweight";
    }
    else if (ans < 18.5)
    {
        cout << "Underweight";
    }
    else
    {
        cout << "Normal";
    }

    cout << endl;
    return 0;
}
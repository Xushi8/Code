// 2023/05/25 11:53:59
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        pair<double, double> p1;
        p1.first = c - a;
        p1.second = d - b;
        cin >> a >> b >> c >> d;
        pair<double, double> p2;
        p2.first = c - a;
        p2.second = d - b;
        if (fabs(p1.first * p2.second - p1.second * p2.first) < 1e-6)
            cout << 2 << '\n';
        else if (fabs(p1.first * p2.first + p1.second * p2.second) < 1e-6)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}
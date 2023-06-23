// 2023/05/25 14:21:18
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    cout << setprecision(8) << fixed;
    while (tt--)
    {
        double x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        double b1 = (y2 - y1) * x1 + (x1 - x2) * y1;
        double b2 = (y4 - y3) * x3 + (x3 - x4) * y3;
        double d = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
        double d1 = b2 * (x2 - x1) - b1 * (x4 - x3);
        double d2 = b2 * (y2 - y1) - b1 * (y4 - y3);
        double ans1 = d1 / d;
        double ans2 = d2 / d;
        cout << ans1 << ' ' << ans2 << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}
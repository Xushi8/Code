// 2023/05/25 17:18:39
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (fabs(dis - r1 - r2) < 1e-6)
    {
        cout << 3 << '\n';
    }
    else if (fabs(dis + min(r1, r2) - max(r1, r2)) < 1e-6)
    {
        cout << 1 << '\n';
    }
    else if (dis > r1 + r2)
    {
        cout << 4 << '\n';
    }
    else if (dis + min(r1, r2) < max(r1, r2))
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}
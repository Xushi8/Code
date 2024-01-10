// 2023/05/25 15:03:29
#include <bits/stdc++.h>
using namespace std;

// struct Point
// {
//     Point() {}
//     Point(double _x, double _y)
//     {
//         x = _x; y = _y;
//     }
//     double x, y;
// };


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (x1 > x2)
    {
        swap(x1, x2);
        swap(r1, r2);
        swap(y1, y2);
    }

    double dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double degree = acos((r1 * r1 + dis * dis - r2 * r2) / (2 * r1 * dis));
    double degree1 = atan((y2 - y1) / (x2 - x1));
    double ans1 = x1 + r1 * cos(degree1 + degree);
    double ans2 = y1 + r1 * sin(degree1 + degree);
    double ans3 = x1 + r1 * cos(degree1 - degree);
    double ans4 = y1 + r1 * sin(degree1 - degree);
    cout << setprecision(10) << fixed;
    if (ans1 > ans3)
    {
        swap(ans1, ans3);
        swap(ans2, ans4);
    }
    else if (fabs(ans1 - ans3) < 1e-6)
    {
        if (ans2 > ans4)
        {
            swap(ans1, ans3);
            swap(ans2, ans4);
        }
    }

    cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << '\n';

    cout << flush;
    system("pause");
    return 0;
}
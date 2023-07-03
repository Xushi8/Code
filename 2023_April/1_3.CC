// 2023/05/25 10:42:19
#include <bits/stdc++.h>
using namespace std;

inline double get_dis(double a, double b, double c, double d)
{
    return sqrt((d - b) * (d - b) + (c - a) * (c - a));
}

inline pair<double, double> danweihua(double a, double b, double c, double d)
{
    double x = c - a;
    double y = d - b;
    return make_pair(x, y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double dis = get_dis(a, b, c, d);
    pair<double, double> z = danweihua(a, b, c, d);
    int tt;
    cin >> tt;
    double x, y;
    while (tt--)
    {
        cin >> x >> y;
        if (fabs(x - a) <= 1e-6 && fabs(y - b) <= 1e-6)
        {
            cout << "ON_SEGMENT\n";
        }
        else
        {
            auto tmp = danweihua(a, b, x, y);
            double ans = z.first * tmp.second - z.second * tmp.first;
            if (ans > 1e-6)
            {
                cout << "COUNTER_CLOCKWISE\n";
            }
            else if (ans < -1e-6)
            {
                cout << "CLOCKWISE\n";
            }
            else
            {
                if (z.first * tmp.first + z.second * tmp.second < -1e-6)
                    cout << "ONLINE_BACK\n";
                else
                {
                    double tmp_dis = get_dis(a, b, x, y);
                    if (dis < tmp_dis)
                        cout << "ONLINE_FRONT\n";
                    else
                        cout << "ON_SEGMENT\n";
                }

            }

            
            // if (fabs(ans - 0.) <= 1e-6)
            // {
            //     if (tmp.first * z.first + tmp.second * z.second < 0)
            //     {
            //         cout << "ONLINE_BACK\n";
            //     }
            //     else
            //     {
            //         double tmp_dis = get_dis(a, b, x, y);
            //         if (dis > tmp_dis) cout << "ON_SEGMENT\n";
            //         else cout << "ONLINE_FRONT\n";
            //     }
            // }
            // else if (ans > 0)
            // {
            //     cout << "COUNTER_CLOCKWISE\n";
            // }
            // else
            // {
            //     cout << "CLOCKWISE\n";
            // }
        }
    }

    cout << flush;
    system("pause");
    return 0;
}
// 2023/05/25 11:59:38
#include <bits/stdc++.h>
using namespace std;

// inline int chacheng(int a, int b, int c, int d, int e, int f, int g, int h)
// {
//     int res;
//     res = (c - a) * (h - f) - (d - b) * (g - e);
//     return res;
// }


struct line
{
    double x1, y1, x2, y2;
};

bool RapidRejExper(line& l1, line& l2) {
    if ((l1.x1 > l1.x2 ? l1.x1 : l1.x2) < (l2.x1 < l2.x2 ? l2.x1 : l2.x2) ||
        (l1.y1 > l1.y2 ? l1.y1 : l1.y2) < (l2.y1 < l2.y2 ? l2.y1 : l2.y2) ||
        (l2.x1 > l2.x2 ? l2.x1 : l2.x2) < (l1.x1 < l1.x2 ? l1.x1 : l1.x2) ||
        (l2.y1 > l2.y2 ? l2.y1 : l2.y2) < (l1.y1 < l1.y2 ? l1.y1 : l1.y2)) {
        return false;
    }
    return true;
}

// 跨立实验
bool Cross(line& l1, line& l2) {
    if ((((l1.x1 - l2.x1) * (l2.y2 - l2.y1) - (l1.y1 - l2.y1) * (l2.x2 - l2.x1)) *
        ((l1.x2 - l2.x1) * (l2.y2 - l2.y1) - (l1.y2 - l2.y1) * (l2.x2 - l2.x1))) > 0 ||
        (((l2.x1 - l1.x1) * (l1.y2 - l1.y1) - (l2.y1 - l1.y1) * (l1.x2 - l1.x1)) *
            ((l2.x2 - l1.x1) * (l1.y2 - l1.y1) - (l2.y2 - l1.y1) * (l1.x2 - l1.x1))) > 0)
    {
        return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        line l1, l2;
        cin >> l1.x1 >> l1.y1 >> l1.x2 >> l1.y2;
        cin >> l2.x1 >> l2.y1 >> l2.x2 >> l2.y2;
        if (RapidRejExper(l1, l2) && Cross(l1, l2)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
        
        // int a, b, c, d, e, f, g, h;
        // cin >> a >> b >> c >> d;
        // cin >> e >> f >> g >> h;
        // if (max(e, g) < min(a, c) || max(f, h) < min(b, d) ||
        //     max(a, c) < min(e, g) || max(b, d) < min(f, h))
        //     cout << 0 << '\n';
        // else if (chacheng(a, b, c, d, a, b, e, f) * chacheng(a, b, c, d, a, b, g, h) > 0 || 
        //          chacheng(e, f, g, h, e, f, a, b) * chacheng(e, f, g, h, e, f, c, d) > 0)
        //     cout << 0 << '\n';
        // else
        //     cout << 1 << '\n';

    }

    cout << flush;
    system("pause");
    return 0;
}
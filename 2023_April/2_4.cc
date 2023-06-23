// 2023/05/25 14:41:47
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
    Point(double _x = 0., double _y = 0.)
    {
        x = _x;
        y = _y;
    }

    double abs()
    {
        return sqrt(norm());
    }
    
    double norm()
    {
        return x * x + y * y;
    }
};

double dot(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(Point a, Point b)
{
    return abs(a.x * b.y - a.y * b.x);
}

double getDistancePP(Point a, Point b)
{
    Point c(b.x - a.x, b.y - a.y);
    return  c.abs();
}

double getDistancePL(Point a, Point b, Point c)
{
    Point ab(b.x - a.x, b.y - a.y);
    Point ac(c.x - a.x, c.y - a.y);

    return cross(ab, ac) / ab.abs();
}

double getDistancePS(Point a, Point b, Point c)
{
    Point ab(b.x - a.x, b.y - a.y);
    Point ba(a.x - b.x, a.y - b.y);
    Point ac(c.x - a.x, c.y - a.y);
    Point bc(c.x - b.x, c.y - b.y);

    if (dot(ab, ac) < 0.0) return getDistancePP(a, c);
    if (dot(ba, bc) < 0.0) return getDistancePP(b, c);

    return getDistancePL(a, b, c);
}

double getDistanceSS(Point a, Point b, Point c, Point d)
{
    return min({ getDistancePS(c, d, a), getDistancePS(c, d, b), getDistancePS(a, b, c), getDistancePS(a, b, d) });
}


struct line
{
    line(double _x1, double _y1, double _x2, double _y2)
    {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
    
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
    cout << setprecision(8) << fixed;
    while (tt--)
    {
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        line l1(p1.x, p1.y, p2.x, p2.y), l2(p3.x, p3.y, p4.x, p4.y);
        if (RapidRejExper(l1, l2) && Cross(l1, l2))
            cout << 0. << '\n';
        else
            cout << getDistanceSS(p1, p2, p3, p4) << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}
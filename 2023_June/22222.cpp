#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

#define COUNTER_CLOCKWISE -1 //逆时针
#define CLOCKWISE 1          //顺时针
#define ONLINE_BACK -2       //p2 p0 p1依次排列在一条直线上
#define ONLINE_FRONT 2       //p0 p1 p2依次排列在一条直线上
#define ON_SEGMENT 0         //p2在线段p0p1上

#define EPS 1E-8

class Point
{
public:
    double x, y;
    Point()
    {
    }
    Point(double x, double y)
    {
        (*this).x = x;
        (*this).y = y;
    }

    double operator^(const Point& p) const //叉乘
    {
        return x * p.y - y * p.x;
    }

    double operator*(const Point& p) const //点乘
    {
        return x * p.x + y * p.y;
    }

    Point operator*(const double& d) const
    {
        return Point(x * d, y * d);
    }

    Point operator/(const double& d) const
    {
        return Point(x / d, y / d);
    }

    Point operator-(const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }

    Point operator+(const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }

    double sqr()
    {
        return x * x + y * y;
    }
    double abs()
    {
        return sqrt(sqr());
    }

    double distance(const Point& p)
    {
        return fabs((*this - p).abs());
    }

    void print()
    {

        printf("%.8lf %.8lf", x, y);
    }
};

class Line
{
public:
    Point p1, p2;
    Point vec;
    Line()
    {
    }
    Line(Point p1, Point p2)
    {
        (*this).p1 = p1;
        (*this).p2 = p2;
        (*this).vec = p2 - p1;
    }
};

class Circle
{
public:
    Point o;
    double r;
    Circle()
    {
    }

    Circle(Point o, double r)
    {
        (*this).o = o;
        (*this).r = r;
    }

    Circle(double cx, double cy, double r)
    {
        (*this).o.x = cx;
        (*this).o.y = cy;
        (*this).r = r;
    }
};

double get_distance_LP(const Line& line, const Point& p) //点到直线的距离
{
    return fabs((p - line.p1) ^ (line.p1 - line.p2) / (line.p1 - line.p2).abs());
}

pair<Point, Point> get_Cross_Points(Circle c, Line l)
{
    //l.p1.print();
    Point pr = l.p1 + (l.vec) * ((c.o - l.p1) * l.vec) / (l.vec.sqr());

    double base = sqrt(c.r * c.r - (pr - c.o).sqr());
    if (base <= EPS) //只有一个交点
    {
        return make_pair(pr, pr);
    }

    //有两个交点
    Point e = (l.vec) / l.vec.abs();

    return make_pair(pr + e * base, pr - e * base);
}

int main()
{
    double cx, cy, r;
    cin >> cx >> cy >> r;
    Circle c(cx, cy, r);

    int q;
    cin >> q;

    while (q--)
    {
        Line l = Line();
        cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
        l.vec = l.p2 - l.p1;
        auto ans = get_Cross_Points(c, l);
        //ans.first.print();
        if (ans.first.x < ans.second.x)
        {
            ans.first.print();
            cout << ' ';
            ans.second.print();
            cout << endl;
        }
        else if (ans.second.x < ans.first.x)
        {
            ans.second.print();
            cout << ' ';
            ans.first.print();
            cout << endl;
        }
        else
        {
            if (ans.first.y - ans.second.y <= EPS)
            {
                ans.first.print();
                cout << ' ';
                ans.second.print();
                cout << endl;
            }
            else
            {
                ans.second.print();
                cout << ' ';
                ans.first.print();
                cout << endl;
            }
        }
    }
}
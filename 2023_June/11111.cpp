#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const double eps = 1e-10;
const double pi = acos(-1.0);

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

int dcmp(double x)
{
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }

Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }

Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }

Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y / p); }

bool operator < (const Point& a, const Point& b)
{
    return a.x < b.x || (!dcmp(a.x - b.x) && a.y < b.y);
}

bool operator == (const Point& a, const Point& b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }

double Length(Vector A) { return sqrt(Dot(A, A)); }

double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }

double angle(Vector v) { return atan2(v.y, v.x); }

double angtox(Vector v)
{
    double ang = angle(v);
    if (dcmp(ang) < 0) ang += pi;
    if (dcmp(ang - pi) >= 0) ang -= pi;
    return ang;
}

double dis2(Point A, Point B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

double dis(Point A, Point B) { return sqrt(dis2(A, B)); }

Vector Rotate(Vector A, double rad)
{
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

Vector Normal(Vector A)
{
    double L = Length(A);
    return Vector(-A.y / L, A.x / L);
}

struct Line
{
    Point v, p;
    Vector dir;
    double ang;

    Line() { }
    Line(Point v, Point p) :v(v), p(p) { dir = p - v; ang = atan2(dir.y, dir.x); }
    bool operator < (const Line& L) const
    {
        return ang < L.ang;
    }
    Point point(double t)
    {
        return v + dir * t;
    }
};

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}

Point GetLineIntersection(Line L1, Line L2)
{
    return GetLineIntersection(L1.v, L1.dir, L2.v, L2.dir);
}

double DistanceToLine(Point P, Point A, Point B)
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1);
}

double DistanceToLine(Point P, Line L)
{
    return DistanceToLine(P, L.v, L.p);
}

Point GetLineProjection(Point P, Point A, Point B)
{
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
}

Point GetLineProjection(Point P, Line L)
{
    return GetLineProjection(P, L.v, L.p);
}

struct Circle
{
    Point c;
    double r;
    Circle(Point c = Point(0, 0), double r = 0) :c(c), r(r) {}
    Point point(double a)
    {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

Circle Excenter(Point a, Point b, Point c)
{
    double a1 = b.x - a.x;
    double b1 = b.y - a.y;
    double c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x;
    double b2 = c.y - a.y;
    double c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    Point O = Point(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
    double r = dis(O, a);
    return Circle(O, r);
}

Circle getNqc(Point a, Point b, Point c)
{
    double C = dis(a, b);
    double B = dis(a, c);
    double A = dis(b, c);
    Circle cir;
    cir.c.x = (A * a.x + B * b.x + C * c.x) / (A + B + C);
    cir.c.y = (A * a.y + B * b.y + C * c.y) / (A + B + C);
    cir.r = sqrt((A + B - C) * (A - B + C) * (-A + B + C) / (A + B + C)) / 2;
    return cir;
}

int getTangents(Point p, Circle C, Vector* v)
{
    Vector u = C.c - p;
    double dist = Length(u);
    if (dcmp(dist - C.r) < 0) return 0;
    else if (dcmp(dist - C.r) == 0)  //p在圆上
    {
        v[0] = Rotate(u, pi / 2);
        return 1;
    }
    else
    {
        double ang = asin(C.r / dist);
        v[0] = Rotate(u, -ang);
        v[1] = Rotate(u, ang);
        return 2;
    }
}

int getLineCircleIntersection(Line a, Circle b, vector<Point>& res)
{
    double h = DistanceToLine(b.c, a);
    if (dcmp(b.r - h) < 0) return 0;
    Point c = GetLineProjection(b.c, a);
    if (!dcmp(h - b.r))
    {
        res.push_back(c);
        return 1;
    }
    double w = sqrt(b.r * b.r - h * h);
    res.push_back(c + a.dir / Length(a.dir) * w); //直线L的单位向量
    res.push_back(c - a.dir / Length(a.dir) * w);
    sort(res.begin(), res.end());
    return 2;
}

vector<Point> Circle_Through_A_Point_And_Tangent_To_A_Line_With_Radius(Point a, Line b, double r)
{
    vector<Point> res;
    Vector c = Normal(b.dir);
    Circle k(a, r);
    Point p = b.v + c * r, q = b.v - c * r;
    Line L1 = Line(p, p + b.dir), L2 = Line(q, q + b.dir);
    getLineCircleIntersection(L1, k, res);
    getLineCircleIntersection(L2, k, res);
    sort(res.begin(), res.end());
    return res;
}

vector<Point> Circle_Tangent_To_Two_Lines_With_Radius(Line L1, Line L2, double r)
{
    vector<Point> res;
    Vector n1 = Normal(L1.dir), n2 = Normal(L2.dir);

    Point p1 = L1.v + n1 * r, p2 = L1.v - n1 * r, q1 = L2.v + n2 * r, q2 = L2.v - n2 * r;
    Line L3(p1, p1 + L1.dir), L4(p2, p2 + L1.dir), L5(q1, q1 + L2.dir), L6(q2, q2 + L2.dir);
    Point O[5];
    O[1] = GetLineIntersection(L3, L5), O[2] = GetLineIntersection(L3, L6),
        O[3] = GetLineIntersection(L4, L5), O[4] = GetLineIntersection(L4, L6);
    for (int i = 1;i <= 4;i++) res.push_back(O[i]);
    sort(res.begin(), res.end());
    return res;
}

int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol)
{
    double d = Length(C1.c - C2.c);
    if (dcmp(d) == 0)
    {
        if (dcmp(C1.r - C2.r) == 0) return -1;
        return 0;
    }
    if (dcmp(C1.r + C2.r - d) < 0) return 0;
    if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;

    double a = angle(C2.c - C1.c);
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);

    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

void print(vector<Point>& res)
{
    int num = res.size();
    printf("[");
    for (int i = 0;i < num - 1;i++) printf("(%lf,%lf),", res[i].x, res[i].y);
    if (num > 0) printf("(%lf,%lf)", res[num - 1].x, res[num - 1].y);
    printf("]\n");
}

Point V[10];
char str[100];

int main()
{


    for (int i = 0;i < 3;i++) scanf("%lf%lf", &V[i].x, &V[i].y);
    Circle C = getNqc(V[0], V[1], V[2]);
    printf("%.10lf %.10lf %.10lf\n", C.c.x, C.c.y, C.r);

    return 0;
}

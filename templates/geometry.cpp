#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 二维向量
const double PI = acosl(-1);
const double EPS = 1e-10;

struct Vector2
{
    double x, y;
    explicit Vector2(double x_ = 0, double y_ = 0) :
        x(x_), y(y_) {}

    // 比较两个向量
    bool operator==(const Vector2& vec) const
    {
        return fabs(x - vec.x) < EPS && fabs(y - vec.y) < EPS;
    }
    bool operator<(const Vector2& vec) const
    {
        if (fabs(x - vec.x) < EPS)
            return y < vec.y;
        return x < vec.x;
    }

    // 向量的加法和减法
    Vector2 operator+(const Vector2& vec) const
    {
        return Vector2(x + vec.x, y + vec.y);
    }
    Vector2 operator-(const Vector2& vec) const
    {
        return Vector2(x - vec.x, y - vec.y);
    }

    // 向量的数乘
    Vector2 operator*(double a) const
    {
        return Vector2(x * a, y * a);
    }

    // 向量的模
    double norm() const
    {
        return hypot(x, y);
    }

    // 返回方向相同的单位向量
    // 零向量不可调用
    Vector2 normalize() const
    {
        return Vector2(x / norm(), y / norm());
    }

    // 从 x 轴正方向转到当前向量的角度
    double polar() const
    {
        // atan2 返回 (-PI, PI]，修正为 [0，2PI)
        // fmod 求两个实数相除的余数
        return fmod(atan2(y, x) + 2 * PI, 2 * PI);
    }

    // 内积
    double dot(const Vector2& vec) const
    {
        return x * vec.x + y * vec.y;
    }
    double cross(const Vector2& vec) const
    {
        return x * vec.y - y * vec.x;
    }

    // 当前向量映射到另一向量的结果
    // vec的长度需要大于0
    Vector2 project(const Vector2& vec) const
    {
        Vector2 r = vec.normalize();
        return r * r.dot(*this);
    }

    // 两个向量的夹角
    // 两个向量长度均需要大于 0
    double insersection_angle(const Vector2& vec) const
    {
        return acos(dot(vec) / norm() * vec.norm());
    }

    // 判断两个向量是否垂直
    // 两个向量长度均需要大于 0
    bool perpendicular(const Vector2& vec) const
    {
        return fabs(dot(vec)) < EPS;
    }

    // 平行四边形面积
    double parallelogram_area(const Vector2& vec) const
    {
        return fabs(cross(vec));
    }

    // 三角形面积，可以扩找到多边形
    double triangle_area(const Vector2& vec) const
    {
        return fabs(cross(vec)) / 2;
    }
};

// 凸包的面积
double area(const vector<Vector2>& p)
{
    double ans = 0.0;
    int n = p.size();
    for (int i = 0; i < n; ++i)
        ans += p[i].cross(p[(i + 1) % n]);
    return fabs(ans) / 2.0;
}

// 两点的距离
double dis(const Vector2& a, const Vector2& b)
{
    return (a - b).norm();
}

// 判定两个向量的方向
// ccw: counter clock wise
double ccw(const Vector2& a, const Vector2& b)
{
    // 正数: b 在 a 的逆时针 180 度内
    // 负数: b 在 a 的顺时针 180 度内
    // 0: 平行
    return a.cross(b);
}
double ccw(const Vector2& p, const Vector2& a, const Vector2& b)
{
    // 正数: 以 p 为基准点时，b 在 a 的逆时针 180 度内
    // 负数: 以 p 为基准点时，b 在 a 的顺时针 180 度内
    return ccw(a - p, b - p);
}

// 求凸包
vector<Vector2> convex_hull(vector<Vector2>& p)
{
    int n = p.size();
    sort(p.begin(), p.end());
    vector<Vector2> result(n * 2);
    int k = 0; // 当前的凸包点个数，即 result.size()
    // 构造凸包的下侧
    for (int i = 0; i < n; ++i)
    {
        while (k > 1 && (result[k - 1] - result[k - 2]).cross(p[i] - result[k - 1]) < 0)
            --k;
        result[k++] = p[i];
    }
    // 构造凸包的上侧
    int t = k;
    for (int i = n - 2; i >= 0; --i)
    {
        while (k > t && (result[k - 1] - result[k - 2]).cross(p[i] - result[k - 1]) < 0)
            --k;
        result[k++] = p[i];
    }
    result.resize(k - 1);
    return result;
}

double polygan_diameter(const vector<Vector2>& p)
{
    // p 以逆时针给出凸多边形的顶点
    int n = p.size();
    // 找最左端和最右端的点
    int left = min_element(p.begin(), p.end()) - p.begin();
    int right = max_element(p.begin(), p.end()) - p.begin();
    // 分别向 p[left] 和  p[right] 加垂线，两条垂涎有相反方向
    // 标出 a 的方向
    Vector2 calipersA(0, 1); // 卡尺的方向向量
    double ans = (p[right] - p[left]).norm();
    // toNext[i] := p[i] 到下一个顶点方向的单位向量
    vector<Vector2> toNext(n);
    for (int i = 0; i < n; ++i)
    {
        // normalize() 返回方向相同的单位向量
        toNext[i] = (p[(i + 1) % n] - p[i]).normalize();
    }
    // a, b 分别表示两条直线正在以哪个顶点为中心旋转
    int a = left, b = right;
    // 一直执行到两条直线旋转半圈后方向互换为止
    while (a != right || b != left)
    {
        // 查看 a, b 哪个到下一个顶点的角度更小
        double cosThetaA = calipersA.dot(toNext[a]);
        double cosThetaB = -calipersA.dot(toNext[b]);
        if (cosThetaA > cosThetaB)
        {
            // ThetaA < ThetaB
            // [0, PI] 的余弦值递减，不用计算实际角度就可以比较角度的大小关系
            calipersA = toNext[a];
            a = (a + 1) % n;
        }
        else
        {
            calipersA = toNext[b] * (-1);
            b = (b + 1) % n;
        }
        ans = max(ans, (p[a] - p[b]).norm());
    }
    return ans;
}

// 返回凸包直径
double get_D(vector<Vector2> const& vec)
{
    auto t = vec;
    vector<Vector2> ch = convex_hull(t);
    double D = polygan_diameter(ch);
    return D;
}

// 返回点 P 以点 O 为圆心逆时针旋转 alpha 后所在的位置
Vector2 rotate(Vector2 O, double alpha, Vector2 P)
{
    Vector2 new_P;
    Vector2 OP = P - O;
    new_P.x = OP.x * cos(alpha) - OP.y * sin(alpha) + O.x;
    new_P.y = OP.y * cos(alpha) + OP.x * sin(alpha) + O.y;
    return new_P;
}

// 直线
struct Line
{
    // line: a+pb, a 是点, b 是方向向量
    Vector2 a;
    Vector2 b;
    double deg; // 极角
    Line(Vector2 a, Vector2 b) :
        a(a), b(b)
    {
        deg = b.polar();
    }
    bool operator<(const Line& l) const
    {
        // 方向向量的极角序
        return deg < l.deg;
    }
};

bool on_left(const Line& l, const Vector2& p)
{
    // 点 p 是否在有向直线 l 左侧
    return l.b.cross(p - l.a) > EPS;
}

// 直线与直线相交
bool line_intersection(const Line& l1, const Line& l2, Vector2& x)
{
    double det = l1.b.cross(l2.b); // 两个方向向量的外积
    // 平行或重叠返回false
    if (fabs(det) < EPS)
        return false;
    // 两条有向直线的交点
    Vector2 u = l1.a - l2.a;
    double t = l2.b.cross(u) / det;
    x = l1.a + l1.b * t;
    return true;
}

// 直线与直线相交
bool line_intersection(Vector2 a, Vector2 b, Vector2 c, Vector2 d, Vector2& x)
{
    // 平行或重叠返回 false
    // (b - a) 是 (a, b) 的方向向量
    // (d - c) 是 (c, d) 的方向向量
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPS)
        return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

// 两条直线平行时，判断两条线段是否属于同一直线且有重叠或相接于一点
bool parallelSegments(Vector2 a, Vector2 b, Vector2 c, Vector2 d, Vector2& x)
{
    // (a, b) , (c, d) 平行时，判断是否相接于一点
    if (b < a)
        std::swap(a, b);
    if (d < c)
        std::swap(c, d);
    // 两条线段不在同一条直线以及两条线段不重叠的情况
    if (ccw(a, b, c) != 0 || b < c || d < a)
        return false;
    if (a < c)
        x = c;
    else
        x = a;
    return true;
}

// 判断交点是否落在线段上
bool inBoundingRectangle(Vector2 x, Vector2 a, Vector2 b)
{
    // x, a, b 同线
    // 判断 x 是否在包含 (a, b) 且各边平行于 x 轴，y 轴的最小四边形内部。
    if (b < a)
        std::swap(a, b);
    return x == a || x == b || (a < x && x < b);
}

// 线段与线段相交
bool segmentIntersection(Vector2 a, Vector2 b, Vector2 c, Vector2 d, Vector2& x)
{
    // 将 (a, b) , (c, d) 的交点返回 x
    // 多个交点返回 x 最小的，x 相同的情况下返回 y 最小的
    // 不相交返回 false
    if (!line_intersection(a, b, c, d, x))
    {
        // 两条线段平行
        return parallelSegments(a, b, c, d, x);
    }
    // 两条直线有交点 x
    // 仅当两条线段都包含 x 时返回真
    return inBoundingRectangle(x, a, b) && inBoundingRectangle(x, c, d);
}

bool segmentIntersection(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);
    // 两条线段在同一直线上或者端点相互重叠
    if (abs(ab - 0) < EPS && abs(cd - 0) < EPS)
    {
        if (b < a)
            std::swap(a, b);
        if (d < c)
            std::swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

// 角平分线
Line get_pingfen(Vector2 a, Vector2 b, Vector2 c)
{
    auto get_duidian = [](Vector2 a, Vector2 b, Vector2 c)
    {
        Vector2 ea = a - b;
        Vector2 eb = c - b;
        auto dis1 = dis(c, b);
        auto dis2 = dis(a, b);
        Vector2 eaaa = ea * dis1;
        Vector2 ebbb = eb * dis2;
        Vector2 bb = eaaa + ebbb;
        return bb + b;
    };
    Vector2 bb = get_duidian(a, b, c);
    return Line(b, bb);
}
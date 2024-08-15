// 2024/08/13 15:01:48
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define double long double

// 二维向量
const double PI = 2.0 * acos(0.0);
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

double area(const vector<Vector2>& p)
{
    double ans = 0.0;
    int n = p.size();
    for (int i = 0; i < n; ++i)
        ans += p[i].cross(p[(i + 1) % n]);
    return fabs(ans) / 2.0;
}

double dis(const Vector2& a, const Vector2& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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

struct Line
{
    // line: a+pb, a 是点, b 是方向向量
    Vector2 m_a;
    Vector2 m_b;
    double deg; // 极角
    Line(Vector2 a, Vector2 b) :
        m_a(a), m_b(b)
    {
        deg = b.polar();
    }
    bool operator<(const Line& l) const
    {
        // 方向向量的极角序
        return deg < l.deg;
    }
};

// 直线与直线相交
bool line_intersection(const Line& l1, const Line& l2, Vector2& x)
{
    double det = l1.m_b.cross(l2.m_b); // 两个方向向量的外积
    // 平行或重叠返回false
    if (fabs(det) < EPS)
        return false;
    // 两条有向直线的交点
    Vector2 u = l1.m_a - l2.m_a;
    double t = l2.m_b.cross(u) / det;
    x = l1.m_a + l1.m_b * t;
    return true;
}

// 直线与直线相交
bool lineIntersection(Vector2 a, Vector2 b, Vector2 c, Vector2 d, Vector2& x)
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

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    cin >> tt;
    cout << setprecision(20) << fixed;
    while (tt--)
    {
        solve();
    }

    return 0;
}

Vector2 get_duidian(Vector2 a, Vector2 b, Vector2 c)
{
    Vector2 ea = a - b;
    Vector2 eb = c - b;
    auto dis1 = dis(c, b);
    auto dis2 = dis(a, b);
    Vector2 eaaa = ea * dis1;
    Vector2 ebbb = eb * dis2;
    Vector2 bb = eaaa + ebbb;
    return bb + b;
}

Vector2 get_pingfen(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
    Vector2 bb = get_duidian(a, b, c);
    Vector2 cc = get_duidian(b, c, d);
    Vector2 res;
    lineIntersection(b, bb, c, cc, res);
    return res;
}

const double pi = acosl(-1);
void solve()
{
    int n;
    cin >> n;
    vector<Vector2> arra, arrb;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arra.emplace_back(x, y);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        arrb.emplace_back(x, y);
    }

    auto get_zhijing = [](vector<Vector2> const& vec)
    {
        auto t = vec;
        vector<Vector2> ch = convex_hull(t);
        double D = polygan_diameter(ch);
        return D;
    };

    double CA1 = 0;
    for (int i = 0; i < n; i++)
    {
        CA1 += dis(arra[i], arra[(i + 1) % n]);
    }

    double DA = get_zhijing(arra);
    double DB = get_zhijing(arrb);
    double ans = 2 * pi * DB + CA1;

    if (DA > 2 * DB)
    {
        auto dis1 = dis(arra[0], arra[1]);
        auto dis2 = dis1 - 2 * DB;
        auto CA2 = CA1 * (dis2 / dis1);
        ans += CA2;
    }

    cout << ans << '\n';
}
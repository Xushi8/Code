#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    double x, y;
} p[510000], sta[510000];

int i, j, k, m, n, o, top;
double ans, jl, js;

double multi(node p1, node p2, node p0)
{
    double x1 = p1.x - p0.x;
    double y1 = p1.y - p0.y;

    double x2 = p2.x - p0.x;
    double y2 = p2.y - p0.y;

    return (x1 * y2 - x2 * y1);
} // 计算叉积

double dis(node p1, node p2)
{
    return (double((p1.x - p2.x) * (p1.x - p2.x)) + double((p1.y - p2.y) * (p1.y - p2.y)));
} // 计算任意两点间距离

bool cmp(node p1, node p2)
{
    double tt = multi(p1, p2, p[1]);
    if (tt < 0)
        return (0);
    if (tt == 0 && dis(p1, p[1]) > dis(p2, p[1]))
        return (0);
    return (1);
}

void graham()
{
    sort(p + 2, p + n + 1, cmp);
    for (int i = 1; i <= 2; i++)
        sta[i] = p[i];
    top = 2;
    n++;
    p[n] = p[1];

    for (int i = 3; i <= n; i++)
    {
        while (top > 1 && multi(sta[top], p[i], sta[top - 1]) <= 0)
            top--;
        top++;
        sta[top] = p[i];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x))
        {
            node t = p[1];
            p[1] = p[i];
            p[i] = t;
        } // 找最下方的点
    }

    top = 0; // 记录凸包上点的个数
    graham();
    top--; // sta中存储了top+1个点，第top+1个和第一个相同

    j = 2;
    ans = 0;
    for (int i = 1; i < top; i++)
    {
        while (fabs(multi(sta[i], sta[i + 1], sta[j])) < fabs(multi(sta[i], sta[i + 1], sta[j + 1])))
        {
            j++;
            if (j > top)
                j = 1;
        }
        js = max(dis(sta[i], sta[j]), dis(sta[i + 1], sta[j]));
        if (js > ans)
            ans = js;
    } // 旋转卡壳

    printf("%0.2lf", ans);
    return 0;
}
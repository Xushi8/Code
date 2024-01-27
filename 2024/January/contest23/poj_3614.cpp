#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2555;
class A
{
public:
    int l, r;
};

class B
{
public:
    int val, num;
};

bool operator<(A const& x, A const& y)
{
    if (x.r != y.r)
        return x.r < y.r;
    else
        return x.l < y.l;
}

bool operator<(B const& x, B const& y)
{
    return x.val < y.val;
}

A t1[N];
B t2[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        t1[i] = {a, b};
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        t2[i] = {a, b};
    }

    sort(t1, t1 + n);
    sort(t2, t2 + k);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (t2[j].num == 0)
                continue;
            if (t1[i].l <= t2[j].val && t2[j].val <= t1[i].r)
            {
                ans++;
                t2[j].num--;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
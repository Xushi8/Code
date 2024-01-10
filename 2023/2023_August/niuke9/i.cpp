#include<bits/stdc++.h>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
const int m = 1e9 + 7;
int sum[maxn << 2], ans[maxn << 2], tags[maxn << 2], taga[maxn << 2];
void build(int p, int l, int r) {
    if (l == r) {
        ans[p] = 0;
        sum[p] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
}
void pushup(int p) {
    if (sum[ls(p)] > sum[p]) {
        sum[p] = sum[ls(p)];
        ans[p] = ans[ls(p)];
    }
    else if (sum[rs(p)] > sum[p]) {
        sum[p] = sum[rs(p)];
        ans[p] = ans[rs(p)];
    }
    else {
        if (ans[ls(p)] > ans[p])ans[p] = ans[ls(p)];
        if (ans[rs(p)] > ans[p])ans[p] = ans[rs(p)];
    }
}
void pushdown(int p, int l, int r) {
    if (tags[p]) {
        tags[ls(p)] += tags[p];
        tags[rs(p)] += tags[p];
        sum[ls(p)] += tags[p];
        sum[rs(p)] += tags[p];
        tags[p] = 0;
    }
}
void pushdown1(int p, int l, int r) {
    if (taga[p]) {
        taga[ls(p)] += taga[p];
        taga[rs(p)] += taga[p];
        ans[ls(p)] += taga[p];
        ans[rs(p)] += taga[p];
        taga[p] = 0;
    }
}
void update(int p, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        sum[p]++;
        tags[p]++;
        return;
    }
    int mid = l + r >> 1;
    pushdown(p, l, r);
    if (ql <= mid)update(ls(p), l, mid, ql, qr);
    if (qr > mid)update(rs(p), mid + 1, r, ql, qr);
    pushup(p);
}
void update1(int p, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        ans[p]++;
        taga[p]++;
        return;
    }
    int mid = l + r >> 1;
    pushdown1(p, l, r);
    if (ql <= mid)update1(ls(p), l, mid, ql, qr);
    if (qr > mid)update1(rs(p), mid + 1, r, ql, qr);
    pushup(p);
}
signed main() {
    int n;
    scanf("%lld", &n);
    int l1, r1, l2, r2;
    build(1, 1, maxn - 3);
    for (int i = 1;i <= n;i++) {
        scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
        if (l1 > r2 || l2 > r1) {
            update(1, 1, maxn - 3, l1, r1);
            update(1, 1, maxn - 3, l2, r2);
        }
        else {
            int nl = min(l1, l2);
            int nr = max(r1, r2);
            update(1, 1, maxn - 3, nl, nr);
        }
        update1(1, 1, maxn - 3, l1, r1);
        update1(1, 1, maxn - 3, l2, r2);
    }
    int res = 1;
    if (sum[1] < n) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = sum[1];i < ans[1];i++) {
        res = res * 2 % m;
    }
    cout << res << endl;
    return 0;
}
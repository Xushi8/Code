#include <bits/stdc++.h>
using namespace std;
long long now, l, r, day, sub, add;
const int maxn = 1e6 + 5;
int vis[maxn];
bool check(long long now)
{
    if (now > r || now < l)
    {
        return false;
    }
    return true;
}
void solve1()
{
    if (now + add > r)
    {
        day--;
        now -= sub;
    }
    if (!check(now))
    {
        cout << "NO" << endl;
        return;
    }
    int gap = sub - add;
    if (gap == 0)
    {
        cout << "YES" << endl;
        return;
    }
    // cout<<k<<" "<<l<<" "<<gap<<" "<<t<<endl;
    if ((now - l) / gap >= day)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
void solve2()
{
    // step 0 k->l
    long long num1 = (now - l) / sub;
    if (num1 >= day)
    {
        cout << "YES" << endl;
        return;
    }
    now = now - num1 * sub;
    day -= num1;
    // step 1 无限循环的增加一次，减少无数次
    while ((!vis[now]) && day > 0)
    {
        // cout<<k<<" "<<t<<endl;
        vis[now] = 1;
        now = now + add;
        if (!check(now))
        {
            cout << "NO" << endl;
            return;
        }
        long long num2 = (now - l) / sub;
        day -= min(num2, day);
        now = now - num2 * sub;
        // cout<<"2:" << k<<" "<<t<<endl;
    }
    cout << "YES" << endl;
}
int main()
{
    cin >> now >> l >> r >> day >> sub >> add;
    now -= l;
    r -= l;
    l = 0;
    if (sub >= add)
    {
        solve1();
    }
    else
    {
        solve2();
    }
}

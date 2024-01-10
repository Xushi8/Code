// 2023/08/02 09:39:21
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;
int m, s;

void get_min()
{
    int i;
    // 第一个数的最小值
    for (i = 1; i <= 9; i++)
    {
        if ((m - 1) * 9 >= s - i)
            break;
    }

    int m_ = m;
    int s_ = s;
    int cnt = (s_ - i) / 9;
    int tmp = -1;
    if ((s_ - i) % 9 != 0)
    {
        tmp = (s_ - i) % 9;
    }

    if (tmp == -1)
        m_ -= 1 + cnt;
    else
        m_ -= 1 + cnt + 1;

    cout << i;
    while (m_--)
        cout << 0;
    if (tmp != -1)
        cout << tmp;

    while (cnt--)
        cout << 9;

}

void get_max()
{
    int m_ = m;
    int s_ = s;
    while (s_ - 9 >= 0)
    {
        s_ -= 9;
        cout << 9;
        m_--;
    }
    cout << s_;
    m_--;
    while (m_--)
        cout << 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> m >> s;
    // cout << m << ' ' << s << ' ';
    if (s == 0)
    {
        if (m != 1)
            cout << -1 << ' ' << -1 << '\n';
        else
            cout << 0 << ' ' << 0 << '\n';
    }
    else if (s == 1)
    {
        int m_ = m;
        cout << 1;
        m_--;
        while (m_--)
            cout << 0;
        cout << ' ';

        cout << 1;
        m_ = m;
        m_--;
        while (m_--)
            cout << 0;
        cout << '\n';
    }
    else if (s > 9 * m)
    {
        cout << -1 << ' ' << -1 << '\n';
    }
    else if (s == 9 * m)
    {
        int m_ = m;
        while (m_--)
            cout << 9;
        cout << ' ';
        m_ = m;
        while (m_--)
            cout << 9;
        cout << '\n';
    }
    else
    {
        get_min();
        cout << ' ';
        get_max();
        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
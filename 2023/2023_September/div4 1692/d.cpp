// 2023/09/17 12:10:14
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
#include <array>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int h, m, tim;
        char ch;
        cin >> h >> ch >> m >> tim;
        // cout << h << m << ch << tim;
        int th = h, tm = m;
        int ans = 0;
        set<pii> st;
        st.emplace(th, tm);

        string a, b, c;
        a += th % 10 + '0';
        if (th / 10 == 0)
        {
            a += '0';
        }
        else
        {
            a += th / 10 % 10 + '0';
        }
        swap(a.front(), a.back());


        b += tm % 10 + '0';
        if (tm / 10 == 0)
        {
            b += '0';
        }
        else
        {
            b += tm / 10 % 10 + '0';
        }
        swap(b.front(), b.back());


        c = a;
        swap(c.front(), c.back());

        ans += (c == b);
        tm += tim % 60;
        th += tim / 60 + tm / 60;
        th %= 24;
        tm %= 60;
        while (st.count(make_pair(th, tm)) == 0)
        {
            st.emplace(th, tm);
            a = th % 10 + '0';
            if (th / 10 == 0)
            {
                a += '0';
            }
            else
            {
                a += th / 10 % 10 + '0';
            }
            swap(a.front(), a.back());


            b = tm % 10 + '0';
            if (tm / 10 == 0)
            {
                b += '0';
            }
            else
            {
                b += tm / 10 % 10 + '0';
            }
            swap(b.front(), b.back());

            c = a;
            swap(c.front(), c.back());
            ans += (c == b);
            // cerr << c << ' ' << b << '\n';
            tm += tim % 60;
            th += tim / 60 + tm / 60;
            th %= 24;
            tm %= 60;
        }

        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
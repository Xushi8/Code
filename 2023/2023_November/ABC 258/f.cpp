// 2023/12/04 21:32:39
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
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void solve()
{
    ll b, k;
    ll bx, by, ex, ey;
    cin >> b >> k >> bx >> by >> ex >> ey;
    set<ll> st;
    st.emplace((abs(bx - ex) + abs(by - ey)) * k);
    for (int i = 0; i < 4; i++)
    {
        ll now = 0;
        ll nbx, nby;
        if (i == 0)
        {
            nbx = bx / b * b + b;
            nby = by;
        }
        else if (i == 1)
        {
            nbx = bx;
            nby = by / b * b;
        }
        else if (i == 2)
        {
            nbx = bx / b * b;
            nby = by;
        }
        else
        {
            nbx = bx;
            nby = by / b * b + b;
        }

        now += k * (abs(nbx - bx) + abs(nby - by));

        for (int j = 0; j < 4; j++)
        {
            ll nex, ney;
            if (j == 0)
            {
                nex = ex / b * b + b;
                ney = ey;
            }
            else if (j == 1)
            {
                nex = ex;
                ney = ey / b * b;
            }
            else if (j == 2)
            {
                nex = ex / b * b;
                ney = ey;
            }
            else
            {
                nex = ex;
                ney = ey / b * b + b;
            }

            ll tmp = now;
            tmp += k * (abs(nex - ex) + abs(ney - ey));
            if (nbx / b != nex / b && nby / b != ney / b)
            {
                st.emplace(tmp + abs(nbx - nex) + abs(nby - ney));
            }
            else
            {
                if (nbx / b == nex / b)
                {
                    st.emplace(tmp + min({abs(nby - ney) + nbx - nbx / b * b + (nex - nex / b * b), abs(nby - ney) + nbx / b * b + b - nbx + (nex / b * b + b - nex), abs(nby - ney) * k + abs(nbx - nex)}));
                }
                else
                {
                    st.emplace(tmp + min({abs(nbx - nex) + nby - nby / b * b + (ney - ney / b * b), abs(nbx - nex) + nby / b * b + b - nby + (ney / b * b + b - ney), abs(nbx - nex) * k + abs(nby - ney)}));
                }
            }
        }
    }

    cout << *st.begin() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
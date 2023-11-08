// 2023/11/08 13:12:42
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
constexpr int N = 105;

int chuang[N];

struct A
{
    int bg, len, ed;
};

bool operator<(A a, A b)
{
    return a.bg < b.bg;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<A> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        int h, m, s;
        char ch;
        int len;
        cin >> h >> ch >> m >> ch >> s >> len;
        len = min(len, 60);
        a[i] = {h * 3600 + m * 60 + s, len * 60, 0};
    }

    a[n] = {999999999, 0, 0};

    sort(a.begin(), a.end());

    int tot = 0;
    memset(chuang, -1, sizeof(chuang));
    double sum = 0.0;
    for (int now = 28800; a[tot].bg <= 61200; now++)
    {
        for (int i = 0; i < m; i++)
        {
            if (chuang[i] != -1)
            {
                int j = chuang[i];
                if (a[j].ed == now)
                {
                    chuang[i] = -1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (chuang[i] == -1)
            {
                if (a[tot].bg <= 61200 && a[tot].bg <= now)
                {
                    chuang[i] = tot++;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (chuang[i] != -1)
            {
                int j = chuang[i];
                if (a[j].ed == 0)
                {
                    sum += now - a[j].bg;
                    a[j].ed = now + a[j].len;
                }
            }
        }
    }

    cout << setprecision(1) << fixed;
    cout << sum / tot / 60;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
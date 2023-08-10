// 2023/08/10 08:52:28
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 13000000;

char s[N], s_new[2 * N];
int p[2 * N];

int init()
{
    int len = (int)strlen(s);
    int tot = 0;
    s_new[tot++] = '@';
    s_new[tot++] = '#';
    for (int i = 0; i < len; i++)
    {
        s_new[tot++] = s[i];
        s_new[tot++] = '#';
    }

    s_new[tot] = '\0';
    return tot;
}

void solve()
{
    int len = init();
    int ans = 1;
    int id;
    int maxn = 0;
    for (int i = 1; i <= len; i++)
    {
        if (i < maxn)
        {
            p[i] = min(p[2 * id - i], maxn - i);
        }
        else
        {
            p[i] = 1;
        }

        while (s_new[i - p[i]] == s_new[i + p[i]])
            p[i]++;

        if (maxn < i + p[i])
        {
            maxn = i + p[i];
            id = i;
        }

        ans = max(ans, p[i] - 1);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin >> s)
    {
        solve();
    }

    cout << flush;
    return 0;
}
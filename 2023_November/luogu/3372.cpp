// 2023/11/04 14:45:29
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

ll arr[N], bel[N], st[N], ed[N], sz[N];
ll sum[N], mark[N];
int n, m;

void init()
{
    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        st[i] = n / sq * (i - 1) + 1;
        ed[i] = n / sq * i;
    }
    ed[sq] = n;

    for (int i = 1; i <= sq; i++)
    {
        for (int j = st[i]; j <= ed[i]; j++)
        {
            bel[j] = i;
        }
    }

    for (int i = 1; i <= sq; i++)
    {
        sz[i] = ed[i] - st[i] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    init();

    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        for (int j = st[i]; j <= ed[i]; j++)
        {
            sum[i] += arr[j];
        }
    }

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            if (bel[x] == bel[y])
            {
                for (int i = x; i <= y; i++)
                {
                    arr[i] += k;
                    sum[bel[x]] += k;
                }
            }
            else
            {
                for (int i = x; i <= ed[bel[x]]; i++)
                {
                    arr[i] += k;
                    sum[bel[x]] += k;
                }
                for (int i = st[bel[y]]; i <= y; i++)
                {
                    arr[i] += k;
                    sum[bel[y]] += k;
                }

                for (int i = bel[x] + 1; i < bel[y]; i++)
                {
                    mark[i] += k;
                }
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            ll ans = 0;
            if (bel[x] == bel[y])
            {
                for (int i = x; i <= y; i++)
                {
                    ans += arr[i] + mark[bel[x]];
                }
            }
            else
            {
                for (int i = x; i <= ed[bel[x]]; i++)
                {
                    ans += arr[i] + mark[bel[x]];
                }
                for (int i = st[bel[y]]; i <= y; i++)
                {
                    ans += arr[i] + mark[bel[y]];
                }

                for (int i = bel[x] + 1; i < bel[y]; i++)
                {
                    ans += sum[i] + sz[i] * mark[i];
                }
            }

            cout << ans << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
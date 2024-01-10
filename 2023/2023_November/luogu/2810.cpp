// 2023/11/04 15:08:40
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
#include <bitset>
#include <fstream>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

ll arr[N], bel[N], st[N], ed[N], sz[N], mark[N];
vector<int> sorted[N];

void init(int n)
{
    int sq = sqrt(n) + 2; // 加2 ！！！！！
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

void update(int x)
{
    for (int i = st[x]; i <= ed[x]; i++)
    {
        sorted[x][i - st[x]] = arr[i];
    }
    sort(sorted[x].begin(), sorted[x].end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init(n);
    int sq = sqrt(n) + 2;
    for (int i = 1; i <= sq; i++)
    {
        for (int j = st[i]; j <= ed[i]; j++)
        {
            sorted[i].push_back(arr[j]);
        }
        sort(sorted[i].begin(), sorted[i].end());
    }

    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'M')
        {
            int l, r, adds;
            cin >> l >> r >> adds;
            if (bel[l] == bel[r])
            {
                for (int i = l; i <= r; i++)
                {
                    arr[i] += adds;
                }
                update(bel[l]);
            }
            else
            {
                for (int i = l; i <= ed[bel[l]]; i++)
                {
                    arr[i] += adds;
                }
                for (int i = st[bel[r]]; i <= r; i++)
                {
                    arr[i] += adds;
                }
                update(bel[l]);
                update(bel[r]);

                for (int i = bel[l] + 1; i < bel[r]; i++)
                {
                    mark[i] += adds;
                }
            }
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            int ans = 0;
            if (bel[l] == bel[r])
            {
                for (int i = l; i <= r; i++)
                {
                    if (arr[i] + mark[bel[l]] >= k)
                    {
                        ans++;
                    }
                }
            }
            else
            {
                for (int i = l; i <= ed[bel[l]]; i++)
                {
                    if (arr[i] + mark[bel[l]] >= k)
                    {
                        ans++;
                    }
                }
                for (int i = st[bel[r]]; i <= r; i++)
                {
                    if (arr[i] + mark[bel[l]] >= k)
                    {
                        ans++;
                    }
                }

                for (int i = bel[l] + 1; i < bel[r]; i++)
                {
                    ans += sorted[i].end() - lower_bound(sorted[i].begin(), sorted[i].end(), k - mark[i]);
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
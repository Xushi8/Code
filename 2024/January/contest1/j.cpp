// 2024/01/12 13:15:44
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
    int n, k;
    ll attack;
    cin >> n >> attack >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n;)
    {
        int need_max = 0;
        bool update = 0;
        ll tmp_attack = 0;
        for (int j = i + 1; j - i <= k; j++)
        {
            if (j > n)
            {
                break;
            }
            if (attack >= a[j] && attack + a[j] >= need_max)
            {
                update = 1;
                attack += tmp_attack + a[j];
                i = j;
                break;
            }
            tmp_attack += a[j];
            need_max = max(a[j], need_max - a[j]);
        }

        if (!update)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
    return 0;
}
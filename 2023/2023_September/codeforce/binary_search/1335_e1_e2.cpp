// 2023/10/11 22:36:48
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

constexpr int MAX_SIZE = 200;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> index[MAX_SIZE + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        index[arr[i]].push_back(i + 1);
    }

    int ans = 0;
    for (int i = 1; i <= MAX_SIZE; i++)
    {
        ans = max(ans, int(index[i].size()));
    }

    for (int i = 1; i <= MAX_SIZE; i++)
    {
        for (int j = 1; j <= index[i].size() / 2; j++)
        {
            int l = index[i][j - 1] + 1;
            int r = index[i][index[i].size() - j] - 1;
            for (int k = 1; k <= MAX_SIZE; k++)
            {
                if (k == i)
                    continue;
                int adds = upper_bound(index[k].begin(), index[k].end(), r) - lower_bound(index[k].begin(), index[k].end(), l);
                ans = max(ans, j * 2 + adds);
            }
        }
    }

    cout << ans << '\n';
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
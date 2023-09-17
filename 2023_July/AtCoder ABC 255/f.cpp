// 2023/09/15 17:56:57
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

pii ans[N];

// int dfs(vector<int>&& pre_order, vector<int>&& in_order)
// {
//     size_t len = pre_order.size();
//     if (len == 0)
//         return 0;
//     else if (len == 1)
//         return pre_order[0];

//     size_t pos = find(in_order.begin(), in_order.end(), pre_order.front()) - in_order.begin();

//     if (pos == len)
//     {
//         cout << -1 << endl;
//         exit(0);
//     }

//     ans[pre_order[0]].first =
//         dfs(vector<int>(pre_order.begin() + 1, pre_order.begin() + pos + 1), vector<int>(in_order.begin(), in_order.begin() + pos));
//     ans[pre_order[0]].second =
//         dfs(vector<int>(pre_order.begin() + pos + 1, pre_order.end()), vector<int>(in_order.begin() + pos + 1, in_order.end()));

//     return pre_order[0];
// }

int pre_order[N], in_order[N], all_pos[N];

// int dfs(int* pre_order, int* in_order, int len)
// {
//     if (len == 0)
//         return 0;
//     if (len == 1)
//         return pre_order[0];

//     int pos = find(in_order, in_order + len, pre_order[0]) - in_order;
//     if (pos == len)
//     {
//         cout << -1 << endl;
//         exit(0);
//     }

//     ans[pre_order[0]].first = dfs(pre_order + 1, in_order, pos);
//     ans[pre_order[0]].second = dfs(pre_order + pos + 1, in_order + pos + 1, len - pos - 1);
//     return pre_order[0];
// }

int dfs(int x1, int y1, int x2, int y2)
{
    int len = y1 - x1;
    if (len == 0)
        return 0;
    if (len == 1)
        return pre_order[x1];

    int pos = all_pos[pre_order[x1]];
    if (pos < x2 || pos >= y2)
    {
        cout << -1 << endl;
        exit(0);
    }

    int l_size = pos - x2;

    ans[pre_order[x1]].first = dfs(x1 + 1, x1 + 1 + l_size, x2, x2 + l_size);
    ans[pre_order[x1]].second = dfs(x1 + l_size + 1, y1, x2 + l_size + 1, y2);
    return pre_order[x1];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    // vector<int> pre_order(n), in_order(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre_order[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in_order[i];
    }

    for (int i = 0; i < n; i++)
    {
        all_pos[in_order[i]] = i;
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cerr << all_pos[i] << '\n';
    // }

    if (pre_order[0] != 1)
    {
        cout << -1 << endl;
        return 0;
    }

    dfs(0, n, 0, n);

    // dfs(move(pre_order), move(in_order));

    // dfs(pre_order + 0, pre_order + n, in_order + 0, in_order + n);

    // dfs(pre_order, in_order, n);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
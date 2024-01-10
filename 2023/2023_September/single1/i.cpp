// 2023/09/30 16:56:23
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;


void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        vis2[arr[i]]++;
    }
    int cnt1 = 0, cnt2 = 0;
    while (vis2[cnt2 + 1] == 1)
        cnt2++;

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        vis1[arr[i]]++;
        vis2[arr[i]]--;
        if (vis1[arr[i]] == 2 && cnt1 >= arr[i])
            cnt1 = arr[i] - 1;
        if (vis2[arr[i]] == 0 && cnt2 >= arr[i])
            cnt2 = arr[i] - 1;
        while (vis1[cnt1 + 1] == 1)
            cnt1++;
        while (vis2[cnt2 + 1] == 1)
            cnt2++;
        if (cnt1 == i && cnt2 == n - i)
        {
            ans.emplace_back(cnt1);
        }
    }

    cout << ans.size() << '\n';
    if (ans.size() > 0)
    {
        for (int x : ans)
        {
            cout << x << ' ' << n - x << '\n';
        }
    }
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
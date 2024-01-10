// 2023/09/30 14:35:11
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool hask = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k)
            arr[i] = 0;
        else if (arr[i] == k)
            arr[i] = 1, hask = 1;
        else
            arr[i] = 2;
    }
    if (!hask)
    {
        cout << "no\n";
        return;
    }

    if (n == 1)
    {
        cout << "yes\n";
        return;
    }

    if (n == 2)
    {
        int tmp = arr[0] + arr[1];
        if (tmp > 1)
            cout << "yes\n";
        else
            cout << "no\n";
        return;
    }

    // [1, n - 2]
    for (int i = 1; i < n - 1; i++)
    {
        int l = i - 1;
        int mid = i;
        int r = i + 1;
        int tmp = (arr[l] == 0) + (arr[mid] == 0) + (arr[r] == 0);
        if (tmp <= 1)
        {
            cout << "yes\n";
            return;
        }
    }

    cout << "no\n";
    return;
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
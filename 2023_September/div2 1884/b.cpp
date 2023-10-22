// 2023/10/22 15:21:23
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
#define int long long
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    if (cnt == 0)
    {
        while (n--)
        {
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }

    vector<int> arr;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            arr.push_back(n - i - 1);
        }
    }

    int dec = 1;
    for (size_t i = 1; i < arr.size(); i++)
    {
        arr[i] += arr[i - 1];
        arr[i] -= dec;
        dec++;
    }

    cnt = n - arr.size();
    for (int i = 0; i < cnt; i++)
    {
        arr.push_back(-1);
    }

    for (int x : arr)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main()
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
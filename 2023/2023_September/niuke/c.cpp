// 2023/10/27 10:29:59
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
int minn = -1, maxx = -1;
int n;

void check(int x, vector<int>& arr)
{
    int cnt = 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (abs(arr[i] - arr[i + 1]) <= 2)
        {
            cnt++;
        }
        else
            break;
    }
    for (int i = x + 1; i < n; i++)
    {
        if (abs(arr[i] - arr[i - 1]) <= 2)
        {
            cnt++;
        }
        else
            break;
    }

    if (minn == -1)
    {
        minn = maxx = cnt;
    }
    else
    {
        minn = min(minn, cnt);
        maxx = max(maxx, cnt);
    }
}

void solve()
{
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    minn = -1, maxx = -1;
    for (int i = 0; i < n; i++)
    {
        check(i, arr);
    }

    cout << minn << ' ' << maxx << '\n';
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
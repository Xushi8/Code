// 2024/01/12 15:06:44
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

int f(int x)
{
    int res = 0;
    while (x > 0)
    {
        x /= 10;
        res++;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.emplace(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.emplace(x);
    }

    int ans = 0;
    while (!a.empty())
    {
        if (a.top() == b.top())
        {
            a.pop();
            b.pop();
            continue;
        }

        ans++;
        if (a.top() > b.top())
        {
            int x = a.top();
            a.pop();
            a.emplace(f(x));
        }
        else
        {
            int x = b.top();
            b.pop();
            b.emplace(f(x));
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
    return 0;
}
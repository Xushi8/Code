// 2023/09/05 19:14:07
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

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    ll sum = 0;
    for (ll i = 0, tmp; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
    }
    
    if (((sum + x) & 1) == (y & 1))
        cout << "Alice\n";
    else
        cout << "Bob\n";
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
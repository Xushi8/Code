// 2023/08/03 14:25:03
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

class A
{
public:
    int l, r;
};

bool operator < (const A& a, const A& b)
{
    if (a.r != b.r)
        return a.r < b.r;
    else
        return a.l < b.l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<A> arr(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i].l >> arr[i].r;
    }

    sort(arr.begin() + 1, arr.end());
    vector<ll> ans(n + 1);
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] * arr[i - 1].r * arr[i].l / arr[i].r;
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
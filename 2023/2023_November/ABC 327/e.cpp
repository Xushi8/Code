// 2023/11/04 20:36:01
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

struct A
{
    int val, index;
};

bool cmp1(A a, A b)
{
    if (a.val != b.val)
        return a.val > b.val;
    else
        return a.index > b.index;
}

bool cmp2(A a, A b)
{
    return a.index > b.index;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<A> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }
    sort(arr.begin(), arr.end(), cmp1);

    double ans = -1e18;
    vector<A> tmp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            tmp[j] = arr[j];
        }
        sort(tmp.begin(), tmp.begin() + i + 1, cmp2);
        double now = -1200. / sqrt(i + 1);
        double zi = 0, mu = 0;
        double a = 1.0;
        for (int j = 0; j <= i; j++)
        {
            zi += a * tmp[j].val;
            mu += a;
            a *= 0.9;
        }
        double aaaaa = zi / mu;
        now += aaaaa;
        ans = max(ans, now);
    }

    cout << setprecision(15) << fixed << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
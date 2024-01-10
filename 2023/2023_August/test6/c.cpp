// 2023/08/03 15:13:03
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
const int N = 100005;

class A
{
public:
    int s, h, this_ans; // 字串的s, h, 与该字串自己的答案
    A()
        :s(0), h(0), this_ans(0)
    {}
};

bool cmp(const A& a, const A& b)
{
    return 1LL * a.s * b.h > 1LL * b.s * a.h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    vector<A> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int sum = 0; // 记录h的后缀和
        for (int j = (int)s.size() - 1; j >= 0; j--)
        {
            if (s[j] == 'h')
                sum++;
            else
                arr[i].this_ans += sum;
        }

        arr[i].h = sum;
        arr[i].s = (int)(s.size()) - sum;
    }

    sort(arr.begin(), arr.end(), cmp);

    ull ans = 0;
    ull sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        A a = arr[i];
        ans += a.this_ans + a.s * sum;
        sum += a.h;
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
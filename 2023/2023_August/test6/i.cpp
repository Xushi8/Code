// 2023/08/04 10:40:59
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
const int N = 1000005;

struct A
{
    int a, b;
};

int n;
ll bit[N];

void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}

ll sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += bit[i];
        i -= i & -i;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<A> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].a;
        add(i, arr[i].a);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].b;
    }

    priority_queue<pii> que;
    for (int i = 1; i <= n; i++)
    {
        ll now_sum = sum(i);
        if (now_sum >= arr[i].b)
        {
            add(i, -arr[i].b);
            que.emplace(arr[i].b, i);
        }
        else
        {
            if (!que.empty() && que.top().first > arr[i].b)
            {
                auto [b, index] = que.top(); que.pop();
                add(index, b);
                add(i, -arr[i].b);
                que.emplace(arr[i].b, i);
            }
        }
    }

    cout << que.size() << '\n';
    vector<int> tmp;
    while (!que.empty())
    {
        tmp.emplace_back(que.top().second);
        que.pop();
    }

    sort(tmp.begin(), tmp.end());
    for (int p : tmp)
    {
        cout << p << ' ';
    }
    cout << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
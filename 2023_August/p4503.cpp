// 2023/08/04 12:00:51
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
    int end, time;
};

bool cmp(const A& a, const A& b)
{
    if (a.end != b.end)
        return a.end < b.end;
    else
        return a.time < b.time;
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
        cin >> arr[i].time >> arr[i].end;
    }

    sort(arr.begin(), arr.end(), cmp);
    priority_queue<int> que;
    ll now = 0;
    for (int i = 0; i < n; i++)
    {
        if (now + arr[i].time <= arr[i].end)
        {
            now += arr[i].time;
            que.emplace(arr[i].time);
        }
        else
        {
            if (que.top() > arr[i].time)
            {
                now -= que.top(); que.pop();
                now += arr[i].time;
                que.emplace(arr[i].time);
            }
        }
    }

    cout << que.size() << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
    }
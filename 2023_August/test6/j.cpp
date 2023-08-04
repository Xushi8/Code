// 2023/08/04 14:32:09
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
    int k, l;
};

struct B
{
    friend bool operator > (const B& a, const B& b)
    {
        return a.add > b.add;
    }

    B(int a, int b)
    {
        index = a;
        add = b;
    }

    int index, add;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<A> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].k >> arr[i].l;
    }

    priority_queue<B, vector<B>, greater<B>> que;
    for (int i = 0; i < n; i++)
    {
        int add = min(arr[i].k * 2, arr[i].l) - min(arr[i].k, arr[i].l);
        if (que.size() < m)
            que.emplace(i, add);
        else
        {
            if (!que.empty() && add > que.top().add)
            {
                que.pop();
                que.emplace(i, add);
            }
        }
    }

    vector<int> tmp;
    while (!que.empty())
    {
        tmp.emplace_back(que.top().index);
        que.pop();
    }

    sort(tmp.begin(), tmp.end());
    int tot = 0;

    for (int i = 0; i < n; i++)
    {
        if (tot != (int)tmp.size())
        {
            if (i == tmp[tot])
            {
                arr[i].k *= 2;
                tot++;
            }
        }
        else
        {
            break;
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(arr[i].k, arr[i].l);
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2024/01/12 13:33:30
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

void solve()
{
    int index, n;
    cin >> index >> n;
    vector<int> a(n);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, less<>> great_que;
    priority_queue<int, vector<int>, greater<>> less_que;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (great_que.empty() || x <= great_que.top())
        {
            great_que.emplace(x);
        }
        else
        {
            less_que.emplace(x);
        }

        while (great_que.size() < less_que.size())
        {
            great_que.emplace(less_que.top());
            less_que.pop();
        }
        while (great_que.size() >= less_que.size() + 2)
        {
            less_que.emplace(great_que.top());
            great_que.pop();
        }

        if (great_que.size() == less_que.size() + 1)
        {
            ans.emplace_back(great_que.top());
        }
    }

    cout << index << ' ' << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); i += 10)
    {
        for (size_t j = i; j - i < 10 && j < ans.size(); j++)
        {
            cout << ans[j] << ' ';
        }
        cout << '\n';
    }
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
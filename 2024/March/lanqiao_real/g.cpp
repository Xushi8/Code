#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    vector<int> ans(n, -1);
    map<int, deque<int>, greater<int>> maxx;
    for (int i = 0; i < k; i++) {
        maxx[a[i]].emplace_back(i);
    }

    ans[0] = maxx.begin()->first;
    k -= 1 + maxx.begin()->second.front();
    maxx.begin()->second.pop_front();
    if (maxx.begin()->second.empty()) {
        maxx.erase(maxx.begin());
    }

    for (int i = k; i < n; i++) {
        
    }

    return 0;
}
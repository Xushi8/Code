#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int h, m, s;
        char ch;
        cin >> h >> ch >> m >> ch >> s;
        int tl = h * 3600 + m * 60 + s;
        cin >> h >> ch >> m >> ch >> s;
        int tr = h * 3600 + m * 60 + s;
        a[i] = {tl, tr};
    }

    // sort(a.begin(), a.end(), [](pii const& lhs, pii const& rhs) {
    //     if(lhs.second != rhs.second) {
    //         return lhs.second < rhs.second;
    //     } else  {
    //         return lhs.first > rhs.first;
    //     }
    // });

    sort(a.begin(), a.end());

    priority_queue<int, vector<int>, greater<>> que;
    que.emplace(0);
    size_t ans = 1;

    for(auto [l, r] : a) {
        ans = max(ans, que.size());
        int lst = que.top();
        que.pop();
        if(l > lst) {
            que.emplace(r);
        } else {
            que.emplace(r);
            que.emplace(lst);
        }
    }
    ans = max(ans, que.size());

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
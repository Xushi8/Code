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
    ll n, S;
    cin >> n >> S;
    priority_queue<pii, vector<pii>, greater<pii>> que; // 第一个存 次数, 次数小的先出
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        int val, cnt;
        cin >> val >> cnt;
        que.emplace(cnt, val);
        sum += val;
    }

    ll ans = 0;
    ll cnt = 0;
    while (!que.empty()) {
        if (S <= sum) {
            ans += S;
        }
        else {
            ans += sum;
        }
        cnt++;
        while (!que.empty() && que.top().first <= cnt) {
            sum -= que.top().second;
            que.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
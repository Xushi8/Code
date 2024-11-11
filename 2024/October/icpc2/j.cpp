#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<array<i64, 3>> a(n);
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        i64 x, y, z;
        cin >> x >> y >> z;
        sum += x;
        a[i] = {x, y, z};
    }

    sort(a.begin(), a.end(), [](array<i64, 3> const& lhs, array<i64, 3> const& rhs) {
        auto [wi, vi, ci] = lhs;
        auto [wj, vj, cj] = rhs;
        return ci * wj > cj * wi;
    });

    i64 ans = 0;
    for(auto [w, v, c] : a) {
        sum -= w;
        ans += v - sum * c;
        // cerr << ans << ' ' << w << ' ' << v << ' ' << c << '\n';
    }

    cout << ans << '\n';
    return 0;
}
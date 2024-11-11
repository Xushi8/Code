#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cout << a[(n + 1) / 2 - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}
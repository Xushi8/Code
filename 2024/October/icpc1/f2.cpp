#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> L(n), R(n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.top()] <= a[i])
            stk.pop();
        L[i] = stk.empty() ? -1 : stk.top();
        stk.emplace(i);
    }
    stack<int>().swap(stk);
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[stk.top()] <= a[i])
            stk.pop();
        R[i] = stk.empty() ? n : stk.top();
        stk.emplace(i);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int cntl = 0;
        int cntr = 0;
        int t = i;
        while (L[t] != -1) {
            t = L[t];
            cntl++;
        }
        t = i;
        while (R[t] != n) {
            t = R[t];
            cntr++;
        }
        ans += max(cntl, cntr);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
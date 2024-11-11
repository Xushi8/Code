#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
int n;

// void dfs(int l, int r, vector<int> const& a, i64& ans) {
//     if (r - l <= 1) {
//         return;
//     }
//     int maxx = *max_element(a.begin() + l, a.begin() + r);
//     int index1 = find(a.begin() + l, a.begin() + r, maxx) - a.begin();
//     int index2;
//     for (index2 = index1 + 1; index2 < r; index2++) {
//         if (a[index2] != maxx)
//             break;
//     }
//     index2--;
//     // [index1, index2] == maxx
//     ans += (index1 - l) + (r - index2 - 1);
//     dfs(l, index1, a, ans);
//     dfs(index2 + 1, r, a, ans);
// }

void dfs(int l, int r, vector<int> const& a, i64& ans) {
    if (r - l <= 1) {
        return;
    }

    int maxx = *max_element(a.begin() + l, a.begin() + r);
    vector<pii> qujian;
    for (int i = l; i < r; i++) {
        if (a[i] == maxx) {
            int j;
            for (j = i + 1; j < r; j++) {
                if (a[j] != maxx) {
                    break;
                }
            }
            j--;
            qujian.emplace_back(i, j);
            i = j + 1;
        }
    }

    int now = l;
    for (auto [x, y] : qujian) {
        dfs(now, x, a, ans);
        ans += x - now;
        now = y + 1;
    }
    dfs(now, r, a, ans);
    ans += r - now;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++) {
        cin >> a[i];
    }

    i64 ans = 0;

    dfs(0, n, a, ans);

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
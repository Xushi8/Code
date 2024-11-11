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
    map<int, set<pii>> qujian;
    for (int i = 0; i < n; ) {
        int j;
        for (j = i + 1; j < n; j++) {
            if (a[i] != a[j])
                break;
        }
        qujian[a[i]].emplace(i, j - 1);
        i = j;
    }

    if (qujian.size() == 1) {
        cout << 0 << '\n';
        return;
    }

    auto erase_l = [&](int l, int r) {
        int nex = a[l - 1];
        a[l] = a[r] = nex;
        auto& st = qujian[nex];
        auto it = st.lower_bound(pii{ l, 0 });
        it--;
        int new_l = it->first;
        st.erase(it);
        st.emplace(new_l, r);
        };

    auto erase_r = [&](int l, int r) {
        int nex = a[r + 1];
        a[l] = a[r] = nex;
        auto& st = qujian[nex];
        auto it = st.lower_bound(pii{ l, 0 });
        int new_r = it->second;
        st.erase(it);
        st.emplace(l, new_r);
        };

    int maxx;
    {
        auto it = qujian.end();
        it--;
        maxx = it->first;
    }

    i64 ans = 0;
    for (auto [id, st] : qujian) {
        if (id == maxx)
            break;
        for (auto [l, r] : st) {
            ans += r - l + 1;
            if (l == 0) {
                erase_r(l, r);
            }
            else if (r == n - 1) {
                erase_l(l, r);
            }
            else {
                if (a[l - 1] < a[r + 1])
                    erase_r(l, r);
                else
                    erase_l(l, r);
            }
        }
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
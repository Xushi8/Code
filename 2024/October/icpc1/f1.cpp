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
            if (a[j] != a[i])
                break;
        }
        qujian[a[i]].emplace(i, j - 1);
        i = j;
    }

    if (qujian.size() == 1) {
        cout << 0 << '\n';
        return;
    }
    i64 ans = 0;

    auto erase_l = [&](int l, int r) {
        int nex = a[l - 1];
        auto& st = qujian[nex];
        a[l] = a[r] = nex;
        auto it = st.lower_bound(pii{ l, 0 });
        it--;
        int to_l = it->first;
        st.erase(it);
        auto [it1, ok] = st.emplace(to_l, r);
        auto it2 = it1;
        it2++;
        if (it2 != st.end()) {
            if (it1->second + 1 == it2->first) {
                int nl = it1->first;
                int nr = it2->second;
                st.erase(it1);
                st.erase(it2);
                st.emplace(nl, nr);
            }
        }
        if (it1 != st.begin()) {
            it2 = it1;
            it2--;
            if (it2->second + 1 == it1->first) {
                int nl = it2->first;
                int nr = it1->second;
                st.erase(it1);
                st.erase(it2);
                st.emplace(nl, nr);
            }
        }
        };

    auto erase_r = [&](int l, int r) {
        int nex = a[r + 1];
        auto& st = qujian[nex];
        a[l] = a[r] = nex;
        auto it = st.lower_bound(pii{ r, 0 });
        int to_r = it->second;
        st.erase(it);
        auto [it1, ok] =  st.emplace(l, to_r);
        auto it2 = it1;
        it2++;
        if(it2 != st.end()) {
            if(it1->second + 1 == it2->first) {
                int nl = it1->first;
                int nr = it2->second;
                st.erase(it1);
                st.erase(it2);
                st.emplace(nl, nr);
            }
        }
        if (it1 != st.begin()) {
            it2 = it1;
            it2--;
            if (it2->second + 1 == it1->first) {
                int nl = it2->first;
                int nr = it1->second;
                st.erase(it1);
                st.erase(it2);
                st.emplace(nl, nr);
            }
        }
        };

    int maxx;
    {
        auto it = qujian.end();
        it--;
        maxx = it->first;
    }
    for (auto const& [id, st] : qujian) {
        if (id == maxx)
            break;
        for (auto [l, r] : st) {
            ans += (r - l + 1);
            if (l == 0) {
                erase_r(l, r);
            }
            else if (r == n - 1) {
                erase_l(l, r);
            }
            else {
                if (a[l - 1] < a[r + 1])
                    erase_l(l, r);
                else
                    erase_r(l, r);
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
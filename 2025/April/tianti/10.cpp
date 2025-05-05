#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> a(3);
    int n;
    cin >> n;
    for (int i = 0; i < n;i ++){
        int x, y;
        cin >> x >> y;
        a[y].emplace_back(x);
    }

    for (int i = 0; i < 3; i++) {
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
    }

    vector<array<int, 3>> ans;

    for (int i = 0; i < a[0].size(); i++) {
        int x1 = a[0][i];
        for (int j = 0; j < a[1].size(); j++) {
            if(i % 100 == 0) {
                cout << i << ' ' << j << '\n';
            }
            int x2 = a[1][j];
            int sub = x2 - x1;
            auto it = lower_bound(a[2].begin(), a[2].end(), sub + x2);
            if(it != a[2].end() && *it == sub + x2) {
                ans.push_back({x1, x2, *it});
            }
        }
    }


    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    sort(ans.begin(), ans.end(), [](array<int, 3> const &lhs, array<int, 3> const &rhs) {
        if(lhs[1] != rhs[1]) {
            return lhs[1] < rhs[1];
        } else {
            return lhs[0] < rhs[0];
        }
    });

    if(ans.empty()) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < ans.size(); i++) {
            auto [x, y, z] = ans[i];
            cout << '[' << x << ", 0] [" << y << ", 1] [" << z << ", 2]\n";
        }
    }

    cerr << ans.size() << '\n';
}
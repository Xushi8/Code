#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cin >> a[i][j];
    //     }
    // }

    vector<vector<int>> dis(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) {
                    if(i == ii && j == jj) {
                        continue;
                    }

                    dis[i][j] += max(abs(ii - i), abs(jj - j));
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(j != 0) {
                cout << ' ';
            }
            cout << dis[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
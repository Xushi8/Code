#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    deque<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    auto print = [&]
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (i != 0)
            {
                cout << ' ';
            }
            cout << a[i];
        }
        cout << '\n';
    };

    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int k1, k2;
            cin >> k1;
            vector<int> ta(k1);
            for (int j = 0; j < k1; j++) {
                cin >> ta[j];
            }
            cin >> k2;
            vector<int> tb(k2);
            for (int j = 0; j < k2; j++){
                cin >> tb[j];
            }

            int to_erase = -1;
            for (int i = 0; i < a.size(); i++) {
                if(i + k1 > a.size()) {
                    break;
                }
                bool ok = true;
                for (int j = 0; j < k1; j++) {
                    if(ta[j] != a[i + j]) {
                        ok = false;
                    }
                }

                if(ok) {
                    to_erase = i;
                    break;
                }
            }

            if(to_erase == -1) {
                continue;
            }

            auto it = a.erase(a.begin() + to_erase, a.begin() + to_erase + k1);
            a.insert(it, tb.begin(), tb.end());
        } else if(op == 2) {
            deque<int> b;
            b.emplace_back(a.front());
            for (int i = 1; i < a.size(); i++) {
                if((a[i - 1] + a[i]) % 2 == 0) {
                    b.emplace_back((a[i - 1] + a[i]) / 2);
                }
                b.emplace_back(a[i]);
            }

            a = std::move(b);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            reverse(a.begin() + l, a.begin() + r);
        }

        // print();
    }

    print();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
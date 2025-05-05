#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve()
{
    int n;
    i64 l, r;
    cin >> n >> l >> r;
    vector<string> ans;

    string sl = to_string(l);
    string sr = to_string(r);

    auto dfs = [&](auto &&self, string s)
    {
        int deep = s.size();
        if(deep == n) {
            i64 val = stoll(s);
            if(l <= val && val <= r) {
                ans.emplace_back(s);
            }
            return;
        }

        int be;
        if(deep == 0) {
            be = 1;
        } else {
            be = 0;
        }

        for (int i = be; i < 10; i++) {
            s += i + '0';
            i64 val = stoll(s);
            if(val % (deep + 1) == 0) {
                self(self, s);
            }
            s.pop_back();
        }
    };

    dfs(dfs, "");

    sort(ans.begin(), ans.end());
    if (ans.empty())
    {
        cout << "No Solution\n";
    }
    else
    {
        for (auto x : ans)
        {
            cout << x << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
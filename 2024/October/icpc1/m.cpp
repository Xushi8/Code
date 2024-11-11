#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, set<char>> mp;
    array<int, 26> cnt;
    cnt.fill(0);
    for(int i = 0; i < n; i++) {
        string name;
        char id;
        string ans;
        cin >> name >> id >> ans;
        if (ans == "accepted") {
            auto [it, ok] = mp[name].emplace(id);
            if(ok) {
                cnt[id - 'A']++;
            }
        }
    }

    int maxx = *max_element(cnt.begin(), cnt.end());
    for(int i = 0; i < 26; i++) {
        if(maxx == cnt[i]) {
            cout << (char)(i + 'A') << '\n';
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }

    return 0;
}
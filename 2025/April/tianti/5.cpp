#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    array<int, 26> val;
    for (int i = 0; i < 26; i++) {
        cin >> val[i];
    }

    array<int, 26> cnt{};
    int ans = 0;
    for(auto ch : s) {
        cnt[ch - 'a']++;
        ans += val[ch - 'a'];
    }

    for (int i = 0; i < 26; i++){
        if(i != 0) {
            cout << ' ';
        }
        cout << cnt[i];
    }
    cout << '\n'
         << ans << '\n';
}
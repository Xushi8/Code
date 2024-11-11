#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(32);
    for (int i = 0; i < 32; i++) {
        cin >> a[i];
    }

    int tar = a[0];
    sort(a.begin(), a.end());
    int index = find(a.begin(), a.end(), tar) - a.begin();

    if (index <= 1)
        cout << "32\n";
    else if (index <= 5)
        cout << "16\n";
    else if (index <= 12)
        cout << "8\n";
    else if (index <= 26)
        cout << "4\n";
    else if (index <= 30)
        cout << "2\n";
    else
        cout << "1\n";
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
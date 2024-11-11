#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
int main() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for(int i = 0; i < n;i ++) {
        cin >> a[i];
    }

    i64 now = 1500;
    for(int i = 0; i < n; i++){ 
        now += a[i] ;
        if(now >= 4000) {
            cout << (i + 1) << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}
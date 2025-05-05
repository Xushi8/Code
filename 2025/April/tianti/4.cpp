#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<i64, 35> a;
    a[0] = 1;
    for (int i = 1; i < 35; i++) {
        a[i] = a[i - 1] * 2;
    }

    // for (int i = 0; i < 35; i++) {
    //     cout << a[i] << '\n';
    // }

    i64 x;
    cin >> x;

    auto it = lower_bound(a.begin(), a.end(), x);

    if(*it == x) {
        cout << x << '\n';
    } else {
        cout << *--it << '\n';
    }
}
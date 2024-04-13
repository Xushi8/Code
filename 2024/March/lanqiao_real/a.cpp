#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool is_lun(int year) {
    set<int> st = { 2000, 2004, 2008, 2012, 2016, 2020, 2024 };
    return st.count(year);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt[] = { 13, 1, 2, 3, 5, 4, 4, 2, 2, 2 };

    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int ans = 0;
    for (int y = 2000; y <= 2024; y++) {
        for (int m = 1; m <= 12; m++) {
            for (int d = 1; d <= days[m] || (is_lun(y) && d <= 29); d++) {
                int t = y;
                int now = 0;
                while (t) {
                    now += cnt[t % 10];
                    t /= 10;
                }
                now += cnt[m / 10] + cnt[m % 10] + cnt[d / 10] + cnt[d % 10];
                if (now > 50) {
                    ans++;
                }

                if (y == 2024 && m == 4 && d == 13) {
                    goto out;
                }
            }
        }
    }
out:
    cout << ans << endl;

    return 0;
}
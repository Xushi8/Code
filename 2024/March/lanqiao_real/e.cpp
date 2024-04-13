#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, T;
    cin >> n >> k >> T;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tmp(a.begin(), a.begin() + k - 1);
    sort(tmp.begin(), tmp.end());

    int ans = -1;
    for (int i = k - 1; i < n; i++) {
        tmp.insert(lower_bound(tmp.begin(), tmp.end(), a[i]), a[i]);
        ll sum = 0;
        for (int j = 0; j < k; j++) {
            sum += tmp[j];
        }
        for (int be = 0; be + k <= i + 1; be++) {
            if (be != 0) {
                sum -= tmp[be - 1];
                sum += tmp[be + k - 1];
            }
            double ave = 1.0 * sum / k;
            double now_sum = 0;
            for (int j = be; j <= be + k - 1; j++) {
                now_sum += (tmp[j] - ave) * (tmp[j] - ave);
            }
            double fangcha = now_sum / k;
            if (fangcha < T) {
                ans = i + 1;
                goto out;
            }
        }
    }

out:
    cout << ans << endl;

    return 0;
}
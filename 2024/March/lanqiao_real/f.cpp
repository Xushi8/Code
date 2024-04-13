// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;

// constexpr size_t N = 100005;

// bool isnp[N];
// vector<int> primes;
// void get_prime() {
//     for (int i = 2; i < N; i++) {
//         if (!isnp[i])
//             primes.emplace_back(i);
//         for (int p : primes) {
//             if (p * i >= N)
//                 break;
//             isnp[p * i] = 1;
//             if (i % p == 0)
//                 break;
//         }
//     }
// }

// set<int> get_jiao(set<int> const& x, set<int> const& y) {
//     auto it1 = x.begin(), it2 = y.begin();
//     set<int> res;
//     while (it1 != x.end() && it2 != y.end()) {
//         while (it1 != x.end() && *it1 < *it2)
//             it1++;
//         while (it2 != y.end() && *it2 < *it1)
//             it2++;
//         if (*it1 == *it2)
//             res.emplace(*it1++);
//     }
//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     get_prime();
//     // cerr << isnp[1] << endl;
//     map<int, int> cnt;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         if (isnp[x])
//             continue;
//         cnt[x]++;
//     }

//     map<int, set<int>> yinzi;
//     for (auto x : cnt) {
//         int val = x.first;
//         int t = val;
//         set<int> tmp;
//         for (auto p : primes) {
//             if (p * p > val)
//                 break;
//             while (val % p == 0) {
//                 tmp.insert(p);
//                 val /= p;
//                 auto it = yinzi.find(val);
//                 if (it != yinzi.end()) {
//                     tmp.insert(it->second.begin(), it->second.end());
//                     val = 1;
//                     goto out;
//                 }
//             }
//         }
//         if (val != 1) {
//             tmp.emplace(val);
//         }
//         tmp.emplace(1);
//         tmp.emplace(t);
//         for (auto it = tmp.begin(); it != tmp.end(); it++) {
//             if (cnt[*it] == 0) {
//                 it = tmp.erase(it);
//                 it--;
//             }
//         }
//     out:
//         yinzi[t] = std::move(tmp);
//     }

//     ll ans = 0;
//     for (auto p : cnt) {
//         int val = p.first;
//         int sum = 0;
//         for (auto x : yinzi[val]) {
//             sum += cnt[x];
//         }
//         ans += cnt[val] * (cnt[val] - 1) * sum;
//     }

//     for (auto it1 = cnt.begin(); it1 != cnt.end(); it1++) {
//         for (auto it2 = it1; it2 != cnt.end(); it2++) {
//             if (it2 == it1)
//                 continue;
//             auto jiaoji = get_jiao(yinzi[it1->first], yinzi[it2->first]);
//             ll sum1 = 0, sum2 = 0, sum3 = 0;
//             for (auto x : yinzi[it1->first]) {
//                 sum1 += cnt[x];
//                 if (jiaoji.count(x))
//                     sum2 += cnt[x];
//             }
//             for (auto x : yinzi[it2->first]) {
//                 if (!jiaoji.count(x))
//                     sum3 += cnt[x];
//             }

//             ans += sum1 * sum3 + sum2 * (sum2 - 1);
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }


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

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    set<int> st;
                    st.emplace(i);
                    st.emplace(j);
                    st.emplace(k);
                    st.emplace(l);
                    if (st.size() == 4) {
                        int gcd1 = __gcd(a[i], a[k]);
                        int gcd2 = __gcd(a[j], a[l]);
                        if (((gcd1 != 1 && a[i] <= a[k]) || a[i] == 1) &&
                            ((gcd2 != 1 && a[j] <= a[l]) || a[j] == 1)) {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
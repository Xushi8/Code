// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// array<array<int, 5>, 5> a;
// // set < array<array<int, 5>, 5>> st;
// ll ans = 0;
// // 1 白, 2黑

// bool check() {
//     // 横着
//     for (int i = 0; i < 5; i++) {
//         int sum = 0;
//         for (int j = 0; j < 5; j++) {
//             sum += a[i][j];
//         }
//         if (sum == 5 || sum == 10) {
//             return false;
//         }
//     }

//     // 竖着
//     for (int j = 0; j < 5; j++) {
//         int sum = 0;
//         for (int i = 0; i < 5; i++) {
//             sum += a[i][j];
//         }
//         if (sum == 5 || sum == 10) {
//             return false;
//         }
//     }
//     // 斜着
//     int sum;
//     sum = a[0][0] + a[1][1] + a[2][2] + a[3][3] + a[4][4];
//     if (sum == 5 || sum == 10) {
//         return false;
//     }

//     sum = a[4][0] + a[3][1] + a[2][2] + a[1][3] + a[0][4];
//     if (sum == 5 || sum == 10) {
//         return false;
//     }

//     return true;
// }

// void dfs(int x, int y) {
//     if (y == 5) {
//         x++;
//         y = 0;
//         if (x == 5) {
//             if (check()) {
//                 ans++;
//                 // st.emplace(a);
//             }
//             return;
//         }
//     }
//     a[x][y] = 1;
//     dfs(x, y + 1);
//     a[x][y] = 2;
//     dfs(x, y + 1);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     dfs(0, 0);
//     // cout << st.size() << endl;
//     cout << ans << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

array < array<int, 5>, 5 > a;

bool check() {
    // 横着
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += a[i][j];
        }
        if (sum == 5 || sum == 10) {
            return false;
        }
    }

    // 竖着
    for (int j = 0; j < 5; j++) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += a[i][j];
        }
        if (sum == 5 || sum == 10) {
            return false;
        }
    }
    // 斜着
    int sum;
    sum = a[0][0] + a[1][1] + a[2][2] + a[3][3] + a[4][4];
    if (sum == 5 || sum == 10) {
        return false;
    }

    sum = a[4][0] + a[3][1] + a[2][2] + a[1][3] + a[0][4];
    if (sum == 5 || sum == 10) {
        return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ans = 0;
    for (int S = 0; S < (1 << 25); S++) {
        // 1 为白
        if (__builtin_popcount(S) == 13) {
            int tot = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    a[i][j] = (S >> tot) & 1;
                    tot++;
                    a[i][j]++;
                }
            }
            if (check()) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
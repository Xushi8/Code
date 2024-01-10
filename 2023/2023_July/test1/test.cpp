// // // #include <iostream>
// // // #include <cstring>
// // // #include <algorithm>
// // // #include <stack>
// // // #include <queue>
// // // #include <cstdio>

// // // using namespace std;
// // // const int N = 1000010;
// // // typedef long long LL;

// // // int n, k;
// // // int a[N];
// // // int hh = 0, tt = -1;
// // // int q[N];
// // // int h[N];

// // // int s[N];

// // // int main(void) {

// // //     scanf("%d%d", &n, &k);
// // //     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
// // //     s[1] = a[1];
// // //     for (int i = 1; i <= k; i++) {
// // //         while (hh <= tt && a[i] < q[tt]) tt--;
// // //         q[++tt] = a[i];

// // //         s[i] = q[hh];
// // //     }
// // //     for (int i = k + 1; i <= n; i++) {
// // //         if (q[hh] == a[i - k]) hh++;
// // //         while (hh <= tt && a[i] < q[tt]) tt--;
// // //         q[++tt] = a[i];

// // //         s[i] = q[hh];
// // //     }
// // //     for (int i = k; i <= n; i++) {
// // //         printf("%d ", s[i]);
// // //     }
// // //     puts("");
// // //     tt = -1, hh = 0;
// // //     for (int i = 1; i <= k; i++) {
// // //         while (hh <= tt && a[i] > q[tt]) tt--;
// // //         q[++tt] = a[i];

// // //         s[i] = q[hh];
// // //     }
// // //     for (int i = k + 1; i <= n; i++) {
// // //         if (q[hh] == a[i - k]) hh++;
// // //         while (hh <= tt && a[i] > q[tt]) tt--;
// // //         q[++tt] = a[i];

// // //         s[i] = q[hh];
// // //     }

// // //     for (int i = k; i <= n; i++) {
// // //         printf("%d ", s[i]);
// // //     }

// // //     return 0;
// // // }
// // // 2023/07/17 23:54:57
// // #include <iostream>
// // #include <algorithm>
// // #include <cstring>
// // #include <cstdint>
// // #include <vector>
// // #include <string>
// // #include <set>
// // #include <map>
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <queue>
// // #include <functional>
// // #include <iomanip>
// // #include <bitset>
// // using namespace std;

// // using ll = long long;
// // using ull = unsigned long long;
// // using pii = pair<int, int>;
// // const int INF = 0x3f3f3f3f;
// // const int MOD = (int)(1e9 + 7);
// // const int N = 1000005;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);
    
// //     vector<int> arr(10);
// //     auto it1 = arr.begin();
// //     auto it2 = arr.end();
// //     auto x = it2 - it2;
// //     cout << x << endl;

// //     cout << endl;
// //     return 0;
// // }


// //=========================
// //  author:tyqs
// //  date:2019.12.3
// //  website:http://tyqs.kim
// //=========================
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #define N 20
// #define il inline
// #define re register
// #define tie0 cin.tie(0),cout.tie(0)
// #define fastio ios::sync_with_stdio(false)
// #define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
// using namespace std;
// typedef long long ll;

// template <typename T> inline void read(T& x) {
//     T f = 1; x = 0; char c;
//     for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
//     for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
//     x *= f;
// }

// int n, lst, ans;
// int d[N], r[N];
// bool flg;

// bool cmp(int x, int y) { return d[x] < d[y]; }

// int main() {
//     read(n);
//     for (int i = 1; i <= n; ++i) read(d[i]), r[i] = i;
//     sort(r + 1, r + 1 + n, cmp), sort(d + 1, d + 1 + n);
//     for (int i = 1; i <= n; ++i) {
//         int p = i, mx = r[i], mn = r[i];
//         while (d[p] == d[p + 1]) mx = max(mx, r[p + 1]), mn = min(mn, r[p + 1]), p++;
//         if (!flg) {
//             if (mx < lst) lst = mn;
//             else lst = mx, flg = 1;
//         }
//         else {
//             if (mn > lst) lst = mx;
//             else lst = mn, ans++, flg = 0;
//         }
//         i = p;
//     }
//     printf("%d", ans);
//     return 0;
// }









































// 2023/07/19 21:57:49
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <bitset>
#include <fstream>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

ofstream ofs;

inline void func(int n, char a, char b, char c)
{
    if (n == 0)
        return;

    func(n - 1, a, c, b); // 把 n - 1 个挪到B
    ofs << a << "->" << c << '\n'; // 把 最下面的挪到C
    func(n - 1, b, a, c); // 把B中的n - 1个挪到C
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ofs.open("test.data");
    func(15, 'A', 'B', 'C');
    
    cout << endl;
    return 0;
}
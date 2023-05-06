// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;
// typedef long long LL;

// const int N = 45000;

// int primes[N], cnt;
// bool st[N];
// int dividor[N], cntd;

// int n;
// struct Factor {
//     int p, s;
// }factor[50];
// int cntf;

// void get_primes(int n) {
//     for (int i = 2; i <= n; i++)
//     {
//         if (!st[i]) primes[cnt++] = i;

//         for (int j = 0; primes[j] <= n / i; j++) {
//             st[primes[j] * i] = 1;
//             if (i % primes[j] == 0)  break;
//         }
//     }
// }

// void dfs(int u, int p) {
//     if (u > cntf) {

//         dividor[cntd++] = p;
//         return;
//     }

//     for (int i = 0; i <= factor[u].s; i++) {
//         dfs(u + 1, p);
//         p *= factor[u].p;
//     }
// }


// int gcd(int a, int b) {
//     return b ? gcd(b, a % b) : a;
// }


// int main(void) {
//     scanf("%d", &n);

//     get_primes(N - 1);
//     while (n--) {
//         int a, b, c, d;
//         scanf("%d%d%d%d", &a, &b, &c, &d);

//         int t = d;
//         cntf = 0;
//         for (int i = 0; primes[i] <= t / primes[i]; i++) {
//             int p = primes[i];

//             if (t % p == 0) {
//                 int s = 0;
//                 while (t % p == 0) t /= p, s++;
//                 factor[++cntf] = { p, s };
//             }
//         }

//         if (t > 1) factor[++cnt] = { t, 1 };

//         cntd = 0;
//         dfs(1, 1);

//         int res = 0;
//         for (int i = 0; i < cntd; i++) {
//             int x = dividor[i];
//             if (gcd(a, x) == b && (LL)c * x / gcd(c, x) == d) res++;
//         }

//         cout << res << endl;
//     }


//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str = "1245";
    string tmp = "12";
    cout << str.find(tmp);

    cout << flush;
    system("pause");
    return 0;
}
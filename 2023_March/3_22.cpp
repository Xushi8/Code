#include <bits/stdc++.h>
using namespace std;

// int n, W, v[10005], w[10005];
// long long f[10000005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin >> n >> W;
//     int tot = 1;
//     for (int i = 0; i < n; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         for (int k = 1; k <= c; k *= 2)
//         {
//             v[tot] = k * a;
//             w[tot++] = k * b;
//             c -= k;
//         }
//         if (c > 0)
//         {
//             v[tot] = c * a;
//             w[tot++] = c * b;
//         }
//     }

//     for (int i = 1; i < tot; i++)
//     {
//         for (int j = W; j >= w[i]; j--)
//         {
//             f[j] = max(f[j], f[j - w[i]] + v[i]);
//         }
//     }
//     cout << f[W];

//     cout << flush;
//     system("pause");
//     return 0;
// }



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int, vector<int>, less<int>> arr;
    for (int i = 0; i < 5; i++)
    {
        arr.emplace(i);
    }
    while (!arr.empty())
    {
        cout << arr.top() << '\n';
        arr.pop();
    }

    cout << flush;
    system("pause");
    return 0;
}
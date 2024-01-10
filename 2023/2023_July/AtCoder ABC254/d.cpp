// 2023/07/11 13:58:01
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;


ull func(int n)
{
    ull ret = 1;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;

        int cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt & 1)
            ret *= i;
    }

    ret *= n;
    return ret;
}

ull the_ans[200005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> arr(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//         arr[func(i)]++;


//     ull ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         ans += 1ULL * arr[i] * arr[i];
//     }

//     cout << ans << '\n';


//     cout << endl;
//     return 0;
// }

// 2023/07/13 22:47:48

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int tt = 1; tt <= 20000; tt++)
    {
        int n = tt;
        vector<int> arr(n + 1, 0);
        for (int i = 1; i <= n; i++)
            arr[func(i)]++;

        ull ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += 1ULL * arr[i] * arr[i];
        }
        the_ans[tt] = ans;
    }

    ofstream ofs;

    for (int i = 1; i <= 20000; i++)
    {
        cout << the_ans[i] << '\n';
    }

    cout << endl;
    return 0;
}
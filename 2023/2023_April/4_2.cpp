#include <bits/stdc++.h>
using namespace std;

// void func(int n, char a, char b, char c)
// {
//     if (n == 0) return;
//     func(n - 1, a, c, b);
//     cout << a << "->" << c << '\n';
//     func(n - 1, b, a, c);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     char a = 'A', b = 'B', c = 'C';
//     func(n, a, b, c);

//     cout << flush;
//     system("pause");
//     return 0;
// }

// ostream& operator << (ostream& out, __uint128_t& num)
// {
//     int arr[40] = {0};
//     int i = 0;
//     __uint128_t tmp = 10;
//     while (num != 0)
//     {
//         arr[i++] = num % tmp;
//         num /= tmp;
//     }
//     for (int j = 0; j < i; j++)
//     {
//         cout << arr[j];
//     }
//     return out;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     __uint128_t i = LLONG_MAX;
//     cout << i << '\n';
//     i++;
//     cout << i << '\n';

//     cout << flush;
//     system("pause");
//     return 0;
// }

// typedef pair<int, int> P;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, k, s;
//     cin >> n >> k >> s;
//     vector<P> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].first >> arr[i].second;
//     }
//     cout << '\n';
//     sort(arr.begin(), arr.end(), greater<P>());
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i].first << ' ' << arr[i].second << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m, tt;
//     cin >> n >> m >> tt;
//     long long ans = n * m;
//     set<int> k1, k2;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a == 0)
//         {
//             if (k1.count(b) == 0)
//             {
//                 ans -= m;
//                 k1.emplace(b);
//             }
//         }
//         else
//         {
//             if (k2.count(b) == 0)
//             {
//                 ans -= n;
//                 k2.emplace(b);
//             }
//         }
//     }
//     ans += k1.size() * k2.size();
//     cout << ans;

//     cout << flush;
//     system("pause");
//     return 0;
// }


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        int tmp = 0;
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            tmp ^= a;
        }
        if (n & 1)
        {
            cout << tmp << '\n';
        }
        else
        {
            if (tmp == 0)
                cout << a;
            else
                cout << -1;
            cout << '\n';
        }
    }

    cout << flush;
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     int a;
//     while (cin >> a)
//     {
//         if (a == 0)
//         {
//             cout << sizeof(int*) << ' ' << sizeof(int);
//         }
//         else if (a == 1)
//         {
//             cout << sizeof(long long*) << ' ' << sizeof(long long);
//         }
//         else if (a == 2)
//         {
//             cout << sizeof(float*) << ' ' << sizeof(float);
//         }
//         else
//         {
//             cout << sizeof(double*) << ' ' << sizeof(double);
//         }

//         cout << endl;
//     }



//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n = 0;
//     int& m = n;
//     int tt;
//     cin >> tt;
//     int tmp;
//     while (cin >> tmp)
//     {
//         if (tmp == 0 || tmp == 1)
//         {
//             int a;
//             cin >> a;
//             m = a;
//         }
//         else
//         {
//             cout << n << '\n';
//         }
//     }

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
        int a;
        cin >> a;
        int b, c, d;
        b = a * 0.1 + 0.99;
        c = a * 0.3 + 0.99 - b;
        d = a * 0.6 + 0.99 - b - c;
        cout << b << '\n' << c << '\n' << d << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}
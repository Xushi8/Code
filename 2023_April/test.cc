// 2023/05/24 22:40:21
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr)
        cin >> x;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int tmp;
        cin >> tmp;
        cout << binary_search(arr.begin(), arr.end(), tmp) << '\n';
    }



    

    // int a, b, c, d;
    // cin >> a >> b >> c >> d;
    // int tt;
    // cin >> tt;
    // int x, y;
    // double A, B, C;
    // A = d - b;
    // B = a - c;
    // C = b * c - a * d;

    // while (tt--)
    // {
    //     cin >> x >> y;
    //     cout << setprecision(8) << fixed << (B * B * x - A * B * y - A * C) / (A * A + B * B) << ' ';
    //     cout << (-A * B * x + A * A * y - B * C) / (A * A + B * B) << '\n';
    // }


    
    // while (tt--)
    // {
    //     cin >> x >> y;
    //     cout << setprecision(10) << fixed << -(2 * y * A * B + (A * A - B * B) * x + 2 * A * C) / (A * A + B * B) << ' ';
    //     cout << -((B * B - A * A) * y + 2 * A * B * x + 2 * B * C) / (A * A + B * B) << '\n';
    // }



    cout << flush;
    system("pause");
    return 0;
}
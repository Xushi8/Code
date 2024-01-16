// 2024/01/15 15:16:30
#include <iostream>
#include <numeric>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int the_gcd = gcd(a, b);
    a /= the_gcd;
    b /= the_gcd;
    for (int i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            if (a == i * i + (b / i) * (b / i))
            {
                cout << i << ' ' << b / i << '\n';
                return;
            }
        }
    }

    cout << "0 0\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        string n;
        cin >> a >> b >> n;
        if ((n[n.size() - 1] - 48) & 1)
        {
            cout << a * a + a * b - b * b << '\n';
        }
        else
        {
            cout << -(a * a) - a * b + b * b << '\n';
        }
    }

    cout << flush;
    system("pause");
    return 0;
}
// 2023/05/30 11:29:03
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    cout << sum << sum << endl;

    cout << flush;
    return 0;
}
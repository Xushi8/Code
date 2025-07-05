// 2023:04:14 19:01:01
#include <bits/stdc++.h>
using namespace std;

// (q & r) | (p & (q ^ r))
int func(int p, int q, int r)
{
    return (q & r) | (p & (q ^ r));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int p, q, r;
    cin >> p >> q >> r;
    cout << func(p, q, r) << endl;

    cout << flush;
    system("pause");
    return 0;
}
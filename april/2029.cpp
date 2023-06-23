// 2023/04/26 22:29:29
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double h, r;
    cin >> h >> r;
    double V = 3.14 * h * r * r;
    cout << (int)(20000 / V + 0.999);

    cout << endl;
    return 0;
}
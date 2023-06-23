// 2023/04/26 22:18:23
#include <bits/stdc++.h>
using namespace std;



int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    printf("%.1lf", sqrt(p * (p - a) * (p - b) * (p - c)));

    
    cout << endl;
    return 0;
}
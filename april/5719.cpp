// 2023/04/27 11:52:48
#include <bits/stdc++.h>
using namespace std;



int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    int k;
    cin >> n >> k;
    vector<int> a, b;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            a.emplace_back(i);
        }
        else
        {
            b.emplace_back(i);
        }
    }
    int c, d;
    c = 0; d = 0;
    for (int p : a)
        c += p;
    for (int p : b)
        d += p;
    printf("%.1lf %.1lf", (double)c / a.size(), (double)d / b.size());

    cout << endl;
    return 0;
}
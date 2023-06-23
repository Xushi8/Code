// 2023/05/08 21:41:28
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand((unsigned)time(nullptr));
    int ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        int a = rand();
        if (a <= 100000) ans++;
    }
    cout << ans << endl;
    cout << ans / 1000000000. << endl;

    cout << endl;
    return 0;
}
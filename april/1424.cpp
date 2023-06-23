// 2023/04/26 18:36:37
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, n;
    cin >> x >> n;
    unsigned long long ans = 0;
    ans += n / 7ULL * 5 * 250;
    n %= 7;
    int y = x + n;
    int arr[15] = { 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0 };
    for (int i = x; i < y; i++)
    {
        ans += arr[i] * 250;
    }
    cout << ans;

    cout << endl;
    return 0;
}
// 2023/04/27 11:30:22
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    uint64_t ans = 0;
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        uint64_t tmp = (n / a + (n % a != 0)) * b;
        if (ans == 0 || ans > tmp)
        {
            ans = tmp;
        }
    }
    cout << ans;

    cout << endl;
    return 0;
}
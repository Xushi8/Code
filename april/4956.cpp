// 2023/04/27 13:20:35
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 100; i > 0; i--)
    {
        for (int j = 1; j < n; j++)
        {
            int arr[7] = { i,i + j,i + 2 * j,i + 3 * j,i + 4 * j,i + 5 * j,i + 6 * j };
            int sum = 0;
            for (int k = 0; k < 7; k++)
            {
                sum += arr[k];
            }
            if (sum * 52 == n)
            {
                cout << i << endl;
                cout << j << endl;
                return 0;
            }
        }
    }


    cout << endl;
    return 0;
}
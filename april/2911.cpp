// 2023/04/27 16:40:36
#include <bits/stdc++.h>
using namespace std;


int arr[10000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                arr[i + k + j]++;
            }
        }
    }
    int ans = -1;
    int index = -1;
    for (int i = 0; i < 1000000; i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
            index = i;
        }
    }
    cout << index;

    cout << endl;
    return 0;
}
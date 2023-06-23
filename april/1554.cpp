// 2023/04/27 16:23:11
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    int arr[10] = { 0 };
    for (int i = m; i <= n; i++)
    {
        int j = i;
        while (j)
        {
            arr[j % 10]++;
            j /= 10;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    

    cout << endl;
    return 0;
}
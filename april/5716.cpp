// 2023/04/27 11:35:09
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
    {
        int arr[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
        cout << arr[b];
    }
    else
    {
        int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        cout << arr[b];
    }

    cout << endl;
    return 0;
}
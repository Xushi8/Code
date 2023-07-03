// 2023/04/27 12:57:30
#include <bits/stdc++.h>
using namespace std;


int arr[1005];
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int sum = 0;
    for (int i = 1; i < n - 1; i++)
    {
        sum += arr[i];
    }
    printf("%.2lf", (double)sum / (n - 2));

    cout << endl;
    return 0;
}
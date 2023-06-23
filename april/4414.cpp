// 2023/04/27 11:45:04
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int arr[3];
    string str;
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    cin >> str;
    cout << arr[str[0] - 'A'] << ' ' << arr[str[1] - 'A'] << ' ' << arr[str[2] - 'A'];

    cout << endl;
    return 0;
}
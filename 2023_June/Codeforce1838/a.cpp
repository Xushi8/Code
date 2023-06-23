// 2023/06/04 22:59:04
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& x : arr)
            cin >> x;
        sort(arr.begin(), arr.end());
        if (arr[0] < 0)
        {
            cout << arr[0] << '\n';
        }
        else
        {
            cout << arr.back() << '\n';
        }
    }

    cout << endl;
    system("pause");
    return 0;
}
// 2023/06/11 23:18:27
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        arr[i] = i;
    }

    int begin = clock();
    for (int& x : arr)
    {
        cout << x;
    }
    int end = clock();
    cout << endl;
    cout << (end - begin) / 1000. << endl;

    cout << flush;
    return 0;
}
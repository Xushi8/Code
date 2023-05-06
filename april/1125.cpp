// 2023/04/27 17:24:10
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int arr[26] = {0};
    int ch;
    while ((ch = cin.get()) != EOF)
    {
        arr[ch - 'a']++;
    }
    sort(arr, arr + 26);
    int tmp;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            tmp = arr[25] - arr[i];
            break;
        }
    }
    
    bool flag = 0;
    if (tmp == 0 || tmp == 1)
    {
        flag = 1;
    }
    
    for (int i = 2; i < tmp; i++)
    {
        if (tmp % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "No Answer\n" << 0;
    }
    else
    {
        cout << "Lucky Word\n" << tmp;
    }

    cout << endl;
    return 0;
}
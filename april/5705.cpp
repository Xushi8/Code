// 2023/04/26 22:10:11
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char str[10000];
    cin >> str;
    int len = (int)strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        swap(str[i], str[len - i - 1]);
    }
    cout << str;

    cout << endl;
    return 0;
}
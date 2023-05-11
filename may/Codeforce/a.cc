// 2023/05/06 22:34:50
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    string str = "codeforces";
    while (tt--)
    {
        string tmp;
        cin >> tmp;
        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (tmp[i] != str[i])
                cnt++;
        }
        cout << cnt << '\n';
    }

    cout << endl;
    return 0;
}
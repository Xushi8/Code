// 2023/05/06 22:35:08
#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b)
{
    if (a == b)
    {
        return true;
    }
    
    if (a / 3 * 2 < b)
    {
        return false;
    }
    if (a % 3 != 0)
    {
        return false;
    }
    
    if (a / 3 == b)
    {
        return true;
    }
    if (a / 3 * 2 == b)
    {
        return true;
    }
    return check(a / 3, b) || check(a / 3 * 2, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            if (b == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }
        
        
        if (check(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    cout << endl;
    return 0;
}
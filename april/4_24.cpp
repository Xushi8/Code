// 2023/04/24 13:23:13
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string ans;
    cin >> ans;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b;
        string c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        string tmp;
        tmp = ans.substr(a, b - a + 1);
        ans.erase(a, b - a + 1);
        size_t pos = ans.find(c + d);

        if (pos == -1)
            ans += tmp;
        else
            ans.insert(pos + c.size(), tmp);
    }
    cout << ans << endl;

    cout << flush;
    return 0;
}
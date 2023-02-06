#include<bits/stdc++.h>
using namespace std;
int n, m;



int main()
{
    cin >> n >> m;
    string tmp;
    getline(cin, tmp);
    set<string> str;
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        str.insert(tmp);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        getline(cin, tmp);
        if (str.find(tmp) != str.end())
        {
            ans++;
        }
    }

    cout << ans << endl;

    system("pause");
    return 0;
}
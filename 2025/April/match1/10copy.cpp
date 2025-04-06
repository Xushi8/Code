#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> mp;

int N;

signed main()
{
    cin >> N;
    getchar();
    string s;
    for (int i = 1; i <= N; ++i)
    {
        getline(cin, s);
        string tmp = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
                tmp += s[i];
        }
        // cout << tmp << endl;
        mp[tmp].push_back(s);
    }
    for (auto& x : mp)
    {
        sort(x.second.begin(), x.second.end());
    }

    int M;
    cin >> M;
    getchar();
    while (M--)
    {
        string s;
        getline(cin, s);
        string tmp = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if ((!i || s[i - 1] == ' ') && s[i] != ' ')
                tmp += s[i];
        }
        if (mp[tmp].size() == 0)
            cout << s << endl;
        else
        {
            int cnt = 0;
            for (auto& x : mp[tmp])
            {
                if (!cnt)
                {
                    cout << x;
                    ++cnt;
                }
                else
                    cout << "|" << x;
            }
            cout << endl;
        }
    }

    return 0;
}
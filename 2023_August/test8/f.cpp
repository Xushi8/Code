#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

constexpr int N = 105;
int nex[N];
void solve(const string& s)
{
    nex[0] = -1;
    for (int i = 0, j = -1; i < (int)s.size(); )
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            nex[i] = j;
        }
        else
        {
            j = nex[j];
        }
    }

    vector<int> ans;
    int tmp = nex[s.size() - 1];
    while (tmp != -1)
    {
        if (s[tmp] == s.back())
            ans.emplace_back(tmp + 1);
        tmp = nex[tmp];
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++)
    {
        cout << *it << ' ';
    }
    cout << s.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while (cin >> s)
    {
        solve(s);
    }

    cout << flush;
    return 0;
}
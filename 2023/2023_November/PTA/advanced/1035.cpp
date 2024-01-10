// 2023/11/14 20:20:15
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> mp;
    mp.emplace('1', '@');
    mp.emplace('0', '%');
    mp.emplace('l', 'L');
    mp.emplace('O', 'o');
    int n;
    cin >> n;
    vector<pair<string, string>> ans;
    for (int i = 0; i < n; i++)
    {
        string name, s;
        cin >> name >> s;
        bool flag = 0;
        for (char& ch : s)
        {
            if (mp.count(ch) != 0)
            {
                flag = 1;
                ch = mp[ch];
            }
        }
        if (flag)
        {
            ans.emplace_back(name, s);
        }
    }

    if (ans.empty())
    {
        if (n == 1)
            cout << "There is " << 1 << " account and no account is modified";
        else
        {
            cout << "There are " << n << " accounts and no account is modified";
        }
    }
    else
    {
        cout << ans.size() << endl;
        for (auto [x, y] : ans)
        {
            cout << x << ' ' << y << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
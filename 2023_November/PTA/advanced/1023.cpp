// 2023/11/08 17:16:24
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

    unordered_map<string, set<string>> mp[5];
    int n;
    cin >> n;
    cin.ignore(999, '\n');
    for (int i = 0; i < n; i++)
    {
        string id, title, author, key, publisher, year;
        getline(cin, id);
        getline(cin, title);
        mp[0][title].emplace(id);
        getline(cin, author);
        mp[1][author].emplace(id);
        do
        {
            cin >> key;
            mp[2][key].emplace(id);
        } while (cin.get() == ' ');
        getline(cin, publisher);
        mp[3][publisher].emplace(id);
        getline(cin, year);
        mp[4][year].emplace(id);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int i;
        char ch;
        cin >> i >> ch;
        cin.get();
        string text;
        getline(cin, text);
        cout << i << ':' << ' ' << text << '\n';

        if (mp[i - 1][text].empty())
        {
            cout << "Not Found\n";
        }
        else
        {
            for (const auto& each : mp[i - 1][text])
            {
                cout << each << '\n';
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
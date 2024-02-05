// 2024/02/04 14:24:18
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

    int n;
    cin >> n;
    vector<string> s(n);
    cin.ignore(1024, '\n');
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string a = s[i], b = s[j];
            int now = 0;
            for (int la = a.size() - 1, lb = b.size() - 1; la >= 0 && lb >= 0; la--, lb--)
            {
                if (a[la] == b[lb])
                    now++;
                else
                    break;
            }
            ans = min(ans, now);
        }
    }

    if (ans == 0)
        cout << "nai" << endl;
    else
    {
        cout << s[0].substr(s[0].size() - ans) << endl;
    }

#ifdef LOCAL
    cerr
        << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
// 2024/01/18 09:33:10
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

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size();)
    {
        int j = 0;
        while (j < t.size() && s[i] != t[j])
            j++;
        int pre = j;
        if (pre == t.size())
        {
            cout << "No\n";
            return 0;
        }

        while (pre < t.size() && i - pre >= 0)
        {
            bool flag = 0;
            for (int k = 0; k < pre; k++)
            {
                if (s[i - pre + k] != t[k])
                {
                    pre++;
                    flag = 1;
                    break;
                }
            }
            if (!flag) break;
        }

        if (pre == t.size())
        {
            cout << "No\n";
            return 0;
        }

        while (j < t.size() && s[i] == t[j])
            j++;
        if (j == pre)
        {
            cout << "No\n";
            return 0;
        }
        i += j;
    }

    cout << "Yes\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
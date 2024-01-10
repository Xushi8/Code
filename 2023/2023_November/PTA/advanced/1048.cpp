// 2023/11/14 21:53:14
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

    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    pii ans = {-1, -1};

    for (int i = k - 1; i > 0; i--)
    {
        int a = k - i;
        int b = i;
        if (a == b)
        {
            if (mp[a] >= 2)
            {
                ans = {a, b};
            }
            break;
        }

        if(mp[a] >= 1 && mp[b] >= 1) {
            ans = {a, b};
            break;
        }
    }

    if (ans.first == -1)
    {
        cout << "No Solution\n";
    }
    else
    {
        cout << ans.first << ' ' << ans.second << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
// 2023/09/27 13:41:37
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
    string a, b;
    cin >> a >> b;
    vector<int> dis(n);
    for (int i = 0; i < n; i++)
    {
        dis[i] = b[i] - a[i] + 26;
    }

    int ans = 0;
    int adds = 0;
    for (int i = 0; i < n; i++)
    {
        if ((adds + dis[i]) % 26 != 0)
        {
            ans++;
            adds += 26 - (adds + dis[i]) % 26;
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
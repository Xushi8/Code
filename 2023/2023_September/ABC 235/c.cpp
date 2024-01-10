// 2023/09/03 14:50:40
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
    map<pii, int> mp;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        mp[make_pair(x, cnt[x])] = i + 1;
    }

    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (mp.find(make_pair(a, b)) != mp.end())
            cout << mp.find(make_pair(a, b))->second;
        else
            cout << -1;
        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/07/15 20:57:41
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    set<string> s;
    int te = 0;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        s.emplace(tmp);
        reverse(tmp.begin(), tmp.end());
        s.emplace(tmp);
        if (tmp.size() == 1)
            te++;
    }

    size_t ans = 0;
    ans += te;
    ans += (s.size() - te) / 2;

    cout << ans << '\n';

    cout << endl;
    return 0;
}
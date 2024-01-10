// 2023/11/14 20:33:27
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

bool cmp(string const& x, string const& y)
{
    return x + y < y + x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end(), cmp);
    string ans;
    for (auto& x : s)
    {
        ans += move(x);
    }

    while (!ans.empty() && ans.front() == '0')
    {
        ans.erase(0, 1);
    }

    if (ans.empty())
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
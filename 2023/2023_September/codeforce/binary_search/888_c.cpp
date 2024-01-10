// 2023/10/03 14:21:51
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
    
    string s;
    cin >> s;
    vector<int> arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i].push_back(0);
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        arr[s[i] - 'a'].emplace_back(i + 1);
    }

    for (int i = 0; i < 26; i++)
    {
        arr[i].emplace_back(s.size() + 1);
    }

    int ans = 999999999;
    for (int i = 0; i < 26; i++)
    {
        int tmp = 0;
        for (size_t j = 1; j < arr[i].size(); j++)
        {
            tmp = max(tmp, arr[i][j] - arr[i][j - 1]);
        }
        ans = min(ans, tmp);
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/08/12 20:19:15
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
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int x;
            cin >> x;
            arr[i].emplace_back(x);
        }
    }

    int tar;
    cin >> tar;
    vector<int> ans;
    size_t minn = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int)arr[i].size(); j++)
        {
            if (arr[i][j] == tar)
            {
                if (arr[i].size() < minn)
                {
                    ans.clear();
                    minn = arr[i].size();
                    ans.emplace_back(i + 1);
                }
                else if (arr[i].size() == minn)
                {
                    ans.emplace_back(i + 1);
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (int p : ans)
    {
        cout << p << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
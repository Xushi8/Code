// 2023/09/18 18:35:29
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
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int t[4] = { 0 };
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        t[0]++;
        for (int j = 3; j >= 0; j--)
        {
            if (t[j] != 0)
            {
                t[j]--;
                int nex = j + arr[i];
                if (nex >= 4)
                    ans++;
                else
                    t[nex]++;
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
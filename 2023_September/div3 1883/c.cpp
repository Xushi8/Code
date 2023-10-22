// 2023/10/22 19:30:34
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = (k - x % k) % k;
    }

    if (k == 5 || k == 3 || k == 2)
    {
        cout << *min_element(arr.begin(), arr.end()) << '\n';
    }
    else
    {
        sort(arr.begin(), arr.end());
        int cnt = count(arr.begin(), arr.end(), 2);
        if (cnt >= 2 || arr.front() == 0)
            cout << 0 << '\n';
        else
        {
            if (arr.front() == 1)
                cout << "1\n";
            else
            {
                int cnt1 = count(arr.begin(), arr.end(), 3);
                if (cnt > 0 && cnt1 > 0)
                {
                    cout << "1\n";
                }
                else if (cnt == 0 && cnt1 > 0)
                {
                    cout << "2\n";
                }
                else if (cnt > 0 && cnt1 == 0)
                {
                    cout << "2\n";
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
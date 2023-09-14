// 2023/09/13 15:38:43
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

void solve()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    string ans;
    while (1)
    {
        int minn = -1;
        if (ans.empty())
        {
            for (int i = 1; i < 10; i++)
            {
                if (arr[i] > 0)
                {
                    minn = i;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (arr[i] > 0)
                {
                    minn = i;
                    break;
                }
            }
        }

        if (minn == -1)
        {
            if (arr[0] == 0)
                cout << ans << '\n';
            else
                cout << "-1\n";
            return;
        }

        int nex = -1;
        for (int i = 0; i < 10; i++)
        {
            if (i == minn)
                continue;

            if (arr[i] > 0)
            {
                nex = i;
                break;
            }
        }

        if (nex == -1)
        {
            if (minn > 1)
                cout << "-1\n";
            else
                cout << ans + to_string(minn) << '\n';
            return;
        }

        if (nex == 0)
        {
            if (ans.empty())
            {
                int t = min(arr[minn], arr[nex]);
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
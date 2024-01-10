// 2023/07/22 09:28:23
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
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n + 1), sum(n + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i - 1] + (arr[i] % 2 == 1);
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (ans.empty())
            {
                if ((sum[i] - sum[0]) % 2 == 1)
                {
                    if (ans.size() + 1 != k)
                    {
                        ans.emplace_back(i);
                    }
                    else
                    {
                        if (i == n)
                        {
                            ans.emplace_back(i);
                        }
                    }
                }
            }
            else
            {
                if ((sum[i] - sum[ans.back()]) % 2 == 1)
                {
                    if (ans.size() + 1 != k)
                    {
                        ans.emplace_back(i);
                    }
                    else
                    {
                        if (i == n)
                        {
                            ans.emplace_back(i);
                        }
                    }
                }
            }
        }

        if (ans.size() != k)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (size_t i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " \n"[i == ans.size() - 1];
            }
        }
    }

    cout << endl;
    return 0;
}
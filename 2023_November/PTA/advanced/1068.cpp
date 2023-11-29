// 2023/11/26 15:22:04
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
constexpr int N = 10005;

int arr[N];
int n, m;
vector<int> ans;

void dfs(int sum, int now)
{
    ans.emplace_back(arr[now]);
    if (sum == m)
    {
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
        exit(0);
    }

    for (int i = now + 1; i < n && sum + arr[i] <= m;)
    {
        dfs(sum + arr[i], i);
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] != arr[i])
            {
                break;
            }
        }
        i = j;
    }

    ans.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    for (int i = 0; i < n;)
    {
        dfs(arr[i], i);
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] != arr[i])
            {
                break;
            }
        }
        i = j;
    }

    cout << "No Solution\n";

#ifdef LOCAL
    cerr
        << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
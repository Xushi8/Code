// 2023/10/27 21:56:47
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

int arr[N], L[N], R[N], ans[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    stack<int> stk;
    for (int i = 1; i <= n; i++)
    {
        while (!stk.empty() && arr[i] <= arr[stk.top()])
        {
            stk.pop();
        }

        L[i] = stk.empty() ? 0 : stk.top();
        stk.emplace(i);
    }

    stack<int>().swap(stk);

    for (int i = n; i >= 1; i--)
    {
        while (!stk.empty() && arr[i] <= arr[stk.top()])
        {
            stk.pop();
        }
        R[i] = stk.empty() ? n + 1 : stk.top();
        stk.emplace(i);
    }

    for (int i = 1; i <= n; i++)
    {
        int len = R[i] - L[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
        
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/07/25 08:40:13
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
int n;
bool used[30];
vector<int> ans;

inline bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

void dfs(int deep, int pre) // 第一个是已经放的层数， 第二个是上一个数的值
{
    if (n == 1)
    {
        cout << "1\n";
        return;
    }

    if (deep == n - 1)
    {
        int tmp;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                tmp = i;
                break;
            }
        }

        ans.push_back(tmp);
        if (is_prime(ans[n - 1] + ans[n - 2])&&
            is_prime(ans.front() + ans.back()))
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " \n"[i == n - 1];
            }
        }

        ans.pop_back();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!used[i] && is_prime(i + pre))
        {
            ans.push_back(i);
            used[i] = 1;
            dfs(deep + 1, i);
            ans.pop_back();
            used[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 1;
    while (cin >> n)
    {
        used[1] = 1;
        ans.clear();
        ans.push_back(1);

        cout << "Case " << cnt++ << ":\n";
        dfs(1, 1);
        cout << '\n';
    }

    cout << endl;
    return 0;
}
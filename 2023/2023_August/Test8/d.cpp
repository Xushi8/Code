// 2023/08/12 11:20:49
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
ull ans = 0;
int n;
bool used[N];

string a, b;
unordered_map<string, int> mp;

void dfs(int deep)
{
    if (deep == n)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            string s;
            int cnt = 0;
            for (int j = 0; j < n && cnt <= deep; j++)
            {
                if (used[j])
                {
                    s += a[j];
                    cnt++;
                }
            }
            ans += mp[s];
            dfs(deep + 1);
            used[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> a >> b;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            string tmp = b.substr(i, j - i + 1);
            mp[move(tmp)]++;
        }
    }

    dfs(0);



    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
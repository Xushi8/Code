// 2023/07/06 16:48:06
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

int l[N], r[N];
char s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
            l[i] = l[i - 1] + 1;
        // shenglue
        // else
        //     l[i] = 0;
    }
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == 'C')
            r[i] = r[i + 1] + 1;
        // shenglue
        // else
        //     r[i] = 0;
    }

    cout << endl;
    return 0;
}
// 2023/09/02 20:47:06
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

int  arr[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++)
        {
            for (int j = c; j < d; j++)
            {
                arr[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 105; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            ans += arr[i][j];
        }
    }
    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
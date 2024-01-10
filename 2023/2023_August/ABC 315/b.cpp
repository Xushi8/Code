// 2023/08/19 20:06:43
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
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = (int)(1e9 + 7);
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int tim = sum / 2 + 1;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        now += arr[i];
        if (now >= tim)
        {
            now -= arr[i];
            cout << i + 1 << ' ' << tim - now << '\n';
            break;
        }
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/11/07 19:14:59
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int ans = n * 5;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = a[i] - now;
        if(tmp > 0) {
            ans += tmp * 6;
        } else {
            ans += -tmp * 4;
        }
        now = a[i];
    }

    cout << ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
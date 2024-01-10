// 2023/11/05 16:21:13
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

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt += a[i];
        }
        int one = cnt;
        int zero = n - one;
        if (zero >= one)
        {
            cout << zero << '\n';
            while (zero--)
                cout << 0 << ' ';
            cout << '\n';
        }
        else
        {
            if (one & 1)
                one--;
            cout << one << '\n';
            while (one--)
                cout << 1 << ' ';
            cout << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
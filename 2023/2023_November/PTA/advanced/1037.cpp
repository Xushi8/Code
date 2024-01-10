// 2023/11/14 20:27:06
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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());

    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        int tmp = a[i] * b[j];
        if (tmp >= 0)
        {
            ans += tmp;
            i++;
            j++;
        }
        else
        {
            break;
        }
    }

    int k = n - 1;
    int l = m - 1;
    while (k >= i && l >= j)
    {
        int tmp = a[k] * b[l];
        if (tmp >= 0)
        {
            ans += tmp;
            k--;
            l--;
        }
        else
        {
            break;
        }
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
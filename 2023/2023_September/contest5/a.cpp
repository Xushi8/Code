// 2023/09/13 13:58:40
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
        vector<string> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        if (a.back().back() == '1' || a.back().back() == '2' ||
            b.back().back() == '3' || b.back().back() == '4')
            cout << "NO\n";
        else
        {
            bool flag = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i].back() == '1' || a[i].back() == '2')
                {
                    if (b[i].back() == '1' || b[i].back() == '2')
                    {
                        flag = 0;
                        break;
                    }
                }
                else
                {
                    if (b[i].back() == '3' || b[i].back() == '4')
                    {
                        flag = 0;
                        break;
                    }
                }
            }

            cout << (flag ? "YES\n" : "NO\n");
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
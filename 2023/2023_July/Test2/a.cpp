// 2023/07/22 01:04:03
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b;
        cin >> a >> b;
        // if (a > b)
        //     swap(b, a);

        // if (a * 2 < b)
        //     cout << a * 2 << '\n';
        // else if (a * 2 == b)
        //     cout << a + b << '\n';
        
        cout << a + b << '\n';
    }

    cout << endl;
    return 0;
}
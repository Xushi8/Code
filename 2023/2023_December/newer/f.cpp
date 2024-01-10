// 2023/12/13 20:05:02
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
    if (n % 10 == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << n % 10 << endl;
        n -= n % 10;
    }

    while (1)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }

        n -= x;
        cout << n % 10 << endl;
        n -= n % 10;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
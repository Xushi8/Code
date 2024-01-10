// 2023/11/04 20:06:49
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
using ull = unsigned long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

ull qmi(ull a, ull n)
{
    ull b = 1;
    while(n != 0)
    {
        if (n & 1)
            b *= a;
        a *= a;
        n /= 2;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ull n;
    cin >> n;
    ull i = 1;
    ull now = qmi(i, i);
    while (now < n)
    {
        i++;
        now = qmi(i, i);
    }

    if (now == n)
        cout << i;
    else
        cout << -1;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
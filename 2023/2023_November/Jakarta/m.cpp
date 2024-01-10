// 2023/12/03 12:53:34
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
    ll sum = 0;
    for (int& x : a)
    {
        cin >> x;
        sum += x;
    }

    ll maxn = *max_element(a.begin(), a.end());
    ll tmp = sum - maxn;
    if (maxn / 2 > tmp)
    {
        cout << tmp << endl;
        return 0;
    }

    cout << sum / 3 << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
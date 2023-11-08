// 2023/11/08 16:18:33
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

    int n, b;
    cin >> n >> b;
    vector<int> s;
    while (n)
    {
        s.push_back(n % b);
        n /= b;
    }

    vector<int> tmp = s;
    vector<int> rev(tmp.rbegin(), tmp.rend());
    if (tmp == rev)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    for (size_t i = 0; i < rev.size(); i++)
    {
        if (i != 0) cout << ' ';
        cout << rev[i];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
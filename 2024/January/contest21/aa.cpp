// 2024/01/18 09:03:09
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

    int q;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<>> que;
    ll adds = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll x;
            cin >> x;
            que.emplace(x - adds);
        }
        else if (op == 2)
        {
            ll x;
            cin >> x;
            adds += x;
        }
        else
        {
            ll x = que.top();
            que.pop();
            cout << x + adds << '\n';
        }
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
// 2023/08/12 20:26:43
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
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }

    vector<char> alpha(m, 0);
    for (int i = 0; i < n; i++)
    {
        if (alpha[arr[i]] == 0)
            alpha[arr[i]] = s[i];
        else
            swap(alpha[arr[i]], s[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (alpha[arr[i]] != 0)
        {
            s[i] = alpha[arr[i]];
            alpha[arr[i]] = 0;
        }
    }

    cout << s << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
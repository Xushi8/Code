// 2023/09/30 20:09:24
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[tot] - i << '\n';
        if (arr[tot] == i)
            tot++;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
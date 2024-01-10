// 2023/09/30 20:14:57
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

constexpr int INF = 0x3f3f3f3f;
int ans = INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> arr(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            cin >> arr[i][j];
        }
    }

    sort(arr.begin(), arr.end());

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
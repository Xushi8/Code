// 2023/11/25 15:30:01
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

int arr[N];

int solve()
{
    int x;
    cin >> x;
    return arr[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < N; i++)
    {
        if (i % 3 == 0)
        {
            arr[i]++;
        }

        arr[i] += arr[i - 1];
    }

    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": " << solve() << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
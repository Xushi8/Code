// 2023/10/14 14:26:39
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, m;
    cin >> n >> k >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
    }

    for (int i = 0; i < n * k; i++)
    {
        int x;
        cin >> x;
        cout << (++arr[x]) << " \n"[i == n * k - 1];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
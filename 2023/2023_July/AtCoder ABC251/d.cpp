// 2023/07/05 19:41:47
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
    
    int W;
    cin >> W;
    cout << 298 << '\n';
    for (int i = 1; i <= 99; i++)
    {
        cout << i << ' ';
    }
    for (int i = 1; i <= 99; i++)
    {
        cout << i * 100 << ' ';
    }
    for (int i = 1; i <= 100; i++)
    {
        cout << i * 10000 << ' ';
    }

    cout << endl;
    return 0;
}
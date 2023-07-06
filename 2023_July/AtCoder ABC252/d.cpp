// 2023/07/06 20:44:51
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int arr[N];
ll sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }

    ll ans = 0;
    sum[0] = arr[0];
    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 1; i < N - 1; i++)
    {
        ans += arr[i] * sum[i - 1] * (sum[N - 1] - sum[i]);
    }

    cout << ans << '\n';


    cout << endl;
    return 0;
}
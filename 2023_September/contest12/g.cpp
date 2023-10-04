// 2023/10/04 09:57:21
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
    
    int n;
    cin >> n;
    vector<int> arr(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans = max(ans, arr[i] - i);
    }

    cout << ans << '\n';


    
    // for (int x : arr)
    // {
    //     cout << x << ' ';
    // }

    // int arr[41];
    // for (int i = 1; i <= 40; i++)
    // {
    //     arr[i] = i;
    // }

    // for (int i = 1; i <= 40 - 1; i++)
    // {
    //     if(rand() & 1)
    //         swap(arr[i], arr[i + 1]);
    // }

    // for (int i = 1; i <= 40; i++)
    // {
    //     cout << arr[i] << ' ';
    // }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
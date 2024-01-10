// 2023/10/31 20:57:30
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

    int n;
    cin >> n;
    vector<pii> arr(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = {x, s[i] - '0'};
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += arr[i].second == 1;
    }
    ans = max(ans, tmp);
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && arr[i].first == arr[j].first)
        {
            if (arr[j].second == 1)
                tmp--;
            else
                tmp++;
            j++;
        }
        i = j - 1;

        ans = max(ans, tmp);
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
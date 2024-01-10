// 2023/08/05 09:08:47
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int index = (int)(upper_bound(arr.begin(), arr.end(), 0) - arr.begin());
    int sum = 0;
    for (int i = index; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum & 1)
        cout << sum << '\n';
    else
    {
        int positive = -1;
        int negative = 1;
        for (int i = index; i < n; i++)
        {
            if (arr[i] & 1)
            {
                positive = arr[i];
                break;
            }
        }

        for (int i = index - 1; i >= 0; i--)
        {
            if (arr[i] & 1)
            {
                negative = arr[i];
                break;
            }
        }

        if (positive < 0)
        {
            cout << sum + negative << '\n';
        }
        else if(negative > 0)
        {
            cout << sum - positive << '\n';
        }
        else
        {
            cout << sum - min(positive, -negative) << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
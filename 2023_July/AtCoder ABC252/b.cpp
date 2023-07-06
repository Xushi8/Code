// 2023/07/06 20:02:40
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dislike(k);
    for (int i = 0; i < k; i++)
        cin >> dislike[i];

    int maxn = *max_element(arr.begin(), arr.end());

    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == maxn && count(dislike.begin(), dislike.end(), i + 1))
        {
            flag = 1;
            cout << "Yes\n";
            break;
        }
    }

    if (!flag)
    {
        cout << "No\n";
    }

    cout << endl;
    return 0;
}
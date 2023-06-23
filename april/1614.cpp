// 2023/04/27 16:34:47
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int ans = INT32_MAX;
    for (int i = k; i <= n; i++)
    {
        ans = min(ans, arr[i] - arr[i - k]);
    }
    cout << ans;

    cout << endl;
    return 0;
}
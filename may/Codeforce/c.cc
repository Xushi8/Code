// 2023/05/06 22:35:10
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<pair<int, string>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end());
        int ans1 = INT32_MAX;
        int ans2 = INT32_MAX;
        int a = 0, b = 0;
        int c = -1, d = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].second == "00")
                continue;
            if (arr[i].second == "11")
            {
                ans2 = min(ans2, arr[i].first);
            }
            else if (arr[i].second == "10")
            {
                if (a == 0)
                {
                    a = 1;
                    c = i;
                }
            }
            else if (arr[i].second == "01")
            {
                if (b == 0)
                {
                    b = 1;
                    d = i;
                }
            }

            if (a == 1 && a == b)
            {
                ans1 = min(ans1, arr[c].first + arr[d].first);
            }
        }
        if (ans1 == INT32_MAX && ans2 == INT32_MAX)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << min(ans1, ans2) << '\n';
        }
    }

    cout << endl;
    return 0;
}
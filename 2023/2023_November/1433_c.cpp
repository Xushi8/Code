#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (count(arr.begin(), arr.end(), arr.front()) == n)
    {
        cout << -1 << '\n';
    }
    else
    {
        int maxn = *max_element(arr.begin(), arr.end());
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] == maxn && arr[i - 1] + arr[i + 1] != maxn * 2)
            {
                cout << i + 1 << '\n';
                return;
            }
        }

        if (arr[0] == maxn && arr[1] != maxn)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << n << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}

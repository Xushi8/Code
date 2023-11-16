#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), sum(n + 1);
    arr[0] = sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] ^ arr[i];
    }

    if (sum[n] != 0)
    {
        cout << "YES\n2\n";
        cout << "1 1 2 " << n << '\n';
        return;
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    queue<pii> que;
    que.emplace(1, ++cnt);
    for (int i = cnt + 1; i <= n; i++)
    {
        int a = sum[i] ^ sum[cnt];
        int b = sum[n] ^ sum[i];
        int c = sum[n];
        if (a != b && b != c && c != a)
        {
            que.emplace(cnt + 1, i);
            que.emplace(i + 1, n);
            break;
        }
    }

    if (que.size() == 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n3\n";
        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();
            cout << x << ' ' << y << '\n';
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

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/06/06 23:22:00
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = (ll)(1e9 + 7);
const int N = 100005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 999;
    

    vector<vector<int>> arr(n, vector<int>(n, 99));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
    }

    cout << endl;
    return 0;
}
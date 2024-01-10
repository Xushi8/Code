// 2023/08/14 08:41:27
#include <iostream>
#include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
#include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
const int N = 10;

string arr[N];
bool used[N][N];
int ans;
int n, k;

bool check(int row, int col)
{
    if (arr[row][col] != '#' || used[row][col] == 1)
        return false;

    for (int i = 0; i < row; i++)
    {
        if (used[i][col] == 1)
            return false;
    }

    return true;
}

void dfs(int row, int now)
{
    if (now == k)
    {
        ans++;
        return;
    }
    if (row == n)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (check(row, i))
        {
            used[row][i] = 1;
            dfs(row + 1, now + 1);
            used[row][i] = 0;
        }
    }

    dfs(row + 1, now);
}

int main()
{
    while (cin >> n >> k && (n != -1 || k != -1))
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        dfs(0, 0);
        cout << ans << '\n';
        ans = 0;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
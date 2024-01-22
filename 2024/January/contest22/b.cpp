// // 2024/01/22 11:20:27
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// constexpr int N = 4;

// int arr[N][N];
// int ex, ey;
// ll ans = 0;

// bool check(int op)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             if (arr[i][j] == op)
//             {
//                 if (i + 1 < 4 && arr[i + 1][j] == op && i + 2 < 4 && arr[i + 2][j] == op)
//                 {
//                     return true;
//                 }
//                 if (j + 1 < 4 && arr[i][j + 1] == op && j + 2 < 4 && arr[i][j + 2] == op)
//                 {
//                     return true;
//                 }
//                 if (i + 1 < 4 && j + 1 < 4 && arr[i + 1][j + 1] == op && i + 2 < 4 && j + 2 < 4 && arr[i + 2][j + 2] == op)
//                 {
//                     return true;
//                 }
//                 if (i + 1 < 4 && j - 1 < 4 && arr[i + 1][j - 1] == op && i + 2 < 4 && j - 2 < 4 && arr[i + 2][j - 2] == op)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }

//     return false;
// }

// void dfs(int y, int op, int deep)
// {
//     int x = -1;
//     for (int i = 0; i < 4; i++)
//     {
//         if (arr[i][y] == -1)
//         {
//             arr[i][y] = op;
//             x = i;
//             break;
//         }
//     }
//     if (x == -1)
//     {
//         return;
//     }

//     if (deep >= 4)
//     {
//         if (check(0))
//         {
//             arr[x][y] = -1;
//             return;
//         }

//         if (check(1))
//         {
//             if (x == ex && y == ey)
//             {
//                 ans++;
//             }
//             arr[x][y] = -1;
//             return;
//         }
//     }

//     for (int i = 0; i < 4; i++)
//     {
//         dfs(i, !op, deep + 1);
//     }

//     arr[x][y] = -1;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     memset(arr, -1, sizeof(arr));
//     int y;
//     cin >> y;
//     y--;
//     cin >> ex >> ey;
//     ex--;
//     ey--;
//     dfs(y, 0, 0);
//     cout << ans << endl;

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

// 2024/01/22 13:10:13
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
constexpr int N = 4;
array<array<int, 4>, 4> arr;
// set<array<array<int, 4>, 4>> st;
vector<array<array<int, 4>, 4>> ans;
int ex, ey;

bool check(int op)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == op && i + 1 < N && arr[i + 1][j] == op && i + 2 < N && arr[i + 2][j] == op)
            {
                return true;
            }
            if (arr[i][j] == op && j + 1 < N && arr[i][j + 1] == op && j + 2 < N && arr[i][j + 2] == op)
            {
                return true;
            }
            if (arr[i][j] == op && i - 1 >= 0 && arr[i - 1][j] == op && i - 2 >= 0 && arr[i - 2][j] == op)
            {
                return true;
            }
            if (arr[i][j] == op && j - 1 >= 0 && arr[i][j - 1] == op && j - 2 >= 0 && arr[i][j - 2] == op)
            {
                return true;
            }
            if (arr[i][j] == op && i + 1 < N && j + 1 < N && arr[i + 1][j + 1] == N && i + 2 < N && j + 2 < N && arr[i + 2][j + 2] == op)
            {
                return true;
            }
            if (arr[i][j] == op && i + 1 < N && j - 1 >= 0 && arr[i + 1][j - 1] == op && i + 2 < N && j - 2 >= 0 && arr[i + 2][j - 2] == op)
            {
                return true;
            }
            if (arr[i][j] == op && i - 1 >= 0 && j + 1 < N && arr[i - 1][j + 1] == op && i - 2 >= 0 && j + 2 < N && arr[i - 2][j + 2] == op)
            {
                return true;
            }
            if (arr[i][j] == op && i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == op && i - 2 >= 0 && j - 2 >= 0 && arr[i - 2][j - 2] == op)
            {
                return true;
            }
        }
    }

    return false;
}

void dfs(int y, int op, int deep)
{
    int x = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i][y] == -1)
        {
            x = i;
            arr[x][y] = op;
            break;
        }
    }
    if (x == -1)
    {
        return;
    }

    if (deep % 2 == 0 && check(0))
    {
        arr[x][y] = -1;
        return;
    }
    if (deep % 2 == 1 && check(1))
    {
        if (x == ex && y == ey)
        {
            // st.emplace(arr);
            ans.emplace_back(arr);
        }
        arr[x][y] = -1;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        dfs(i, !op, deep + 1);
    }
    arr[x][y] = -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = -1;
        }
    }

    int y;
    cin >> y;
    y--;
    cin >> ex >> ey;
    ex--;
    ey--;
    dfs(y, 0, 0);
    // cout << st.size() << endl;
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
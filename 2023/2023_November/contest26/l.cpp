// 2023/11/25 15:40:19
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

#define loop(x) for (int x = 0; x < 3; x++)

int ans[10][10][10][10];

void func(int op, int& x, int& y)
{
    if (op == 0)
    {
        x++;
        y++;
    }
    else if (op == 1)
    {
        x += 3;
    }
    else
    {
        y += 3;
    }
}

const char* solve()
{
    array<int, 4> tmp;
    for (int i = 0; i < 4; i++)
    {
        cin >> tmp[i];
    }

    if (*max_element(tmp.begin(), tmp.end()) > 9 || ans[tmp[0]][tmp[1]][tmp[2]][tmp[3]] == 0)
    {
        return "Wrong Scoreboard";
    }
    else if (ans[tmp[0]][tmp[1]][tmp[2]][tmp[3]] == 1)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    loop(a) loop(b) loop(c) loop(d) loop(e) loop(f)
    {
        array<int, 4> tmp = {0, 0, 0, 0};
        func(a, tmp[0], tmp[1]);
        func(b, tmp[0], tmp[2]);
        func(c, tmp[0], tmp[3]);
        func(d, tmp[1], tmp[2]);
        func(e, tmp[1], tmp[3]);
        func(f, tmp[2], tmp[3]);

        ans[tmp[0]][tmp[1]][tmp[2]][tmp[3]]++;
    }

    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": " << solve() << '\n';
    }

    // for(int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         for (int k = 0; k < 10; k++) {
    //             for (int l = 0; l < 10; l++) {
    //                 cerr << ans[i][j][k][l] << ' ';
    //             }
    //         }
    //     }
    // }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/08/16 09:32:52
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

int arr[10][10];

struct A
{
    A() {}
    A(int a, int b, int c)
    {
        x = a;
        y = b;
        w = c;
    }
    
    int x, y, w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2)
    {
        cout << "0 0 0\n";
    }
    else
    {
        if (x1 == x2 || y1 == y2)
            cout << 1 << ' ';
        else
            cout << 2 << ' ';

        memset(arr, -1, sizeof(arr));

        queue<A> que;
        que.emplace(x1, y1, 0);
        arr[x1][x2] = 0;
        while (!que.empty())
        {
            A a = que.front(); que.pop();
            A tmp = a;
            while (tmp.x + 1 <= 8 && tmp.y + 1 <= 8)
            {
                tmp.x++; tmp.y++;
                if (arr[tmp.x][tmp.y] != -1)
                    continue;

                arr[tmp.x][tmp.y] = a.w + 1;
                que.emplace(tmp.x, tmp.y, a.w + 1);
            }

            tmp = a;
            while (tmp.x + 1 <= 8 && tmp.y - 1 >= 1)
            {
                tmp.x++; tmp.y--;
                if (arr[tmp.x][tmp.y] != -1)
                    continue;

                arr[tmp.x][tmp.y] = a.w + 1;
                que.emplace(tmp.x, tmp.y, a.w + 1);
            }

            tmp = a;
            while (tmp.x - 1 >= 1 && tmp.y + 1 <= 8)
            {
                tmp.x--; tmp.y++;
                if (arr[tmp.x][tmp.y] != -1)
                    continue;

                arr[tmp.x][tmp.y] = a.w + 1;
                que.emplace(tmp.x, tmp.y, a.w + 1);
            }

            tmp = a;
            while (tmp.x - 1 >= 1 && tmp.y - 1 >= 1)
            {
                tmp.x--; tmp.y--;
                if (arr[tmp.x][tmp.y] != -1)
                    continue;

                arr[tmp.x][tmp.y] = a.w + 1;
                que.emplace(tmp.x, tmp.y, a.w + 1);
            }
        }

        if (arr[x2][y2] == -1)
            cout << 0 << ' ';
        else
            cout << arr[x2][y2] << ' ';



        int a = abs(x1 - x2);
        int b = abs(y1 - y2);
        int minn = min(a, b);
        int maxx = max(a, b) - minn;
        cout << minn + maxx << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
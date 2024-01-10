// 2023/11/08 11:48:44
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
constexpr int N = 25;

struct A
{
    int len, ed = 0;
};

queue<int> que[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<A> arr(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i].len;
    }

    int tot = 0;
    for (int now = 480; now < 1020; now++)
    {
        // 送客
        for (int i = 0; i < n; i++)
        {
            if (!que[i].empty())
            {
                int j = que[i].front();
                if (arr[j].ed == now)
                {
                    que[i].pop();
                }
            }
        }

        // 入队
        for (int j = 1; j <= m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (que[i].size() < j)
                {
                    if (tot < k)
                    {
                        que[i].emplace(tot++);
                    }
                }
            }
        }

        // 迎客
        for (int i = 0; i < n; i++)
        {
            if (!que[i].empty())
            {
                int j = que[i].front();
                if (arr[j].ed == 0)
                {
                    arr[j].ed = now + arr[j].len;
                }
            }
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        x--;
        if(arr[x].ed == 0) {
            cout << "Sorry\n";
        } else {
            int j = arr[x].ed;
            int h = j / 60;
            int m = j % 60;
            cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
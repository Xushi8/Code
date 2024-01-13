// 2024/01/12 15:12:39
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

int row[N], col[N];
int cntx[N], cnty[N];
int n, q;

void row_add(int i, int x)
{
    while (i <= n)
    {
        row[i] += x;
        i += i & -i;
    }
}

int row_sum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += row[i];
        i -= i & -i;
    }
    return res;
}

void col_add(int i, int x)
{
    while (i <= n)
    {
        col[i] += x;
        i += i & -i;
    }
}

int col_sum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += col[i];
        i -= i & -i;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            cntx[x]++;
            cnty[y]++;
            if (cntx[x] == 1)
                row_add(x, 1);
            if (cnty[y] == 1)
                col_add(y, 1);
        }
        else if (op == 2)
        {
            int x, y;
            cin >> x >> y;
            cntx[x]--;
            cnty[y]--;
            if (cntx[x] == 0)
                row_add(x, -1);
            if (cnty[y] == 0)
                col_add(y, -1);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << ((x2 - x1 + 1 == row_sum(x2) - row_sum(x1 - 1) || y2 - y1 + 1 == col_sum(y2) - col_sum(y1 - 1)) ? "Yes\n" : "No\n");
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
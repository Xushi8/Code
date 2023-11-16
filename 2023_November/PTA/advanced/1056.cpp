// 2023/11/15 13:39:44
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
constexpr int N = 10005;

int score[N];
int rk[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int tot = a.size() / k + (a.size() % k != 0);
    while (a.size() != 1)
    {
        int j = 0;
        int id, maxn;
        vector<int> b;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (j == 0)
            {
                maxn = score[a[i]];
                id = a[i];
            }
            else
            {
                if (maxn < score[a[i]])
                {
                    rk[id] = tot + 1;
                    maxn = score[a[i]];
                    id = a[i];
                }
                else
                {
                    rk[a[i]] = tot + 1;
                }
            }
            j++;
            if (j == k || i + 1 == a.size())
            {
                j = 0;
                b.emplace_back(id);
            }
        }

        a = move(b);
        tot = a.size() / k + (a.size() % k != 0);
    }

    rk[a[0]] = 1;

    for (int i = 0; i < n; i++)
    {
        cout << rk[i] << " \n"[i + 1 == n];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
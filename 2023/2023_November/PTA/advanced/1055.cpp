// 2023/11/15 12:02:05
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

struct A
{
    char name[10];
    int age, val;
};

bool cmp(A x, A y)
{
    if (x.val != y.val)
    {
        return x.val > y.val;
    }
    else if (x.age != y.age)
    {
        return x.age < y.age;
    }
    else
    {
        return strcmp(x.name, y.name) < 0;
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<A> a(n);
    for (int i = 0; i < n; i++)
    {
        // cin >> a[i].name >> a[i].age >> a[i].val;
        scanf("%s%d%d", a[i].name, &a[i].age, &a[i].val);
    }

    sort(a.begin(), a.end(), cmp);
    int Case = 0;

    while (q--)
    {
        int cnt, l, r;
        // cin >> cnt >> l >> r;
        scanf("%d%d%d", &cnt, &l, &r);
        cout << "Case #" << ++Case << ':' << '\n';
        int k = 0;
        for (auto [x, y, z] : a)
        {
            if(k == cnt) {
                break;
            }
            if (l <= y && y <= r)
            {
                k++;
                cout << x << ' ' << y << ' ' << z << '\n';
            }
        }

        if(k == 0) {
            cout << "None" << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
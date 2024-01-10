// 2023/11/07 18:25:23
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
    string name;
    int a, b, c;
};

bool operator<(A x, A y)
{
    if (x.a != y.a)
        return x.a < y.a;
    if (x.b != y.b)
        return x.b < y.b;
    return x.c < y.c;
}

bool operator>(A x, A y)
{
    if (x.a != y.a)
        return x.a > y.a;
    if (x.b != y.b)
        return x.b > y.b;
    return x.c > y.c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<A> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        string name;
        int h, m, s;
        char ch;
        cin >> name >> h >> ch >> m >> ch >> s;
        a[i] = {name, h, m, s};
        cin >> h >> ch >> m >> ch >> s;
        b[i] = {name, h, m, s};
    }

    sort(a.begin(), a.end(), less<>());
    sort(b.begin(), b.end(), greater<>());

    cout << a.front().name << ' ' << b.front().name;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
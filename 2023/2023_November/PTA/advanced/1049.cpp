// 2023/11/14 22:12:05
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

int a[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int b[] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};

int func(int n)
{
    if(n == 0) {
        return 0;
    }
    int i;
    for (i = 0; n / a[i] > 9; i++) {}
    int j = n / a[i];
    if(j == 1) {
        return b[i] + 1 + func(n - a[i]) + (n - a[i]);
    } else {
        return b[i] * j + a[i] + func(n - j * a[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << func(n) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
// 2023/11/08 10:19:27
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a[3];
    double ans = 1.0;
    for (int i = 0; i < 3; i++) {
        cin >> a[0] >> a[1] >> a[2];
        double* p = max_element(a, a + 3);
        if(p - a == 0) {
            cout << 'W';
        } else if(p - a == 1) {
            cout << 'T';
        } else {
            cout << 'L';
        }
        cout << ' ';

        ans *= *p;
    }

    cout << setprecision(2) << fixed;
    cout << ans * 1.3 - 2;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
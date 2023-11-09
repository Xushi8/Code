// 2023/11/09 14:26:44
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

void print(int a)
{
    if (a >= 10)
        cout << char('A' + a - 10);
    else
        cout << a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << '#';
    for (int i = 0; i < 3; i++)
    {
        int x;
        cin >> x;
        print(x / 13);
        print(x % 13);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
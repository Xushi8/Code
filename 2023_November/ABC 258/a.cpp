// 2023/11/05 15:39:38
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
    // ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a = 21;
    int b = 0;
    while(n >= 60){
        n -= 60;
        a++;
    }
    b += n;
    a %= 24;
    printf("%02d:%02d", a, b);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
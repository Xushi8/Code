// 2023/10/03 17:50:20
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
#include <format>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // cout << format("{:.8f}\n", 3.1415);

    // array<int, 5> tmp = { 1,1,2,8,4 };

    cout << 0b10011 << endl;
    cout << bitset<10>(47) << endl;
    cout << bitset<20>(0x4af) << endl;
    cout << 0x4af << endl;
    cout << 0344 << endl;
    cout << bitset<32>(INT32_MAX) << endl;
    cout << bitset<32>(UINT32_MAX) << endl;

    cout << format("{:.15f}\n", 3.1415926);
    cout << format("{} {}\n", 5676, 998390803810832);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
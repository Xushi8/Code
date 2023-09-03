// 2023/09/03 14:45:25
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int ans = 0;
    ans += stoi(s);
    char ch;
    ch = s.front();
    s[0] = s[1];
    s[1] = s[2];
    s[2] = ch;
    ans += stoi(s);
    ch = s.front();
    s[0] = s[1];
    s[1] = s[2];
    s[2] = ch;
    ans += stoi(s);

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
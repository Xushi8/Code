// 2023/11/09 13:34:27
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

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    map<int, int> s1;
    for (char& ch : s)
    {
        ch -= '0';
        s1[ch]++;
    }

    int jinwei[30] = {0};
    for (size_t i = 0; i < s.size(); i++)
    {
        s[i] = s[i] * 2 + jinwei[i];
        if (s[i] > 9)
        {
            s[i] -= 10;
            jinwei[i + 1]++;
        }
    }

    if (jinwei[s.size()] != 0)
    {
        s.push_back(jinwei[s.size()]);
    }

    reverse(s.begin(), s.end());
    map<int, int> s2;
    for (char& ch : s)
    {
        s2[ch]++;
        ch += '0';
    }

    cout << (s1 == s2 ? "Yes\n" : "No\n");
    cout << s;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
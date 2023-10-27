// 2023/10/27 10:09:10
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

bool check(string s)
{
    for (size_t i = 1; i < s.size(); i++)
    {
        if (islower(s[i]))
            return false;
    }
    return true;
}

bool check1(string s)
{
    size_t cnt = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isupper(s[i]))
            cnt++;
    }
    return cnt == s.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    if ((islower(s[0]) && check(s)) || check1(s))
    {
        for (auto& ch : s)
        {
            if (islower(ch))
                ch = toupper(ch);
            else
                ch = tolower(ch);
        }
    }

    cout << s << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
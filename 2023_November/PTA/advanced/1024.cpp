// 2023/11/09 13:42:09
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

void add(string& s)
{
    vector<int> jinwei(s.size() + 1, 0);
    string a(s.rbegin(), s.rend());
    for (size_t i = 0; i < s.size(); i++)
    {
        s[i] += a[i] + jinwei[i];
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
}

bool check(const string& s)
{
    return s == string(s.rbegin(), s.rend());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int k;
    cin >> s >> k;
    for (char& ch : s)
    {
        ch -= '0';
    }
    reverse(s.begin(), s.end());

    int cnt = 0;
    while (1)
    {
        if (check(s))
        {
            break;
        }

        add(s);
        cnt++;

        if (cnt == k)
        {
            break;
        }
    }

    for (char& ch : s)
    {
        ch += '0';
    }
    reverse(s.begin(), s.end());
    cout << s << '\n'
         << cnt;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
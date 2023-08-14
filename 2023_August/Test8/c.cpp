// 2023/08/12 09:32:01
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int nex[N];

void get_next(const string& s)
{
    nex[0] = -1;
    int i = 0, j = -1;
    while (i < (int)s.size())
    {
        if (j == -1 || s[i] == s[j])
        {
            i++; j++;
            nex[i] = j;
        }
        else
        {
            j = nex[j];
        }
    }
}

int kmp(const string& a, const string& b)
{
    int i = 0, j = 0;
    get_next(b);
    while (i < (int)a.size())
    {
        if (j == - 1 || a[i] == b[j])
        {
            i++; j++;
        }
        else if (j > 0)
        {
            j = nex[j];
        }
        else
        {
            i++;
        }

        if (j == (int)b.size())
            return i - j;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    get_next(s);
    vector<int> arr;
    int t = (int)s.size() - 1;
    while (t != -1)
    {
        if (s[t] == s.back())
            arr.emplace_back(t + 1);
        t = nex[t];
    }

    reverse(arr.begin(), arr.end());
    arr.pop_back();
    reverse(arr.begin(), arr.end());
    bool flag = 1;
    int index = -1;
    for (int x : arr)
    {
        string target = s.substr(0, x);
        // size_t tmp = s.substr(1).find(target);
        // tmp++;
        int tmp = kmp(s.substr(1), target);
        tmp++;
        if (tmp != (int)s.size() - x)
        {
            index = x;
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        cout << "Just a legend\n";
    }
    else
    {
        cout << s.substr(0, index) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
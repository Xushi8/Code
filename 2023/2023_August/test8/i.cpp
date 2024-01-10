// 2023/08/11 16:02:30
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
            i++;
            j++;
            nex[i] = j;
        }
        else
        {
            j = nex[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    while (cin >> s)
    {
        get_next(s);
        vector<int> arr;
        int t = (int)s.size() - 1;
        while (t != -1)
        {
            if (s[t] == s.back())
            {
                arr.emplace_back(t + 1);
            }
            t = nex[t];
        }
        vector<int> tmp = { arr.rbegin(), arr.rend() };
        tmp.pop_back();
        ull ans = 0;
        ans += s.size();
        for (int x : tmp)
        {
            int T = (int)s.size() - x;
            ans += s.size() * 2 / T;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
// 2023/07/26 09:02:20
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string ans = "314159265358979323846264338327";
    int tt;
    cin >> tt;
    while (tt--)
    {
        string str;
        cin >> str;
        int cnt = 0;
        bool flag = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] == ans[i] && !flag) 
                cnt++;
            else
                flag = 1;
        }

        cout << cnt << '\n';
    }

    cout << endl;
    return 0;
}
// 2023/10/12 11:34:44
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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr;
    for (size_t i = 0; i < s.size(); )
    {
        int cnt = 1;
        for (size_t j = i + 1; j < s.size(); j++)
        {
            if (s[j] == s[i])
                cnt++;
            else
                break;
        }
        arr.emplace_back(cnt);
        i += cnt;
    }

    size_t index = arr.size();
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 2)
        {
            index = i;
            break;
        }
    }

    int ans = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        ans++;
        if (arr[i] == 1)
        {
            for (size_t j = index; j < arr.size(); j++)
            {
                if (arr[j] >= 2)
                {
                    index = j;
                    break;
                }
            }
            if (i < index && index < arr.size() && arr[index] >= 2)
                arr[index]--;
            else
                i++;
        }
        else
            index++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
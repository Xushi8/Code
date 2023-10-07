// 2023/10/07 21:02:40
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

int arr[N];

bool cmp(pii a, pii b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (size_t j = i + 1; j < s.size(); j++)
        {
            if (s[j] == 'o')
                arr[i]++;
            else
                arr[j]++;
        }
    }

    vector<pii> ans;
    for (int i = 0; i < n; i++)
    {
        ans.emplace_back(arr[i], i);
    }

    sort(ans.begin(), ans.end(), cmp);
    for (auto [x, y] : ans)
    {
        cout << y + 1 << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
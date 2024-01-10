// 2023/11/01 16:33:10
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
    int n;
    cin >> s >> n;
    vector<pair<char, int>> arr;
    map<int, set<pair<char, int>>, greater<>> mp;
    
    for (size_t i = 0; i < s.size(); i++)
    {
        size_t j = i;
        while (j < s.size() && s[j] == s[i])
        {
            j++;
        }
        pair<char, int> tmp = {s[i], j - i};
        mp[j - i].insert(tmp);
        i = j - 1;
    }

    while (!mp.empty())
    {
        if (mp.begin()->first < n)
        {
            break;
        }

        auto to_be_erase = (mp.begin()->second.begin());
        char ch = to_be_erase->first;
        mp.begin()->second.erase(to_be_erase);
        int i = find(arr.begin(), arr.end(), *to_be_erase) - arr.begin();
        int j;
        j = i + 1;
        while (j < arr.size() && arr[j].first == ch)
        {
            auto& tmp = mp[arr[j].second];
            tmp.erase(tmp.find(arr[j]));
            if (tmp.empty())
            {
                mp.erase(arr[j].second);
            }

            arr[i].second += arr[j].second;
            arr.erase(arr.begin() + j);
        }

        j = i - 1;
        while (j >= 0 && arr[j].first == ch)
        {
            auto& tmp = mp[arr[j].second];
            tmp.erase(tmp.find(arr[j]));
            if (tmp.empty())
            {
                mp.erase(arr[j].second);
            }

            arr[i].second += arr[j].second;
            arr.erase(arr.begin() + j);
            i--; j--;
        }
    }

    cout << (mp.empty() ? "Yes\n" : "No\n");


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/11/14 21:13:40
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

    int k;
    cin >> k;
    vector<int> order(54);
    for (int i = 0; i < 54; i++)
    {
        cin >> order[i];
        order[i]--;
    }

    map<int, char> mp;
    mp.emplace(0, 'S');
    mp.emplace(1, 'H');
    mp.emplace(2, 'C');
    mp.emplace(3, 'D');
    mp.emplace(4, 'J');

    vector<string> arr(54);
    for (int i = 0; i < 54; i++)
    {
        int a = i / 13;
        int b = i % 13;
        arr[i] = mp[a] + to_string(b + 1);
    }

    auto func = [&]() -> void
    {
        vector<string> nex(54);
        for (int i = 0; i < 54; i++)
        {
            nex[order[i]] = arr[i];
        }

        arr = move(nex);
    };

    while (k--)
    {
        func();
    }

    for (auto& x : arr)
    {
        if (x != arr.front())
        {
            cout << ' ';
        }
        cout << x;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
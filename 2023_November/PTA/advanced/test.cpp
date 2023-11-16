// 2023/11/07 17:51:23
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
#include <memory>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // int y = 487;
    // printf("%02d:%02d\n", y / 60, y % 60);
    // map<int, int> mp;
    // mp[5] = 20;
    // for(auto& [u, v] : mp) {
    //     v = 1000;
    // }

    // for(auto [u, v] : mp) {
    //     cout << v;
    // }

    // ofstream ofs("in.txt");
    // srand((unsigned)time(nullptr));
    // int n = 100000;
    // ofs << n << '\n';
    // for (int i = 0; i < n;i ++) {
    //     int x = rand();
    //     x %= 1000000000;
    //     ofs << x << '\n';
    // }

    // constexpr int n = 1000;
    // auto arr = make_unique<int[]>(n);
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = -1;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << '\n';
    // }

    ofstream ofs("in.txt");
    int n;
    n = 100000;
    ofs << n << '\n';
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 3;
        if (x == 0)
        {
            ofs << "Pop\n";
        }
        else if (x == 1)
        {
            ofs << "PeekMedian\n";
        }
        else
        {
            ofs << "Push " << rand() % 100 << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/10/11 14:18:14
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
    
    int arr[20] = { 0 };
    for (int i = 0; i < 20; i++)
    {
        for (int j = i; j < 20; j++)
        {
            arr[i][j]++;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = i; j < 20; j++)
        {
            cout << arr[i][j] << " \n"[j == 19];
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/11/01 13:57:54
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

    int n;
    cin >> n;
    int arr[10] = {0};
    int minn = 1e9;
    for (int i = 1; i <= 9; i++)
    {
        cin >> arr[i];
        minn = min(minn, arr[i]);
    }

    int now = n;
    for (int i = 9; i >= 1; i--)
    {
        int tmp = now;
        for (int j = 1; j * arr[i] <= now; j++)
        {
            if (now / minn == (now - j * arr[i]) / minn + j)
            {
            }
            else
            {
                break;
            }

            cout << i;
            tmp -= arr[i];
        }
        now = tmp;
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/07/21 17:14:02
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
    
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        if (k == 1)
        {
            cout << "Alice\n";
            continue;
        }

        int sum = 0;
        if (n & 1)
        {
            sum ^= arr[1] - 1;
            for (size_t i = 2; i <= n - 1; i += 2)
            {
                sum ^= (arr[i + 1] - arr[i] - 1);
            }

            if (sum == 0)
            {
                if (k == 2)
                    cout << "Bob\n";
                else
                    cout << "Alice\n";
            }
            else
            {
                if (k == 2)
                    cout << "Alice\n";
                else
                    cout << "Bob\n";
            }
        }
        else
        {
            for (size_t i = 1; i <= n - 1; i += 2)
            {
                sum ^= (arr[i + 1] - arr[i] - 1);
            }
            if (sum == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }

    }

    cout << endl;
    return 0;
}
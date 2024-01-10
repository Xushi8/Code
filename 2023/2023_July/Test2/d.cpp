// 2023/07/22 10:05:46
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
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    size_t max_index = arr.end() - arr.begin();
    bool flag = 0;
    while (1)
    {
        // max_index = max_element(arr.begin(), arr.begin() + max_index) - arr.begin();

        if (max_index == arr.end() - arr.begin())
        {
            int maxn = arr.back();
            for (int i = arr.size() - 2; i >= -1; i--)
            {

                if (i == -1)
                {
                    max_index = 0;
                    break;
                }

                if (arr[i] != maxn)
                {
                    max_index = i + 1;
                    break;
                }
            }
        }
        else
        {
            int maxn = arr[max_index - 1];
            for (int i = max_index - 2; i >= -1; i--)
            {

                if (i == -1)
                {
                    max_index = 0;
                    break;
                }
                
                if (arr[i] != maxn)
                {
                    max_index = i + 1;
                    break;
                }
            }
        }

        size_t m = arr.size() - max_index;
        if (m & 1)
        {
            flag = 1;
            break;
        }

        if (max_index == 0)
            break;
    }

    if (flag)
        cout << "Conan\n";
    else
        cout << "Agasa\n";

    cout << endl;
    return 0;
}
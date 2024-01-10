// // 2023/08/09 09:00:14
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;
// int arr[N], tmp[N];
// int ans;

// void merge_sort(int l, int r)
// {
//     if (l < r - 1)
//     {
//         int mid = l + (r - l) / 2;
//         int p = l, q = mid, i = l;
//         merge_sort(l, mid);
//         merge_sort(mid, r);
//         while (p < mid || q < r)
//         {
//             if (q >= r || (p < mid && arr[p] <= arr[q]))
//             {
//                 tmp[i++] = arr[p++];
//             }
//             else
//             {
//                 tmp[i++] = arr[q++];
//                 // ans++;
//                 ans += mid - p;
//             }
//         }
//         for (int i = l; i < r; i++)
//         {
//             arr[i] = tmp[i];
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     merge_sort(0, n);

//     cout << ans << '\n';

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << endl;
//     return 0;
// }


// 2023/08/09 09:27:25
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int arr[N], tmp[N];
ull ans = 0;
void merge_sort(int l, int r)
{
    if (l < r - 1)
    {
        int mid = l + (r - l) / 2;
        int p = l, q = mid, i = l;
        merge_sort(l, mid);
        merge_sort(mid, r);
        while (i < r)
        {
            if (q >= r || (p < mid && arr[p] <= arr[q]))
            {
                tmp[i++] = arr[p++];
            }
            else
            {
                tmp[i++] = arr[q++];
                ans += mid - p;
                // ans++;
            }
        }

        for (i = l; i < r; i++)
        {
            arr[i] = tmp[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(0, n);
    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
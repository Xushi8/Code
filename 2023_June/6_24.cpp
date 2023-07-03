// 2023/06/23 16:39:26
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
#include <list>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 100005;


// void foo()
// {
    
// }

// int bar()
// {
//     for (int i = 0; i < 3; i++)
//     {
//         foo();
//     }

// }

// vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b)
// {
//     vector<vector<int>> ret(a.size(), vector<int>(b[0].size(), 0));
//     for (size_t i = 0; i < a.size(); i++)
//     {
//         for (size_t j = 0; j < b[0].size(); j++)
//         {
//             for (size_t k = 0; k < b.size(); k++)
//             {
//                 ret[i][j] += a[i][k] * b[k][j] % MOD;
//                 ret[i][j] %= MOD;
//             }
//         }
//     }
    
//     return ret;
// }

// vector<vector<int>> pow(vector<vector<int>> a, size_t n)
// {
//     vector<vector<int>> ret(a.size(), vector<int>(a.size(), 0));
//     for (size_t i = 0; i < a.size(); i++)
//     {
//         ret[i][i] = 1;
//     }
//     while (n > 0)
//     {
//         if (n & 1) ret = mul(ret, a);
//         a = mul(a, a);
//         n /= 2;
//     }
//     return ret;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     // bar();

//     ll n, k;
//     cin >> n >> k;
//     vector<vector<int>> arr(n, vector<int>(n));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     arr = pow(arr, k);
//     ll ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ans += arr[i][j];
//         }
//     }

//     cout << ans;

//     cout << endl;
//     return 0;
// }


// 2023/06/23 22:18:20

inline bool func(int n)
{
    return n % 2 != 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << 1 << endl;
    // for (size_t i = 0; i < 1000; i++)
    // {
    //     cout << i << '\n';
    // }

    // for (::std::size_t i = 0; i < 1000; i++)
    // {
    //     cout << i << '\n';
    // }

    list<int> list = { 1, 2, 3, 4 };
    vector<int> datas = { 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // for (auto i : list)
    //     datas.erase(remove(datas.begin(), datas.end(), i), datas.end());

    // datas.erase(remove_if(datas.begin(), datas.end(), func), datas.end());
    // datas.erase(unique(datas.begin(), datas.end()), datas.end());
    // unique(datas.begin(), datas.end());
    // remove_if(datas.begin(), datas.end(), func);
    datas.erase(remove_if(datas.begin(), datas.end(), func), datas.end());


    for (auto i : datas)
        cout << i << '\n';



    cout << endl;
    return 0;
}

// #include <cstdio>

// int main()
// {
//     for (int i = 0; i < 100000; i++)
//     {
//         printf("%d\n", i);
//     }

//     return 0;
// }
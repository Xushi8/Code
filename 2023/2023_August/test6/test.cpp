// 2023/08/03 16:31:20
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
#include <fstream>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;
int arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int N = 10000;
    ofstream ofs("in");
    ofs << N << '\n';
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 2 + 1;
        sum += arr[i];
    }

    for (int i = 0; i < N; i++)
        ofs << arr[i] << ' ';

    ofs << '\n' << sum / 3;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
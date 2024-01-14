// 2024/01/13 21:21:03
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    int arr[200] = {0};
    for (int i = X; i <= N; i++)
    {
        arr[i] = T;
    }

    for (int i = X - 1; i >= 0; i--)
    {
        arr[i] = arr[i + 1] - D;
    }

    cout << arr[M] << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
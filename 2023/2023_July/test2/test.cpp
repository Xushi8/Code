// 2023/07/21 11:17:17
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
    
    vector<int> arr;
    arr.emplace_back(1);
    arr.emplace_back(1);
    arr.emplace_back(1);
    arr.emplace_back(1);

    int index = max_element(arr.begin(), arr.end()) - arr.begin();
    cout << index << '\n';

    cout << endl;
    return 0;
}
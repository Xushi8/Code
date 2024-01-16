// 2024/01/16 11:16:24
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

    int n, A, B;
    cin >> n >> A >> B;
    vector<pii> tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp[i].second;
    }

    vector<int> ba, bb;
    for (int i = 0; i < n; i++)
    {
        if (tmp[i].second == 0) ba.emplace_back(tmp[i].first);
        else bb.emplace_back(tmp[i].first);
    }

    sort(ba.begin(), ba.end());
    sort(bb.begin(), bb.end());

    vector<int> a = ba, b = bb;
    while (A > 0 && B > 0)
    {
        if (A >= a.size())
        {
            A -= a.size();
        }
        else
        {
            
        }
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
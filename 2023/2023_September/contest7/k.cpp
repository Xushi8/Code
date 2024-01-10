// 2023/09/27 16:44:11
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

bool check(int n, int len)
{
    if (len <= 0)
        return false;

    int muls = 1;
    for (int i = 0; i < len; i++)
    {
        muls *= len;
        if (i != len - 1)
        {
            if (muls >= n)
                return true;
        }
        else
        {
            if (muls - 1 >= n)
                return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    int len = k - m;
    if (check(n, len))
    {
        cout << "Yes\n";
        
    }
    else
    {
        cout << "No\n";
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
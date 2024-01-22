// 2024/01/22 09:02:44
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
    set<int> st;
    while(1)
    {
        if (st.count(n) == 1)
        {
            cout << "UNHAPPY" << endl;
            return 0;
        }
        st.emplace(n);
        int tmp = 0;
        while (n)
        {
            tmp += (n % 10) * (n % 10);
            n /= 10;
        }
        if (tmp == 1)
        {
            cout << "HAPPY" << endl;
            return 0;
        }
        n = tmp;
    }


    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
// 2023/11/04 20:10:09
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

int arr[10][10];

bool check()
{
    for (int i = 1; i <= 9; i++)
    {
        set<int> st;
        for (int j = 1; j <= 9; j++)
        {
            st.insert(arr[i][j]);
        }
        if (st.size() != 9)
            return false;
    }

    for (int j = 1; j <= 9; j++)
    {
        set<int> st;
        for (int i = 1; i <= 9; i++)
        {
            st.insert(arr[i][j]);
        }
        if (st.size() != 9)
            return false;
    }

    for (int a = 1; a <= 9; a += 3)
    {
        for (int b = 1; b <= 9; b += 3)
        {
            set<int> st;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    st.insert(arr[a + i][b + j]);
                }
            }
            if (st.size() != 9)
                return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << (check() ? "Yes" : "No");
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
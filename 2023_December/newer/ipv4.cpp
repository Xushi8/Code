// 2023/12/22 15:57:59
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

    string s;
    cin >> s;
    bool flag = true;
    for (auto ch : s)
    {
        if (ch != '.' && !isdigit(ch))
        {
            flag = false;
            break;
        }
    }

    if (count(s.begin(), s.end(), '.') != 3)
    {
        flag = false;
    }

    if (flag)
    {
        vector<int> arr;
        size_t pos = 0;
        while (1)
        {
            size_t nex = s.find('.', pos);
            if (nex == size_t(-1))
            {
                nex = s.size();
            }

            if (nex - pos > 3)
            {
                flag = 0;
                break;
            }

            try
            {
                arr.push_back(stoi(s.substr(pos, nex)));
            }
            catch (exception& e)
            {
                flag = 0;
                break;
            }

            if (nex != s.size())
            {
                pos = nex + 1;
            }
            else
            {
                break;
            }
        }

        for (int x : arr)
        {
            if (x > 255 || x < 0)
            {
                flag = false;
                break;
            }
        }
    }

    cout << (flag ? "Yes" : "No") << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
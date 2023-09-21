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

ifstream ifs("az.in");
ofstream ofs("az.out");

array<ll, 26> arr;
int k;
string s;

array<ll, 26> dfs(size_t x)
{
    array<ll, 26> res;
    for (size_t i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ifs >> s;
    ifs >> k;

    int num = 0;
    bool flag = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            auto tmp = dfs(i + 1);
            if (arr[0] + tmp[0] < k)
            {
                
            }
        }
        else if (isalpha(ch))
        {
            num = 0;
            flag = 0;
            arr[ch - 'a']++;
        }
        else if (isdigit(ch))
        {
            flag = 1;
            num = num * 10 + ch - '0';
        }
    }

    ifs.close();
    ofs.close();
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
// 2023/07/15 20:16:13
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
int n, m;


bool check(int a, int b, const vector<vector<int>>& func)
{
    for (size_t i = 0; i < func[a].size(); i++)
    {
        if (func[a][i] != func[b][i])
        {
            size_t j;
            for (j = i + 1; j < func[b].size(); j++)
            {
                if (func[a][i] == func[b][j])
                    break;
            }

            if (j == func[b].size())
                return false;
        }
    }

    return true;
}

bool check1(int a, int b, const vector<vector<int>>& func)
{
    if (func[a].size() == func[b].size())
        return false;

    for (size_t i = 0; i < func[a].size(); i++)
    {
        if (func[a][i] != func[b][i])
        {
            size_t j;
            for (j = i + 1; j < func[b].size(); j++)
            {
                if (func[a][i] == func[b][j])
                    break;
            }

            if (j == func[b].size())
                return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<int> arr(n);
    vector<vector<int>> func(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int C;
        cin >> C;
        for (int j = 0; j < C; j++)
        {
            int x;
            cin >> x;
            func[i].emplace_back(x);
        }
        sort(func[i].begin(), func[i].end());
    }

    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            
            if (arr[i] > arr[j])
            {
                if (func[j].size() < func[i].size())
                {
                    continue;
                }
                else
                {
                    if (check(i, j, func))
                        flag = 1;
                }
            }
            else if (arr[i] == arr[j])
            {
                if (func[j].size() <= func[i].size())
                {
                    continue;
                }
                else
                {
                    if (check1(i, j, func))
                        flag = 1;
                }
            }
        }
    }

    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";

    cout << endl;
    return 0;
}
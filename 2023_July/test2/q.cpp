// 2023/07/21 10:49:45
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

    int n;
    cin >> n;
    deque<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    deque<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    bool flag;
    int sum = 0;
    int pre = 0;
    vector<int> index;
    for (size_t i = 0, j = 0; ; i++)
    {
        if (i == a.size() || j == b.size())
        {
            if (i == a.size() && j == b.size())
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            
            break;
        }

        sum += a[i];
        if (sum == b[j])
        {
            i++;
            j++;
            int cnt = count(a.begin() + pre, a.begin() + i, a[pre]);
            if (cnt != i - pre || i - pre == 1)
            {
                index.emplace_back(pre);
                pre = i;
            }
            else
            {
                flag = 0;
                break;
            }

            i--;
            sum = 0;
        }
        else if (sum > b[j])
        {
            flag = 0;
            break;
        }
    }

    if (!flag)
    {
           cout << "NO\n";
    }
    else
    {
        vector<pair<int, char>> ans;
        int begin = 0;
        int tot = 0;
        for (int i = 0, j; i < m; i++)
        {
            sum = 0;
            for (j = begin; sum < b[tot]; j++)
            {
                sum += a[j];
            }
            int end = j;
            int cnt = end - begin;
            while (cnt > 1)
            {
                int max_index = max_element(a.begin() + begin, a.begin() + end) - a.begin();
                if (max_index != begin)
                {
                    while (max_index - 1 >= begin)
                    {
                        ans.emplace_back(max_index, 'L');
                        a.erase(a.begin() + (max_index - 1));
                        max_index--;
                        cnt--;
                    }

                    while (cnt > 1)
                    {
                        ans.emplace_back(max_index, 'R');
                        a.erase(a.begin() + (max_index + 1));
                        cnt--;
                    }
                }
                else
                {
                    while (a[max_index + 1] == a[max_index])
                        max_index++;

                    ans.emplace_back(max_index, 'R');
                    a.erase(a.begin() + max_index + 1);
                    cnt--;

                    while (max_index - 1 >= begin)
                    {
                        ans.emplace_back(max_index, 'L');
                        a.erase(a.begin() + (max_index - 1));
                        max_index--;
                        cnt--;
                    }

                    while (cnt > 1)
                    {
                        ans.emplace_back(max_index, 'R');
                        a.erase(a.begin() + (max_index + 1));
                        cnt--;
                    }
                }
            }

            begin++;
            tot++;
        }

        cout << "YES\n";
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first + 1 << ' ' << ans[i].second << '\n';
        }

        // for (size_t i = 1; i < index.size(); i++)
        // {
        //     int begin = index[i - 1];
        //     int end = index[i];
        //     int cnt = end - begin;
        //     while (cnt > 1)
        //     {
        //         cnt--;
        //         int max_index = max_element(a.begin() + begin, a.begin() + end) - a.begin();
        //         bool update = 0;
        //         if()
        //     }
        // }
    }

    cout << endl;
    return 0;
}
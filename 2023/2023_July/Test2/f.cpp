// 2023/07/22 10:30:01
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    set<int> s, tmp;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.emplace(x);
    }

    
    bool flag = 0;
    
    while (1)
    {
        bool update = 0;
        for (auto it1 = s.begin(), it2 = it1; it1 != s.end(); it1++)
        {
            for (it2 = it1, it2++; it2 != s.end(); it2++)
            {
                if (s.count(abs(*it1 - *it2)) == 0 &&
                    tmp.count(abs(*it1 - *it2)) == 0)
                {
                    tmp.emplace(abs(*it1 - *it2));
                    flag = !flag;
                    update = 1;
                }
            }
        }

        if (update)
        {
            for (auto p : tmp)
            {
                s.insert(p);
            }

            tmp.clear();
        }
        else
        {
            break;
        }
    }


    if (flag)
        cout << "Alice\n";
    else
        cout << "Bob\n";

    cout << endl;
    return 0;
}
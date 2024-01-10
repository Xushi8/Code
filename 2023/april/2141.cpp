// 2023/04/27 16:27:13
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    set<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.emplace(tmp);
    }
    for (auto it1 = a.begin(); it1 != a.end(); it1++)
    {
        auto it2 = ++it1;
        --it1;
        for (; it2 != a.end(); it2++)
        {
            b.emplace(*it1 + *it2);
        }
    }
    
    int ans = 0;
    for (int p : a)
    {
        ans += b.count(p);
    }
    cout << ans;

    cout << endl;
    return 0;
}
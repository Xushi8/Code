// 2023/06/04 13:43:09
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, tt;
    cin >> n >> tt;
    set<pair<int, int>> follow;
    while (tt--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            follow.emplace(a, b);
        }
        else if (t == 2)
        {
            follow.erase(make_pair(a, b));
        }
        else
        {
            if (follow.count(make_pair(a, b)) == 1 && follow.count(make_pair(b, a)) == 1)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    cout << endl;
    return 0;
}
// 2023/06/06 20:57:13
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    multiset<int> que;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a;
            cin >> a;
            que.emplace(a);
        }
        else if (op == 2)
        {
            int b, c;
            cin >> b >> c;
            while (c--)
            {
                auto it = que.find(b);
                if (it == que.end())
                    break;

                que.erase(it);
            }
        }
        else
        {
            cout << *que.rbegin() - *que.begin() << '\n';
        }
    }
    

    cout << endl;
    return 0;
}
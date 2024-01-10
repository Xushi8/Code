// 2023:04:14 19:16:40
#include <bits/stdc++.h>
using namespace std;


const int inf = 0x3f3f3f3f;// 无穷, 表示不可知
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int flag[4] = { 0 };
    int p, q, r, s;
    r = 0;
    p = q = s = inf;
    while (p == inf)
    {
        if (q != inf && flag[0] == 0) // 这里忽略了p != inf
        {
            flag[0] = 1;
            p = 1;
            if ((!p | !q) != 1)
            {
                p = 0;
            }
            cout << "公式: !p | !q. \tq -> p, p: " << p << '\n';
        }

        if (s != inf && r == inf && flag[1] == 0)
        {
            flag[1] = 1;
            r = 1;
            if (((!s) | r) != 1)
            {
                r = 0;
            }
            cout << "公式: !s | r. \ts -> r, r: " << r << '\n';
        }

        if (s != inf && q == inf && flag[2] == 0)
        {
            flag[2] = 1;
            q = 1;
            if ((s | q) != 1)
            {
                q = 0;
            }
            cout << "公式:  s |  q. \ts -> q, q: " << q << '\n';
        }
        
        if (r != inf && s == inf && flag[3] == 0)
        {
            flag[3] = 1;
            s = 1;
            if (((!s) | r) != 1)
            {
                s = 0;
            }
            cout << "公式: !s | r. \tr -> s, s: " << s << '\n';
        }
    }
    cout << p << endl;

    cout << flush;
    system("pause");
    return 0;
}
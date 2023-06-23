// 2023/05/12 15:48:07
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    size_t p1, p2, p3, p4, p5;
    p1 = str.find('B');
    p2 = str.rfind('B');
    if ((p1 & 1) ^ (p2 & 1))
    {
        p3 = str.find('R');
        p4 = str.find('K');
        p5 = str.rfind('R');
        if (p3 < p4 && p4 < p5)
        {
            cout << "Yes";
        }
        else
            cout << "No";
    }
    else
        cout << "No";

    cout << endl;
    return 0;
}
// 2023/04/27 13:29:29
#include <bits/stdc++.h>
using namespace std;

class Stu
{
public:
    int a, b, c, d;
    Stu(int _a, int _b, int _c, int _d)
    {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
};
vector<Stu> arr;


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr.emplace_back(a, b, c, a + b + c);
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i].a - arr[j].a) <= 5 && abs(arr[i].b - arr[j].b) <= 5 && abs(arr[i].c - arr[j].c) <= 5 && abs(arr[i].d - arr[j].d) <= 10)
                ans++;
        }
    }
    cout << ans;    

    cout << endl;
    return 0;
}
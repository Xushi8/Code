// 2023/05/06 22:35:12
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i: arr) cin >> i;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                int tmp = 1;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] == 0)
                    {
                        tmp++;
                    }
                    else
                    {
                        i = j - 1;
                        break;
                    }
                }
                cnt = max(cnt, tmp);
            }
        }
        cout << cnt << '\n';
    }

    cout << endl;
    return 0;
}
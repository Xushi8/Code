// 2023/06/04 22:59:04
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
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        if (arr[1] == 1)
        {
            if (arr[2] == n)
            {
                cout << 1 << ' ' << 1 << '\n';
            }
            else
            {
                int maxn = -1;
                int index = -1;
                for (int i = 1; i <= n; i++)
                {
                    if (maxn < arr[i])
                    {
                        maxn = arr[i];
                        index = i;
                    }
                }
                cout << 2 << ' ' << index << '\n';
            }
        }
        else if (arr[n] == 1)
        {
            if (arr[n - 1] == n)
            {
                cout << 1 << ' ' << 1 << '\n';
            }
            else
            {
                int maxn = -1;
                int index = -1;
                for (int i = 1; i <= n; i++)
                {
                    if (maxn < arr[i])
                    {
                        maxn = arr[i];
                        index = i;
                    }
                }
                cout << n - 1 << ' ' << index << '\n';
            }
        }
        else
        {
            int index_of_1;
            for (int i = 1; i <= n; i++)
            {
                if (arr[i] == 1)
                {
                    index_of_1 = i;
                    break;
                }
            }

            int maxn = -1;
            int index = -1;
            for (int i = 1; i <= n; i++)
            {
                if (index_of_1 - 1 <= i && i <= index_of_1 + 1)
                    continue;

                if (maxn < arr[i])
                {
                    maxn = arr[i];
                    index = i;
                }
            }
            if (arr[index_of_1 - 1] < arr[index_of_1 + 1])
            {
                if (maxn > arr[index_of_1 - 1])
                {
                    cout << index << ' ' << index_of_1 - 1 << '\n';
                }
            }
            else
            {
                if (maxn > arr[index_of_1 + 1])
                {
                    cout << index << ' ' << index_of_1 + 1 << '\n';
                }
            }
        }
    }

    cout << endl;
    system("pause");
    return 0;
}
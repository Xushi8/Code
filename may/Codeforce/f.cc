// 2023/05/06 23:44:02
#include <bits/stdc++.h>
using namespace std;


int arr[201];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        memset(arr, 0, sizeof(arr));
        vector<pair<int, int>> tmp(n);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[a]++;
            arr[b]++;
            tmp[i].first = a;
            tmp[i].second = b;
        }
        int a = -1, b = -1;
        int c = -1, d = -1;
        for (int i = 0; i < 201; i++)
        {
            if (arr[i] != 0 && arr[i] != 1)
            {
                if (a == -1)
                {
                    a = arr[i];
                    b = i;
                }
                else if (a == arr[i])
                    continue;
                else
                {
                    c = arr[i];
                    d = i;
                    break;
                }
            }
        }
        int flag = -1;
        for (int i = 0; i < n; i++)
        {
            if (tmp[i].first == b && arr[tmp[i].second] == 1)
            {
                flag = tmp[i].second;
                break;
            }
            if (tmp[i].second == b && arr[tmp[i].first] == 1)
            {
                flag = tmp[i].first;
                break;
            }
        }
        if (c == -1)
        {
            cout << arr[b] << ' ' << arr[b] - 1 << '\n';
            continue;
        }
        if (flag == -1)
        {
            cout << arr[b] << ' ' << arr[d] - 1 << '\n';
        }
        else
        {
            cout << arr[d] << ' ' << arr[b] - 1 << '\n';
        }

        // for (int i = 0; i < m; i++)
        // {
        //     int a, b;
        //     cin >> a >> b;
        //     arr[a]++;
        //     arr[b]++;
        //     tmp[i].first = a;
        //     tmp[i].second = b;
        // }
        // pair<int, int> count[2];
        // count[0].first = -1; count[0].second = 0;
        // count[1].first = -1; count[1].second = 0;
        // for (int i = 0; i < 201; i++)
        // {
        //     if (arr[i] != 0 && arr[i] != 1)
        //     {
        //         if (count[0].first == -1 || count[0].first == arr[i])
        //         {
        //             count[0].first = arr[i];
        //             count[0].second++;
        //         }
        //         else
        //         {
        //             count[1].first = arr[i];
        //             count[1].second++;
        //         }
        //     }
        // }
        // int flag = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (arr[tmp[i].first] == 1 && arr[tmp[i].second] != 1)
        //     {
        //         flag = tmp[i].second;
        //         break;
        //     }
        //     if (arr[tmp[i].second] == 1)
        //     {
        //         flag = tmp[i].second;
        //         break;
        //     }
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     if()
        // }

        // if (count[0].second > count[1].second)
        //     swap(count[0], count[1]);
        // cout << count[0].first << ' ' << count[1].first - 1 << '\n';

        
        // int arr[3];
        // arr[2] = -1;
        // auto it = s.begin();
        // arr[0] = s.count(*it);
        // for (; it != s.end(); it++)
        // {
        //     if (s.count(*it) != arr[0])
        //     {
        //         arr[1] = s.count(*it);
        //         break;
        //     }
        // }
        // for (; it != s.end(); it++)
        // {
        //     if (s.count(*it) != arr[0] && s.count(*it) != arr[1])
        //     {
        //         arr[2] = s.count(*it);
        //         break;
        //     }
        // }
        // if (arr[2] == -1)
        // {
        //     arr[2] = max(arr[0], arr[1]);
        //     sort(arr, arr + 3);
        //     cout << arr[2] << ' ' << arr[2] - 1 << '\n';
        // }
        // else
        // {
        //     sort(arr, arr + 3);
        //     cout << arr[2] << ' ' << arr[1] - 1 << '\n';
        // }



        // for (int i = 2; i < m; i++)
        // {
        //     for (int j = 2; j < m; j++)
        //     {
        //         if (i * j + i == m)
        //         {
        //             cout << i << ' ' << j << '\n';
        //         }
        //     }
        // }
    }

    cout << endl;
    return 0;
}
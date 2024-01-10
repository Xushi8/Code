// 2023/06/04 13:24:32
#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    vector<pair<int, int>> arr;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            int a = j / 10;
            int b = i % 10;
            int c = i / 10 * 10 + a;
            int d = j % 10 + 10 * b;
            if (0 <= c && c < 24 && 0 <= d && d < 60)
            {
                arr.emplace_back(i, j);
            }
        }
    }

    int a, b;
    cin >> a >> b;
    bool flag = 1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        pair<int, int> tmp = { a, b };
        if (tmp == arr[i])
        {
            cout << tmp.first << ' ' << tmp.second << ' ';
            flag = 0;
            break;
        }
        else if (arr[i] < tmp && tmp <= arr[i + 1])
        {
            cout << arr[i + 1].first << ' ' << arr[i + 1].second;
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << arr[0].first << ' ' << arr[0].second;
    }

    cout << endl;
    return 0;
}
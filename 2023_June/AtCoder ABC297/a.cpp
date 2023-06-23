// 2023/06/04 13:13:20
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i;
    int n, tt;
    cin >> n >> tt;
    deque<int> arr(n);
    for (int& x : arr)
        cin >> x;
    while (tt--)
    {
        arr.pop_front();
        arr.push_back(0);
    }
    for (auto it = arr.begin(); it != arr.end(); it++)
        cout << *it << ' ';

    cout << endl;
    return 0;
}
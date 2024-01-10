// 2023/06/28 21:28:39
#include <bits/stdc++.h>
using namespace std;

bool func(int n)
{
    return n % 2 != 0;
}

void print(int n)
{
    cout << n << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr;
    arr.emplace_back(3);
    arr.emplace_back(4);
    arr.emplace_back(4);
    arr.emplace_back(3);
    arr.emplace_back(2);
    arr.emplace_back(1);

    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << '\n';

    cout << '\n';


    arr.erase(remove_if(arr.begin(), arr.end(),
        [](int n) -> bool
        {
            return n % 2 != 0;
        }), arr.end());

    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << '\n';


    ::cout << flush;
    return 0;
}
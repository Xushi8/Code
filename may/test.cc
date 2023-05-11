// 2023/05/01 14:09:34
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr;
    arr.push_back(32);
    arr.emplace_back(33);
    int i = 222;
    arr.push_back(i);
    arr.emplace_back(i);

    cout << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     unordered_set<int> uset;
//     int begin = clock();
//     for (int i = 0; i < 100000; i++)
//     {
//         uset.insert(i);
//     }
//     int end = clock();
//     cout << (end - begin) / 1000.0 << endl;

//     // for (auto it = uset.begin(); it != uset.end(); it++)
//     // {
//     //     cout << *it << '\n';
//     // }
//     // cout << endl; 

//     auto it = uset.find(567);
//     cout << *it << endl;

//     system("pause");
//     return 0;
// }

void print(const int& a)
{
    cout << a << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << i << '\n';
    // }
    // for (int i = 10; i < 20; i++)
    // {
    //     printf("%d\n", i);
    // }
    // cout << endl;

    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(rand());
    }
    
    for_each(v.begin(), v.end(), print);
    sort(v.begin(), v.end(), greater<int>());
    cout << '\n' << '\n' << '\n' << '\n';
    for_each(v.begin(), v.end(), print);
    cout << endl;

    system("pause");
    return 0;
}
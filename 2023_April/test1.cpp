#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n = 2021041820210418;
    vector<int> arr;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr.emplace_back(i);
            if (i != n / i)
            {
                arr.emplace_back(n / i);
            }
        }
    }

    cout << flush;
    system("pause");
    return 0;
}
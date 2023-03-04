#include<bits/stdc++.h>
using namespace std;

void test1(const vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> V;
    V.reserve(10);
    for (int i = 0; i < 10; i++)
    {
        V[i] = rand();
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << V[i] << '\n';
    }
    cout << endl;

    sort(V.begin(), V.end());
    
    for (int i = 0; i < 10; i++)
    {
        cout << V[i] << '\n';
    }
    cout << endl;

    system("pause");
    return 0;
}
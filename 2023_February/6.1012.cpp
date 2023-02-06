#include<bits/stdc++.h>
using namespace std;
int n, m;

bool cmp(string a, string b)
{
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str[20];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cmp(str[j], str[j + 1]))
            {
                swap(str[j], str[j + 1]);
            }
        }
    }

    system("pause");
    return 0;
}
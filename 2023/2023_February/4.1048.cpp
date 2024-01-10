#include<bits/stdc++.h>
using namespace std;

int W, n, w[105], v[105];
int f[1005];

int main()
{
    cin >> W >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = W; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }

    cout << f[W] << endl;
    system("pause");
    return 0;
}
// 2023/04/27 12:04:19
#include <bits/stdc++.h>
using namespace std;

bool isnp[100005];
vector<int> prime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i < 100005; i++)
    {
        if (!isnp[i])
            prime.emplace_back(i);

        for (int p : prime)
        {
            if (p * i > 100003) break;
            isnp[p * i] = 1;
            if (i % p == 0) break;
        }
    }
    int tmp = 0;
    for (int p : prime)
    {
        if (tmp + p <= n)
        {
            cout << p << '\n';
            tmp += p;
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans;

    cout << endl;
    return 0;
}
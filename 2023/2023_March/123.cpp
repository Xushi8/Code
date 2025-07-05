#include <bits/stdc++.h>
using namespace std;

vector<long long> prime;
vector<long long> ans;
bool isnp[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (long long i = 2; i < 1000002; i++)
    {
        if (!isnp[i]) prime.emplace_back(i);

        for (const long long& p : prime)
        {
            if (p * i > 1000002) break;

            isnp[p * i] = 1;

            if (i % p == 0) break;
        }
    }
    
    for (int i = 0; i < (int)prime.size(); i++)
    {
        ans.emplace_back(prime[i] * prime[i]);
    }

    int tt;
    cin >> tt;
    while (tt--)
    {
        long long tmp;
        cin >> tmp;
        if (binary_search(ans.begin(), ans.end(), tmp)) cout << "YES\n";
        else cout << "NO\n";
    }

    cout << flush;
    system("pause");
    return 0;
}
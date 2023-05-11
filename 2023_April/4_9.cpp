// 2023:04:09 14:42:48
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
bool isnp[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int begin = clock();
    for (int i = 2; i < 1000005; i++)
    {
        if (!isnp[i]) prime.emplace_back(i);
        for (const int& p : prime)
        {
            if (p * i > 1000005) break;
            isnp[p * i] = 1;
            if (i % p == 0) break;
        }
    }
    int end = clock();
    cout << (end - begin) / 1000.;

    cout << flush;
    system("pause");
    return 0;
}
// 2023/07/05 22:49:44
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

vector<int> prime;
bool isnp[N];
int sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
            prime.emplace_back(i);

        for (int p : prime)
        {
            if (p * i >= N)
                break;

            isnp[p * i] = 1;

            if (i % p == 0)
                break;
        }
    }

    int now = 0;
    sum[0] = 0;
    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1];
        if (i == prime[now])
            sum[i]++, now++;
    }

    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (1 <= a && a <= m && 1 <= b && b <= m)
            cout << sum[b] - sum[a - 1] << '\n';
        else
            cout << "Crossing the line\n";
    }

    cout << endl;
    return 0;
}
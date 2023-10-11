// 2023/10/11 14:12:48
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
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

bool isnp[N];
vector<int> primes;

void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
            primes.emplace_back(i);
        for (int p : primes)
        {
            if (p * i >= N)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
}

map<int, ll> arr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    get_primes();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        map<int, ll> mp;
        for (int p : primes)
        {
            if (p * p > x)
                break;
            
            while (x % p == 0)
            {
                mp[p]++;
                x /= p;
            }
        }
        if (x != 1)
            mp[x]++;
        arr[i + 1] = move(mp);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
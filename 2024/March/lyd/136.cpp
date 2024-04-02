// 2024/04/02 17:50:39
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
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;
constexpr int MOD = 133331;

int H(array<int, 6> const& arr)
{
	int sum = 0, mul = 1;
	for (int i = 0; i < 6; i++)
	{
		sum = (sum + arr[i]) % MOD;
		mul = (1LL * mul * arr[i]) % MOD;
	}
	return (sum + mul) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	map<int, vector<array<int, 6>>> mp;
	while (n--)
	{
		array<int, 6> a(6);
		for (int i = 0; i < 6; i++)
		{
			cin >> a[i];
		}

		int val = H(a);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
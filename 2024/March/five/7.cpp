// 2024/04/03 18:51:38
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		int ans = 0;
		for (int j = 0, k = n - 1; j < n; j++, --k)
		{
			if (s[j] == 'n')
			{
				ans += 1 << k;
			}
			else
			{
				
            }
		}
		cout << ans + 1 << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
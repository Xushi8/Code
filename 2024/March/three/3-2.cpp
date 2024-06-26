// // 2024/03/27 14:42:17
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// #include <numeric>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// constexpr int N = 1000005;

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	string s;
// 	cin >> s;
// 	ll tmp[4] = {0};
// 	tmp[0] = 1;

// 	for (size_t i = 0; i < s.size();)
// 	{
// 		size_t j;
// 		for (j = i; j < s.size(); j++)
// 		{
// 			if (s[j] != s[i])
// 				break;
// 		}
// 		int cnt = j - i;
//         i = j;
// 		if (cnt >= 1)
// 			tmp[1]++;
// 		if (cnt >= 2)
// 			tmp[2]++;
// 		if (cnt >= 3)
// 			tmp[3]++;
// 	}

// 	ll ans = 0;
// 	ans += tmp[0];
// 	ans += tmp[1];
// 	ll s1 = tmp[1] - tmp[2];
// 	ll s2 = tmp[2] - tmp[3];
// 	ll s3 = tmp[3];
// 	// ans += tmp[2] + (tmp[1] - tmp[2]) * tmp[2] + tmp[2] * (tmp[2] - 1) / 2 + tmp[1] * (tmp[1] - 1) / 2;
// 	// ans += tmp[2] + tmp[2] * (tmp[2] - 1) / 2 + s1 * (s1 - 1) / 2 + s1 * tmp[2];
// 	ans += s3 + s2 + s3 * (s3 - 1) / 2 + s3 * s2 + s3 * s1;
// 	ans += s1 * (s1 - 1) / 2 + s1 * s2 + s2 * (s2 - 1) / 2;
// 	// ans += tmp[3] + tmp[3] * (tmp[3] - 1) / 2 + tmp[3] * (tmp[2] - tmp[3]) + tmp[3] * (tmp[1] - tmp[2]) + ;
// 	ans += s3;
// 	ans += s3 * (s3 - 1) / 2 + s3 * s2 + s3 * s1;
// 	ans += s2 * s3 + s2 * (s2 - 1) / 2 + s2 * s1;
// 	ans += s3 * (s3 - 1) * (s3 - 2) / 3 + s3 * (s3 - 1) * s2 / 2 + s3 * s3 * (s3 - 1) * s1 / 2;
// 	ans += s3 * s2 * (s2 - 1) / 2 + s3 * s2 * s1 + s3 * s1 * (s1 - 1) / 2;
// 	ans += s1 * (s1 -1) * (s1 - 2) / 3 + s1 * (s1 - 1) * s2  / 2 + s1 * s2 * (s2 - 1) / 2 + s2 * (s2 - 1) * (s2 - 2) / 3;
// 	cout << ans << endl;

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/03/29 18:45:35
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

ll dp[N][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	// vector<vector<ll>> dp(s.size() + 1, vector<ll>(4));
	for (size_t i = 0; i <= s.size(); i++)
	{
		dp[i][0] = 1;
	}

	vector<int> last_vis(256);
	for (int i = 1; i <= s.size(); i++)
	{
		int pre = last_vis[s[i - 1]];
		last_vis[s[i - 1]] = i;

		for (int j = 1; j <= 3; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

			if (pre != 0 && j - (i - pre) >= 0)
			{
				dp[i][j] -= dp[pre - 1][j - (i - pre)];
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < 4; i++)
	{
		ans += dp[s.size()][i];
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
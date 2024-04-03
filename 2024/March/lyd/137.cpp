// // 2024/04/03 13:46:24
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

// constexpr int BASE = 131;

// uint64_t f[N], p[N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

// 	string s;
// 	cin >> s;
// 	int n = s.size(); 
// 	s.insert(s.begin(), '\0');
// 	p[0] = 1;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		f[i] = s[i] - 'a' + 1 + f[i - 1] * BASE;
// 		p[i] = p[i - 1] * BASE;
// 	}

// 	int q;
// 	cin >> q;
// 	while (q--)
// 	{
// 		int l1, r1, l2, r2;
// 		cin >> l1 >> r1 >> l2 >> r2;
// 		cout << (f[r1] - f[l1 - 1] * p[r1 - l1 + 1] == f[r2] - f[l2 - 1] * p[r2 - l2 + 1] ? "Yes" : "No") << '\n';
// 	}

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     return 0;
// }

#pragma GCC optimize("Ofast,avx,avx2")
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;

constexpr int BASE = 131;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	s.insert(s.begin(), '\0');
	vector<uint64_t> f(n + 1), p(n + 1);
	p[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * BASE + s[i] - 'a' + 1;
		p[i] = p[i - 1] * BASE;
	}

	int q;
	cin >> q;
	while (q--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		cout << (f[r1] - f[l1 - 1] * p[r1 - l1 + 1] ==
				 f[r2] - f[l2 - 1] * p[r2 - l2 + 1] ? "Yes" : "No") << '\n';
    }

	return 0;
}
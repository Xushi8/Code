// // 2024/04/09 15:19:24
// #pragma GCC optimize(Ofast)
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

// bool is_lun(int y)
// {
// 	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
// }

// bool is_huiwen(string_view s)
// {
// 	if (s.size() != 8)
// 		__builtin_unreachable();
// 	for (size_t i = 0; i < s.size() / 2; i++)
// 	{
// 		if (s[i] != s[s.size() - 1 - i])
// 			return false;
// 	}
// 	return true;
// }

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	string s, t;
// 	cin >> s >> t;
// 	int y1 = stoi(s.substr(0, 4));
// 	int m1 = stoi(s.substr(4, 2));
// 	int d1 = stoi(s.substr(6));

// 	int y2 = stoi(t.substr(0, 4));
// 	int m2 = stoi(t.substr(4, 2));
// 	int d2 = stoi(t.substr(6));

// 	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 	int ans = 0;
// 	while (1)
// 	{
// 		string s1 = to_string(y1), s2 = to_string(m1), s3 = to_string(d1);
// 		s1.insert(s1.begin(), 4 - s1.size(), '0');
// 		s2.insert(s2.begin(), 2 - s2.size(), '0');
// 		s3.insert(s3.begin(), 2 - s3.size(), '0');
// 		if (is_huiwen(s1 + s2 + s3)) ans++;

// 		d1++;
// 		if (d1 == days[m1] + 1)
// 		{
// 			if (m1 == 2 && is_lun(y1))
// 			{
// 			}
// 			else
// 			{
// 				d1 = 1;
// 				m1++;
// 				if (m1 == 13)
// 				{
// 					m1 = 1;
// 					y1++;
// 				}
// 			}
// 		}
// 		else if (d1 > days[m1] + 1)
// 		{
// 			d1 = 1;
// 			m1++;
// 			if (m1 == 13)
// 			{
// 				m1 = 1;
// 				y1++;
// 			}
// 		}

// 		if (y1 == y2 && m1 == m2 && d1 == d2)
// 			break;
// 	}

// 	string s1 = to_string(y1), s2 = to_string(m1), s3 = to_string(d1);
// 	s1.insert(s1.begin(), 4 - s1.size(), '0');
// 	s2.insert(s2.begin(), 2 - s2.size(), '0');
// 	s3.insert(s3.begin(), 2 - s3.size(), '0');
// 	if (is_huiwen(s1 + s2 + s3)) ans++;

// 	cout << ans << endl;

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/04/09 15:43:55
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

bool is_lun(int y)
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	int y1 = stoi(s.substr(0, 4));
	int m1 = stoi(s.substr(4, 2));
	int d1 = stoi(s.substr(6));

	int y2 = stoi(t.substr(0, 4));
	int m2 = stoi(t.substr(4, 2));
	int d2 = stoi(t.substr(6));
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int ans = 0;
	for (int year = y1; year <= y2; year++)
	{
		string s1 = to_string(year);
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		s1 += s2;
		int mon = stoi(s1.substr(4, 2));
		int day = stoi(s1.substr(6, 2));
		if (year == y1)
		{
			if (mon < m1 || (mon == m1 && day < d1))
				continue;
		}
		else if (year == y2)
		{
			if (mon > m2 || (mon == m2 && day > d2))
				continue;
		}

		if (mon == 0 || mon > 12 || day == 0)
			continue;
		if (mon != 2 && day > days[mon])
			continue;
		if (mon == 2)
		{
			if (is_lun(year))
			{
				if (day > 29)
					continue;
			}
			else
			{
				if (day > 28)
					continue;
			}
		}
		ans++;
	}

	cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
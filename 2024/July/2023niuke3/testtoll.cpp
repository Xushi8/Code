#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>
#include <algorithm>
#include <execution>
using namespace std;
using i64 = int64_t;

i64 toll(string_view s)
{
	i64 res = 0;
	for (size_t i = s.size(), j = 0; i--; j++)
	{
		if (s[i] == '1')
		{
			res |= 1ll << j;
		}
	}
	return res;
}

i64 toll(string_view s, int)
{
	string t(s.rbegin(), s.rend());
	i64 res = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (t[i] == '1')
		{
			res |= 1ll << i;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for_each_n(arr.begin(), n, [](string const& s)
		{
			i64 a = stoll(s, 0, 2);
			i64 b = toll(s);
			i64 c = toll(s, 1);
			if (a != b || b != c || c != a) [[unlikely]]
			{
				cout << s << ' ' << a << ' ' << b << '\n';
			}
		});
}
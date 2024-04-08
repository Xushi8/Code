// 2024/04/08 16:00:17
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

vector<int> get_pmt(string_view s)
{
	vector<int> pmt(s.size());
	for (size_t i = 1, j = 0; i < s.size(); i++)
	{
		while (j != 0 && s[i] != s[j])
			j = pmt[j - 1];
		if (s[i] == s[j])
			j++;
		pmt[i] = j;
	}
	return pmt;
}

void kmp(string_view s, string_view t)
{
	auto pmt = get_pmt(t);
	for (size_t i = 0, j = 0; i < s.size(); i++)
	{
		while (j != 0 && s[i] != t[j])
			j = pmt[j - 1];
		if (s[i] == t[j])
			j++;
		if (j == t.size())
		{
			cout << i - j + 2 << '\n';
			j = pmt[j - 1];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	kmp(s, t);
	auto pmt = get_pmt(t);
	for (auto x : pmt)
	{
		cout << x << ' ';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
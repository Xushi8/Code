#include <bits/stdc++.h>
using namespace std;

vector<size_t> get_pmt(string_view s)
{
	vector<size_t> pmt(s.size());
	for (size_t i = 1, j = 0; i < s.size(); i++)
	{
		while (j != 0 && s[i] != s[j])
		{
			j = pmt[j - 1];
		}
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

void brute_force(string_view s, string_view t)
{
	std::boyer_moore_searcher bmsearch{t.begin(), t.end()};
	for (auto pos = std::search(s.begin(), s.end(), bmsearch);
		 pos != s.end();
		 pos = std::search(pos + 1, s.end(), bmsearch))
	{
		cout << pos - s.begin() + 1 << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	// kmp(s, t);
	brute_force(s, t);

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
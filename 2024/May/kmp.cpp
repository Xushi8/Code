// 2024/05/31 17:08:31
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
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
	for (auto x : get_pmt(t))
	{
		cout << x << ' ';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
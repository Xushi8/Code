// #pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <math.h>
#include <stack>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;
typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define N 1000005

vector<int> get_pmt(string const& s)
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (cin >> s)
	{
		vector<int> ans;
		vector<int> pmt = get_pmt(s);
		int t = s.size() - 1;
		while (t != 0)
		{
			// if (s[t] == s.back())
			if (s[t] == s[s.size() - 1])
				ans.push_back(t + 1);
			t = pmt[t - 1];
		}

		// if (s.front() == s.back())
		if (s[0] == s[s.size() - 1])
			ans.push_back(1);

		reverse(ans.begin(), ans.end());
		// for (auto x : ans)
		for (size_t i = 0; i < ans.size(); i++)
		{
			int x = ans[i];
			cout << x << ' ';
		}
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
}
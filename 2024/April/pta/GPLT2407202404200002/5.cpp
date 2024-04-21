#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> weijin(n);
	for (auto& x : weijin)
	{
		cin >> x;
	}

	int m;
	cin >> m;
	string s;
	cin.ignore(111, '\n');
	getline(cin, s);

	int cnt = 0;
	for (auto const& ci : weijin)
	{
		size_t pos = 0;
		while ((pos = s.find(ci)) != -1)
		{
			s.replace(pos, ci.size(), "<censored>");
			cnt++;
		}
	}

	if (cnt >= m)
	{
		cout << "He Xie Ni Quan Jia!\n";
	}
	else
	{
		cout << s << endl;
	}

	return 0;
}

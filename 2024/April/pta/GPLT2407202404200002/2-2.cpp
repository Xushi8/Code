#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

string split(string_view s)
{
	string res;
	res += s.front();
	for (size_t i = 1; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			size_t j;
			for (j = i + 1; j < s.size(); j++)
			{
				if (s[j] != ' ')
					break;
			}
			if (j == s.size())
			{
				return res;
			}

			res += s[j];
			i = j;
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, vector<string>> mp;
	int n;
	cin >> n;
	cin.ignore(111, '\n');
	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		string res = split(s);
		cerr << res << endl;
		mp[res].push_back(std::move(s));
	}

	for (auto& [x, y] : mp)
	{
		sort(y.begin(), y.end());
		//		for(auto& z : y) {
		//			cerr << z << endl;
		//		}
	}

	int m;
	cin >> m;
	cin.ignore(111, '\n');
	for (int i = 0; i < m; i++)
	{
		getline(cin, s);
		auto const& vec = mp[split(s)];
		if (!vec.empty())
		{
			for (size_t j = 0; j < vec.size(); j++)
			{
				if (j != 0)
					cout << '|';
				cout << vec[j];
			}
		}
		else
		{
			cout << s;
		}
		cout << '\n';
	}

	return 0;
}

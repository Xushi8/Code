// 2024/03/30 18:50:02
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

void replace(string& s, string_view from, string_view to)
{
	for (int i = 0;; i++)
	{
		i = s.find(from, i);
		if (i == -1)
			break;
		if ((i == 0 || !isalnum(s[i - 1])) && (i == s.size() - from.size() || !isalnum(s[i + from.size()])))
			s.replace(i, from.size(), to);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin.ignore(111, '\n');
	while (n--)
	{
		getline(cin, s);
		cout << s << '\n';
		cout << "AI: ";

		while (s.front() == ' ')
			s.erase(s.begin());
		while (s.back() == ' ')
			s.pop_back();

		for (int i = 0; i < s.size(); i++)
		{
			if (isupper(s[i]) && s[i] != 'I')
			{
				s[i] = tolower(s[i]);
				continue;
			}

			if (s[i] == ' ')
			{
				while (s[i + 1] == ' ')
					s.erase(s.begin() + i + 1);
				if (!isalnum(s[i + 1]))
					s.erase(s.begin() + i);
				continue;
			}
		}


		replace(s, "can you", "@ can");
		replace(s, "could you", "@ could");
		replace(s, "I", "you");
		replace(s, "me", "you");
		
		for (auto& ch : s)
		{
			if (ch == '?')
				ch = '!';
			if (ch == '@')
				ch = 'I';
		}

		cout << s << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
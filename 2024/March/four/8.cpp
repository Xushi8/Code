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
	size_t pos = string::npos;

	while (1)
	{
		pos = s.find(from, pos + 1);
		if (pos != -1)
		{
			if ((pos == 0 || (!isalpha(s[pos - 1]) && !isdigit(s[pos - 1]))) && !isalpha(s[pos + from.size()]) && !isdigit(s[pos + from.size()]))
				s.replace(pos, from.size(), to);
		}
		else
		{
			break;
		}
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

		for (int i = 0; i < s.size();)
		{
			if (s[i] == ' ')
				s.erase(s.begin());
			else
				break;
		}

		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
				s.pop_back();
			else
				break;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (isupper(s[i]) && s[i] != 'I')
			{
				s[i] = tolower(s[i]);
				continue;
			}

			if (s[i] == ' ')
			{
				for (int j = i + 1; j < s.size();)
				{
					if (s[j] == ' ')
						s.erase(s.begin() + j);
					else
						break;
				}
				continue;
			}

			if (s[i] == '?')
				s[i] = '!';

			if (!isalpha(s[i]) && !isdigit(s[i]))
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (s[j] == ' ')
						s.erase(s.begin() + j);
					else
						break;
				}
			}
		}

		replace(s, "I", "you");
		replace(s, "me", "you");
		replace(s, "can you", "I can");
		replace(s, "could you", "I could");

		cout << s << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
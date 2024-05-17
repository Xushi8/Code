// 2024/05/17 15:53:05
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

map<string, char, greater<>> mp = {
	{"iu", 'q'},
	{"en", 'f'},
	{"ei", 'w'},
	{"eng", 'g'},
	{"ang", 'h'},
	{"uan", 'r'},
	{"an", 'j'},
	{"ue", 't'},
	{"uai", 'k'},
	{"ing", 'k'},
	{"un", 'y'},
	{"uang", 'l'},
	{"iang", 'l'},
	{"sh", 'u'},
	{"ou", 'z'},
	{"ch", 'i'},
	{"ia", 'x'},
	{"ua", 'x'},
	{"uo", 'o'},
	{"ao", 'c'},
	{"ie", 'p'},
	{"zh", 'v'},
	{"ui", 'v'},
	{"in", 'b'},
	{"ong", 's'},
	{"iong", 's'},
	{"iao", 'n'},
	{"ai", 'd'},
	{"ian", 'm'},
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (getline(cin, s))
	{
		size_t pos = 0;
		for (size_t i = 1; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				auto t = s.substr(pos, i - pos);
				pos = i + 1;
				if (t.size() == 1)
				{
					cout << t << t;
				}
				else if (t.size() == 2)
					cout << t;
				else
				{
					int siz = -1;
					bool flag = 0;
					for (auto const& [x, y] : mp)
					{
						if (t.substr(0, x.size()) == x)
						{
							if (x.size() == t.size())
							{
								cout << t.front() << y;
								flag = 1;
							}
							else
							{
								cout << y;
								siz = x.size();
							}
							break;
						}
					}
					if (flag)
					{
						cout << ' ';
						continue;
                        }
					if (siz == -1)
					{
						siz = 1;
						cout << t.front();
					}
					if (siz + 1 == t.size())
						cout << t.back();
					else if (siz == t.size()) {}
					else
						cout << mp[t.substr(siz)];
				}
				cout << ' ';
			}
		}
		auto t = s.substr(pos);
		if (t.size() == 1)
		{
			cout << t << t;
		}
		else if (t.size() == 2)
			cout << t;
		else
		{
			int siz = -1;
			bool flag = 0;
			for (auto const& [x, y] : mp)
			{
				if (t.substr(0, x.size()) == x)
				{
					if (x.size() == t.size())
					{
						cout << t.front() << y;
						flag = 1;
					}
					else
					{
						cout << y;
						siz = x.size();
					}
					break;
				}
			}
			if (flag)
			{
				cout << '\n';
				continue;
			}
			if (siz == -1)
			{
				siz = 1;
				cout << t.front();
			}
			if (siz + 1 == t.size())
				cout << t.back();
			else if (siz == t.size()) {}
			else
				cout << mp[t.substr(siz)];
		}
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
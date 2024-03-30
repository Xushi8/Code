// 2024/03/30 18:25:42
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin.ignore(111, '\n');
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		size_t pos = s.find(',');
		if (int(pos - 3) < 0)
		{
			cout << "Skipped" << '\n';
			continue;
		}

		if (s.substr(pos - 3, 3) == "ong" && s.substr(s.size() - 4, 3) == "ong")
		{
			// cout << s << '\n';
			pos = -1;
			for (int j = 0; j < 3; j++)
			{
				pos = s.rfind(' ', pos);
				pos--;
			}

			cout << s.substr(0, pos + 2) << "qiao ben zhong." << '\n';
		}
		else
		{
			cout << "Skipped" << '\n';
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
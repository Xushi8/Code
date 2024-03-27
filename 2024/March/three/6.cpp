// 2024/03/27 13:30:50
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

	char ch;
	int n;
	cin >> ch >> n;
	vector<string> s1(n);
	cin.ignore(111, '\n');
	for (int i = 0; i < n; i++)
	{
		getline(cin, s1[i]);
	}

	vector<string> s2(n);
	for (int i = 0; i < n; i++)
	{
		s2[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			s2[i][j] = s1[n - i - 1][n - j - 1];
		}
	}

	if (s1 == s2)
	{
		cout << "bu yong dao le\n";
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s2[i][j] == ' ')
				cout << ' ';
			else
				cout << ch;
		}
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
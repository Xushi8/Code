// 2024/04/06 14:01:56
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

	string s;
	cin >> s;
	if (s.size() == 6)
	{
		cout << string(s.data(), 4) << '-' << string(s.data() + 4) << endl;
	}
	else
	{
		int x = stoi(string(s.data(), 2));
		if (x < 22)
		{
			cout << "20";
		}
		else
		{
			cout << "19";
		}
        cout << x / 10 << x % 10;
        cout << '-';
		cout << string(s.data() + 2) << endl;
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
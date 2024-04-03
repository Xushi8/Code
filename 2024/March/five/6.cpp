// 2024/04/03 18:44:58
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

	int t = 0;
	int cnt = 0;
	string s;
	int id = -1;
	while (getline(cin, s))
	{
		if (s.size() == 1 && s.front() == '.')
			break;
		t++;
		if (s.find("chi1 huo3 guo1") != -1)
		{
			if (id == -1)
			{
				id = t;
			}
			cnt++;
        }
	}

	cout << t << '\n';
	if (id == -1)
	{
		cout << "-_-#\n";
	}
	else
	{
		cout << id << ' ' << cnt << '\n';
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
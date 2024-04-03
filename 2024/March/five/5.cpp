// 2024/04/03 18:39:30
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

	int a[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	int minn, wucha;
	cin >> minn >> wucha;
	int maxx = *max_element(a, a + 4);

	vector<int> ans;
	for (int i = 0; i < 4; i++)
	{
		if (maxx - a[i] > wucha)
		{
			ans.emplace_back(i);
		}
		else if (a[i] < minn)
		{
			ans.emplace_back(i);
        }
	}

	if (ans.size() == 0)
	{
		cout << "Normal";
	}
	else if (ans.size() == 1)
	{
		cout << "Warning: please check #";
		cout << ans.back() + 1;
		cout << "!";
	}
	else
	{
		cout << "Warning: please check all the tires!";
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
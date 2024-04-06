// 2024/04/06 14:18:36
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

	vector<int> ans(N);
	cin >> ans[0] >> ans[1];
	int siz;
	cin >> siz;
	int l = 2;
	for(int i = 2; i < siz; i++)
	{
		int x = ans[i - 1] * ans[i - 2];
		if (x < 10)
		{
			ans[l++] = x;
		}
		else
		{
			ans[l++] = x / 10;
			ans[l++] = x % 10;
		}
	}

	for (int i = 0; i < siz; i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans[i];
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
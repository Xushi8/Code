// 2024/04/01 14:36:04
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
int n;

vector<int> ans;
vector<int> chezhan;
int cnt = 0;
bool vis[N];

void dfs(int deep)
{
	if (cnt == 20)
	{
		exit(0);
	}
	
	if (deep == n)
	{
		cnt++;
		for (auto x : ans)
			cout << x + 1;
		for (int i = chezhan.size() - 1; i >= 0; i--)
			cout << chezhan[i] + 1;
		cout << '\n';
		return;
	}

	
	if (!chezhan.empty())
	{
		ans.emplace_back(chezhan.back());
		chezhan.pop_back();
		dfs(deep);
		chezhan.emplace_back(ans.back());
		ans.pop_back();
	}

	chezhan.emplace_back(deep);
	dfs(deep + 1);
	chezhan.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	dfs(0);

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
// 2024/03/15 17:50:18
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

void dfs(int deep)
{
	if (deep == n)
	{
		for (auto x : ans)
			cout << x + 1 << ' ';
		cout << '\n';
		return;
	}

	ans.emplace_back(deep);
	dfs(deep + 1);
	ans.pop_back();

	dfs(deep + 1);
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
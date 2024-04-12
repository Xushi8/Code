// 2024/04/09 16:24:40
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

void dfs(int x, int y, int val, int dx, int dy)
{
	if (x == 0)
	{
		x++;
		dx = 1;
		dy = -1;
	}
	else if (y == 0)
	{
		y++;
		dx = -1;
		dy = 1;
	}

	if (x == 20 && y == 20)
	{
		cout << val << endl;
		exit(0);
	}

	dfs(x + dx, y + dy, val + 1, dx, dy);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    dfs(1, 1, 1, -1, 1);
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
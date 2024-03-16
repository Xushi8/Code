// 2024/03/16 15:39:19
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
constexpr int N = 100005;

struct node
{
	size_t deep;
	vector<node> sons;
	
};

void solve()
{
	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
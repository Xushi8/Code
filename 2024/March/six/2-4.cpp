// 2024/04/06 15:02:29
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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		G[i].reserve(k);
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			G[i].emplace_back(x);
        }
	}

	map<int, int> cundang;
	int now = 1;
	for (int i = 0; i < m; i++)
	{
		int op;
		cin >> op;
		if (op == 0)
		{
			int j;
			cin >> j;
			j--;
			now = G[now][j];
		}
		else if (op == 1)
		{
			int j;
			cin >> j;
			cundang[j] = now;
			cout << now << '\n';
		}
		else
		{
			int j;
			cin >> j;
			now = cundang[j];
        }
	}

	cout << now << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
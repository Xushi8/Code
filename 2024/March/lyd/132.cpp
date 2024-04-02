// 2024/04/02 09:03:13
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

	int t = 1;
	int n;
	while (cin >> n && n)
	{
		map<int, int> id;
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			for (int j = 0; j < k; j++)
			{
				int x;
				cin >> x;
				id[x] = i;
			}
		}

		map<int, int> siz;

		cout << "Scenario #" << t++ << '\n';
		queue<int> que_id;
		vector<queue<int>> que(n);
		string op;
		while (cin >> op && op != "STOP")
		{
			if (op == "ENQUEUE")
			{
				int x;
				cin >> x;
				que[id[x]].emplace(x);
				if (++siz[id[x]] == 1)
				{
					que_id.emplace(id[x]);
                }
			}
			else
			{
				auto front_team = que_id.front();
				cout << que[front_team].front() << '\n';
				que[front_team].pop();
				if (--siz[front_team] == 0)
				{
					que_id.pop();
                }
			}
		}
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
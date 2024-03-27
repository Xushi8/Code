// 2024/03/27 12:56:06
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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] *= 10;
	}

	vector<vector<int>> ans(n);

	set<int> erased;

	int tot = 1;
	bool flag = 0;
	while (!flag)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0)
			{
				if (erased.size() + 1 == n)
				{
					ans[i].emplace_back(tot);
					a[i]--;
					tot += 2;
					while (a[i] != 0)
					{
						a[i]--;
						ans[i].emplace_back(tot);
						tot += 2;
					}
					flag = 1;
					break;
				}
				else
				{
					ans[i].emplace_back(tot++);
					if (--a[i] == 0)
					{
						erased.emplace(i);
                    }
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << '#' << i + 1;
		for (int j = 0; j < ans[i].size(); j++)
		{
			if (j != 0 && j % 10 != 0)
				cout << ' ';
			if ((j) % 10 == 0)
			{
				cout << '\n';
            }
			cout << ans[i][j];
		}
		cout << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
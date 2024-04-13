// 2024/04/13 20:05:34
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
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
        }
	}

	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};

	int cnt1 = 0, cnt2 = 0;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!vis[i][j] && a[i][j] > '0')
			{
				cnt1++;
				queue<pii> que;
				que.emplace(i, j);
				bool flag = 0;
				while (!que.empty())
				{
					auto [x, y] = que.front();
					que.pop();
					if (a[x][y] > '1' && !flag)
					{
						flag = 1;
						cnt2++;
                    }
					for (int k = 0; k < 4; k++)
					{
						int tx = x + dx[k];
						int ty = y + dy[k];
						if (0 <= tx && tx < n && 0 <= ty && ty < m && !vis[tx][ty])
						{
							vis[tx][ty] = 1;
							if (a[tx][ty] > '0')
							{
								que.emplace(tx, ty);
                            }
                        }
                    }
                }
            }
        }
	}

	cout << cnt1 << ' ' << cnt2 << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
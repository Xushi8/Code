// 2024/04/13 19:55:26
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
struct A
{
	A() = default;
	int winer, loser;
};

bool dfs(int root, int maxx, vector<A>& jieju)
{
	if (jieju[root].winer < jieju[root].loser)
		return false;
	int l = root * 2 + 1;
	int r = root * 2 + 2;
	if (r >= maxx)
		return true;
	jieju[l].winer = jieju[root].winer;
	jieju[r].winer = jieju[root].loser;

	if (dfs(l, maxx, jieju) && dfs(r, maxx, jieju))
		return true;
	swap(jieju[l].winer, jieju[r].winer);
	return dfs(l, maxx, jieju) && dfs(r, maxx, jieju);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int k;
	cin >> k;
	vector<A> jieju;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= (1 << (k - i)); j++)
		{
			A tmp;
			cin >> tmp.loser;
			jieju.emplace_back(tmp);
        }
	}

	reverse(jieju.begin(), jieju.end());
	cin >> jieju.front().winer;

	int maxx = (1 << k) - 1;
	bool flag = dfs(0, maxx, jieju);
	if (flag)
	{
		reverse(jieju.begin(), jieju.end());
		for (int i = 0; i < (1 << (k - 1)); i++)
		{
			if (i != 0)
				cout << ' ';
			cout << jieju[i].winer << ' ' << jieju[i].loser;
        }
	}
	else
	{
		cout << "No Solution";
	}
	cout << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
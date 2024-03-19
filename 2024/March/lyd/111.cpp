// 2024/03/18 21:22:44
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
	int l, r, id;
};

bool operator<(A const& x, A const& y)
{
	return x.l < y.l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
    vector<A> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y, i};
	}

	sort(a.begin(), a.end());

	priority_queue<pii, vector<pii>, greater<>> que;
	vector<int> ans(n);
	que.emplace(a.front().r, 0);
	ans[a.front().id] = 0;
	int tot = 1;
	for (int i = 1; i < n; i++)
	{
		auto [l, r, id] = a[i];
		auto [R, tmp] = que.top();
		que.pop();
		if (R < l)
		{
			que.emplace(r, tmp);
            ans[id] = tmp;
		}
		else
		{
			que.emplace(R, tmp);
			que.emplace(r, tot);
			ans[id] = tot++;
        }
    }

	cout << que.size() << '\n';
	for (auto x : ans)
	{
		cout << x + 1 << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
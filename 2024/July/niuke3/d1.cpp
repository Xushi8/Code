#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <map>
#define RI int
#define CI const int&
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pi;
const int N = 200005;
int n, x[N], y[N], used[N];
vector<pi> ans;
map<int, int> rst;
int main()
{
	RI i;
	priority_queue<pi> hp;
	for (scanf("%d", &n), i = 1; i <= n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		if (x[i] == y[i]) ++rst[x[i]], used[i] = 1;
	}
	for (auto [val, cnt] : rst)
		hp.push(pi(cnt, val));
	while (hp.size() >= 2)
	{
		auto [mxc, mxv] = hp.top();
		hp.pop();
		auto [smxc, smxv] = hp.top();
		hp.pop();
		ans.push_back(pi(mxv, mxv));
		ans.push_back(pi(smxv, smxv));
		if (mxc - 1 > 0) hp.push(pi(mxc - 1, mxv));
		if (smxc - 1 > 0) hp.push(pi(smxc - 1, smxv));
	}
	if (hp.size() == 1)
	{
		auto [cnt, val] = hp.top();
		if (ans.empty() || val != ans.back().se)
			ans.push_back(pi(val, val)), --cnt;
		vector<int> vec;
		for (i = 1; i <= n; ++i)
			if (!used[i] && val != x[i] && val != y[i]) vec.push_back(i);
		if ((int)vec.size() < cnt) return puts("No"), 0;
		for (i = 1; i <= cnt; ++i)
		{
			int id = vec.back();
			vec.pop_back();
			used[id] = 1;
			ans.push_back(pi(x[id], y[id]));
			ans.push_back(pi(val, val));
		}
	}
	for (i = 1; i <= n; ++i)
		if (!used[i])
		{
			if (!ans.empty() && ans.back().se == x[i]) swap(x[i], y[i]);
			ans.push_back(pi(x[i], y[i]));
		}
	puts("Yes");
	for (auto [x, y] : ans)
		printf("%d %d\n", x, y);
	return 0;
}

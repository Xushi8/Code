// 2024/03/23 19:26:54
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
	int val, pre, next;
	int index, id;
};

A a[N];

int main()
{
	int id, val, next;
	// cin >> id;
	scanf("%d", &id);

	a[id].index = 1;

	int be = id;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &id, &val, &next);
		a[id].val = val;
		a[id].next = next;
		a[id].id = id;
		a[next].pre = id;
	}

	int now = be, tot = 1;
	while (a[now].next != -1)
	{
		a[now].index = tot++;
		now = a[now].next;
	}

	int ed = now;
	vector<A> ans;
	ans.reserve(n);

	for(int t = 0; t < n / 2; t++)
	{
		ans.emplace_back(a[ed]);
		ans.emplace_back(a[be]);
		be = a[be].next;
		ed = a[ed].pre;
	}
	if (n & 1)
	{
		ans.emplace_back(a[be]);
    }

	
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%05d %d ", ans[i].id, ans[i].val);
		if (i + 1 == ans.size())
		{
			printf("-1\n");
		}
		else
		{
			printf("%05d\n", ans[i + 1].id);
        }
    }

	
	
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
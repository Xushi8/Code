// 2024/03/20 14:47:25
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
constexpr int N = 100;

struct node
{
	node() = default;
	node(int _val, int _deep = 0, node* a = nullptr, node* b = nullptr) :
		val(_val), deep(_deep), l(a), r(b) {}

	int val;
	int deep;
	node *l, *r;

	void insert(int x)
	{
		if (x > val)
		{
			if (l == nullptr)
				l = new node(x, deep + 1);
			else
				l->insert(x);
		}
		else
		{
			if (r == nullptr)
				r = new node(x, deep + 1);
			else
				r->insert(x);
		}
	}
};

// bool func(node* root, int tar_deep, int& cnt)
// {
// 	if (root == nullptr)
// 		return false;
// 	if (cnt == 0)
// 		return true;
// 	if (root->deep < tar_deep)
// 	{
// 		return func(root->l, tar_deep, cnt) && func(root->r, tar_deep, cnt);
// 	}

// 	if (root->l == nullptr && root->r != nullptr)
// 		return false;

// 	if (root->l != nullptr)
// 		cnt--;
// 	if (root->r != nullptr)
// 		cnt--;
// 	return true;
// }

int tmp[N];

void func(node* root, int p)
{
	if (root == nullptr)
		return;
	tmp[p] = root->val;
	func(root->l, p * 2 + 1);
	func(root->r, p * 2 + 2);
}

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
	}

	node* root = new node(a.front());

	for (int i = 1; i < n; i++)
	{
		root->insert(a[i]);
	}

	queue<node*> que;
	que.emplace(root);
	vector<int> ans;
	int cnt[100] = {0};
	while (!que.empty())
	{
		auto x = que.front();
		que.pop();
		if (x == nullptr)
			continue;
		cnt[x->deep]++;
		ans.emplace_back(x->val);
		que.emplace(x->l);
		que.emplace(x->r);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans[i];
	}
	cout << '\n';

	// bool flag = 1;
	// int tot = 1;
	// for (int i = 0; i < 100; i++)
	// {
	// 	if (cnt[i] != tot)
	// 	{
	// 		if (cnt[i + 1] != 0)
	// 			flag = 0;
	// 		else
	// 		{
	// 			int cnt = n - tot / 2;
	// 			bool res = func(root, i - 1, cnt);
	// 			if (!res)
	// 				flag = 0;
	// 		}
	// 		break;
	// 	}
	// 	tot *= 2;
	// }

	bool flag = 1;
	memset(tmp, -1, sizeof(tmp));
	func(root, 0);
	for (int i = 0; i < n; i++)
	{
		if (tmp[i] == -1)
			flag = 0;
	}


	cout << (flag ? "YES" : "NO") << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
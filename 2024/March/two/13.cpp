// 2024/03/23 20:07:11
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

struct node
{
	int m_val, m_deep;
	node *m_l, *m_r;
	node(int val, int deep, node* l = nullptr, node* r = nullptr) :
		m_val(val),
		m_deep(deep),
		m_l(l),
		m_r(r)
	{
	}
	void insert(int val, int deep)
	{
		if (val > m_val)
		{
			if (m_r == nullptr)
				m_r = new node(val, deep + 1);
			else
				m_r->insert(val, deep + 1);
		}
		else
		{
			if (m_l == nullptr)
				m_l = new node(val, deep + 1);
			else
				m_l->insert(val, deep + 1);
		}
	}
};

bool func_root(node* root, int x)
{
	return root->m_val == x;
}

void func_siblings(node* root, int x, int y, bool& flag)
{
	if (root == nullptr)
		return;

	if (root->m_l != nullptr && root->m_r != nullptr)
	{
		if ((root->m_l->m_val == x && root->m_r->m_val == y) || (root->m_l->m_val == y && root->m_r->m_val == x))
		{
			flag = 1;
		}
	}

	func_siblings(root->m_l, x, y, flag);
	func_siblings(root->m_r, x, y, flag);
}

void func_parent(node* root, int x, int y, bool& flag)
{
	if (root == nullptr)
		return;
	if (root->m_val == x)
	{
		if ((root->m_l != nullptr && root->m_l->m_val == y) || (root->m_r != nullptr && root->m_r->m_val == y))
			flag = 1;
	}

	if (root->m_l != nullptr)
		func_parent(root->m_l, x, y, flag);
	if (root->m_r != nullptr)
		func_parent(root->m_r, x, y, flag);
}

void func_left(node* root, int x, int y, bool& flag)
{
	if (root == nullptr)
		return;
	if (root->m_val == y)
	{
		if ((root->m_l != nullptr && root->m_l->m_val == x))
			flag = 1;
	}

	if (root->m_l != nullptr)
		func_left(root->m_l, x, y, flag);
	if (root->m_r != nullptr)
		func_left(root->m_r, x, y, flag);
}

void func_right(node* root, int x, int y, bool& flag)
{
	if (root == nullptr)
		return;
	if (root->m_val == y)
	{
		if ((root->m_r != nullptr && root->m_r->m_val == x))
			flag = 1;
	}

	if (root->m_l != nullptr)
		func_right(root->m_l, x, y, flag);
	if (root->m_r != nullptr)
		func_right(root->m_r, x, y, flag);
}

void func_level(node* root, int x, int y, int& dx, int& dy)
{
	if (root == nullptr)
		return;
	if (root->m_val == x)
		dx = root->m_deep;
	if (root->m_val == y)
		dy = root->m_deep;
	func_level(root->m_l, x, y, dx, dy);
	func_level(root->m_r, x, y, dx, dy);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int x;
	cin >> x;
	node* root = new node(x, 0);
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		root->insert(x, 0);
	}

	int m;
	cin >> m;
	cin.ignore(1111, '\n');
	string s;
	for (int i = 0; i < m; i++)
	{
		getline(cin, s);
		bool res = 0;
		if (s.find("root") != -1)
		{
			int ch;
			int x = 0;
			for (auto ch : s)
			{
				if (ch == ' ')
				{
					break;
				}
				x = x * 10 + ch - '0';
			}
			res = func_root(root, x);
		}
		else if (s.find("sibling") != -1)
		{
			int ch;
			int x = 0;
			int siz;
			for (auto& ch : s)
			{
				if (ch == ' ')
				{
					siz = &ch - s.data();
					break;
				}
				x = x * 10 + ch - '0';
			}
			int y = 0;
			siz += 5;
			for (int i = siz; i < s.size(); i++)
			{
				ch = s[i];
				if (ch == ' ')
					break;
				y = y * 10 + ch - '0';
			}
			func_siblings(root, x, y, res);
		}
		else if (s.find("parent") != -1)
		{
			int ch;
			int x = 0;
			for (auto ch : s)
			{
				if (ch == ' ')
				{
					break;
				}
				x = x * 10 + ch - '0';
			}
			int y = 0;
			int t = 1;
			reverse(s.begin(), s.end());
			for (auto ch : s)
			{
				if (ch == ' ')
					break;
				y += (ch - '0') * t;
				t *= 10;
			}
			func_parent(root, x, y, res);
		}
		else if (s.find("left") != -1)
		{
			int ch;
			int x = 0;
			for (auto ch : s)
			{
				if (ch == ' ')
				{
					break;
				}
				x = x * 10 + ch - '0';
			}
			int y = 0;
			int t = 1;
			reverse(s.begin(), s.end());
			for (auto ch : s)
			{
				if (ch == ' ')
					break;
				y += (ch - '0') * t;
				t *= 10;
			}
			func_left(root, x, y , res);
		}
		else if (s.find("right") != -1)
		{
			int ch;
			int x = 0;
			for (auto ch : s)
			{
				if (ch == ' ')
				{
					break;
				}
				x = x * 10 + ch - '0';
			}
			int y = 0;
			int t = 1;
			reverse(s.begin(), s.end());
			for (auto ch : s)
			{
				if (ch == ' ')
					break;
				y += (ch - '0') * t;
				t *= 10;
			}
			func_right(root, x, y, res);
		}
		else
		{
			int ch;
			int x = 0;
			int siz;
			for (auto& ch : s)
			{
				if (ch == ' ')
				{
					siz = &ch - s.data();
					break;
				}
				x = x * 10 + ch - '0';
			}
			int y = 0;
			siz += 5;
			for (int i = siz; i < s.size(); i++)
			{
				ch = s[i];
				if (ch == ' ')
					break;
				y = y * 10 + ch - '0';
			}

			int dx, dy;
			func_level(root, x, y, dx, dy);
			res = dx == dy;
		}

		cout << (res ? "Yes" : "No") << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
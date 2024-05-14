#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int f(string s)
{
	int res = 0;
	for (int i = 0; i < 9; i++)
	{
		if (s[i] == 'x')
			continue;
		int t = s[i] - '1';
		res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
	}
	return res;
}

void solve(string start)
{
	string ed = "12345678x";
	unordered_map<string, int> dis;
	unordered_map<string, pair<string, char>> last;
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> que;
	que.emplace(f(start), start);
	dis[start] = 0;
	constexpr int dx[4] = {0, 0, -1, 1};
	constexpr int dy[4] = {-1, 1, 0, 0};
	char ope[] = "lrud";
	while (!que.empty())
	{
		auto [now_dis, u] = que.top();
		que.pop();
		if (u == ed)
		{
			break;
		}

		int x, y;
		for (int i = 0; i < 9; i++)
		{
			if (u[i] == 'x')
			{
				x = i / 3;
				y = i % 3;
				break;
			}
		}

		for (int k = 0; k < 4; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (!(0 <= tx && tx < 3 && 0 <= ty && ty < 3))
				continue;

			auto v = u;
			swap(v[x * 3 + y], v[tx * 3 + ty]);
			if (!dis.count(v) || dis[v] > now_dis + 1)
			{
				dis[v] = now_dis + 1;
				que.emplace(f(v) + dis[v], v);
				last[v] = {u, ope[k]};
			}
		}
	}

	string ans;
	while (ed != start)
	{
		// cout << ed << '\n';
		ans += last[ed].second;
		ed = last[ed].first;
	}
	reverse(ans.begin(), ans.end());
	// for (auto const& [x, y] : last)
	// {
	// 	// cout << x << '\n';
	// 	if (x == "12345678x")
	// 	{
	// 		cout << x << ' ' << "!!!!!!!\n";
	// 	}
	// 	if (x == start)
	// 	{
	// 		cout << x << ' ' << "!!!!!!!\n";
	// 	}
	// }
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, x;
	char ch;
	while (cin >> ch)
	{
		s += ch;
		if (ch != 'x')
			x += ch;
	}

	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (x[i] > x[j])
				cnt++;
		}
	}

	if (cnt % 2 != 0)
		cout << "unsolvable\n";
	else
		solve(s);

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}

// int f(array<array<int, 3>, 3> const& val)
// {
// 	int res = 0;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 3; j++)
// 		{
// 			switch (val[i][j])
// 			{
// 			case 1:
// 				res += abs(i - 0) + abs(j - 0);
// 				break;
// 			case 2:
// 				res += abs(i - 0) + abs(j - 1);
// 				break;
// 			case 3:
// 				res += abs(i - 0) + abs(j - 2);
// 				break;
// 			case 4:
// 				res += abs(i - 1) + abs(j - 0);
// 				break;
// 			case 5:
// 				res += abs(i - 1) + abs(j - 1);
// 				break;
// 			case 6:
// 				res += abs(i - 1) + abs(j - 2);
// 				break;
// 			case 7:
// 				res += abs(i - 2) + abs(j - 0);
// 				break;
// 			case 8:
// 				res += abs(i - 2) + abs(j - 1);
// 				break;
// 			case 0:
// 				res += abs(i - 2) + abs(j - 2);
// 				break;
// 			default:
// 				__builtin_unreachable();
// 			}
// 		}
// 	}
// 	return res;
// }

// struct A
// {
// 	array<array<int, 3>, 3> val;
// 	vector<int> path;
// };

// struct cmp
// {
// 	bool operator()(A const& x, A const& y)
// 	{
// 		return x.path.size() + f(x.val) > y.path.size() + f(y.val);
// 	}
// };

// void solve(array<array<int, 3>, 3> a)
// {
// 	set<array<array<int, 3>, 3>> st;
// 	constexpr array<array<int, 3>, 3> ed = {
// 		{{1, 2, 3},
// 			{4, 5, 6},
// 			{7, 8, 0}}};

// 	constexpr int dx[4] = {0, 0, -1, 1};
// 	constexpr int dy[4] = {-1, 1, 0, 0};
// 	priority_queue<A, vector<A>, cmp> que;
// 	que.push({a, {}});
// 	A res = {a, {}};
// 	while (!que.empty())
// 	{
// 		auto u = que.top();
// 		que.pop();
// 		if (u.val == ed)
// 		{
// 			res = std::move(u);
// 			break;
// 		}
// 		int x, y;
// 		for (int i = 0; i < 3; i++)
// 		{
// 			for (int j = 0; j < 3; j++)
// 			{
// 				if (u.val[i][j] == 0)
// 				{
// 					x = i;
// 					y = j;
// 					goto out;
// 				}
// 			}
// 		}
// 	out:

// 		// for (int i = 0; i < 3; i++)
// 		// {
// 		// 	for (int j = 0; j < 3; j++)
// 		// 	{
// 		// 		cout << u.val[i][j] << ' ';
// 		// 	}
// 		// 	cout << '\n';
// 		// }
// 		// cout << '\n';

// 		const size_t n = que.size();
// 		// if (n > 400000)
// 			break;

// 		for (int k = 0; k < 4; k++)
// 		{
// 			int tx = x + dx[k];
// 			int ty = y + dy[k];
// 			if (0 <= tx && tx < 3 && 0 <= ty && ty < 3)
// 			{
// 				auto t = u;
// 				swap(t.val[x][y], t.val[tx][ty]);
// 				t.path.emplace_back(k);
// 				que.emplace(std::move(t));
// 			}
// 		}
// 	}

// 	for (auto x : res.path)
// 	{
// 		if (x == 0)
// 		{
// 			cout << 'l';
// 		}
// 		else if (x == 1)
// 		{
// 			cout << 'r';
// 		}
// 		else if (x == 2)
// 		{
// 			cout << 'u';
// 		}
// 		else
// 		{
// 			cout << 'd';
// 		}
// 	}
// }
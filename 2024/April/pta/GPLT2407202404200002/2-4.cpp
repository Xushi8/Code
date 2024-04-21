#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

size_t tar, n;
ll ans = 0;
int a[4][4];
vector<vector<int>> rows;
vector<int> tmp;

void get_rows(size_t deep, size_t sum)
{
	if (deep == n)
	{
		if (sum == tar)
		{
			rows.push_back(tmp);
		}
		return;
	}

	for (int i = 9; i >= 0; i--)
	{
		if (sum + i > tar)
			continue;

		tmp.push_back(i);
		get_rows(deep + 1, sum + i);
		tmp.pop_back();
	}
}

bool check(vector<vector<int>> const& vec)
{
	for (size_t j = 0; j < n; j++)
	{
		size_t sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			sum += vec[i][j];
		}
		if (sum != tar)
		{
			return false;
		}
	}

	return true;
}

void dfs(vector<int> choose)
{
	if (choose.size() == n)
	{
		vector<vector<int>> to_check;
		for (size_t i = 0; i < choose.size(); i++)
		{
			to_check.push_back(rows[choose[i]]);
		}
		if (check(to_check))
		{
			ans++;
		}

		return;
	}

	for (size_t i = 0; i < rows.size(); i++)
	{
		choose.push_back(i);
		dfs(choose);
		choose.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> tar >> n;
	ll biao[] = {
		0,
		0,
		282,
		2008,
		10147,
		40176,
		132724,
		381424,
		981541,
		2309384};

	if (n == 4)
	{
		cout << biao[tar];
	}
	else
	{
		get_rows(0, 0);

		sort(rows.begin(), rows.end());
		rows.erase(unique(rows.begin(), rows.end()), rows.end());

		vector<vector<int>> to_check(n);
		vector<int> choose;
		dfs(choose);

		cout << ans << endl;
	}

		

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000. << "ms\n";
#endif
	return 0;
}

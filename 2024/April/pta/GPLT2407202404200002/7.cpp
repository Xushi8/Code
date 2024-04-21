#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int L, R;
	cin >> L >> R;
	vector<int> ans;
	int maxn = 0;
	for (int i = L; i < R; i++)
	{
		ll j = i;
		int cnt = 0;
		while (1)
		{
			if (j == 0)
				break;
			stack<int> stk;
			while (j)
			{
				stk.emplace(j % 10);
				j /= 10;
			}
			if (stk.size() == 1)
			{
				break;
			}

			cnt++;
			ll mul = 1;
			while (!stk.empty())
			{
				auto x = stk.top();
				stk.pop();
				mul *= x;
			}
			j = mul;

			if (i == 688)
			{
				// cerr << j << ' ' << cnt << endl;
			}
		}

		if (cnt > maxn)
		{
			ans.clear();
			ans.emplace_back(i);
			maxn = cnt;
		}
		else if (cnt == maxn)
		{
			ans.emplace_back(i);
		}
	}

	cout << maxn << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans[i];
	}

	return 0;
}

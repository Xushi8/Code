// 2024/04/03 19:21:13
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
	string name, id;
	bool status;
	int sec;
	A(string name_, string id_, bool status_, int sec_)
	{
		name = name_;
		id = id_;
		status = status_;
		sec = sec_;
    }
};

bool cmp(A const& x, A const& y)
{
	return x.sec < y.sec;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int D, P;
	cin >> D >> P;
	vector<vector<A>> a(D);
	vector<int> num(D);
	for (int i = 0; i < D; i++)
	{
		int t, s;
		cin >> t >> s;
		num[i] = s;
		for (int j = 0; j < t; j++)
		{
			string name, id;
			bool status;
			char ch;
			int h, m;
			cin >> name >> id >> status;
			cin >> h >> ch >> m;
			a[i].emplace_back(name, id, status, h * 60 + m);
		}
		stable_sort(a[i].begin(), a[i].end(), cmp);
	}

	map<string, vector<int>> mp;

	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			A per = a[i][j];
			mp[per.id].emplace_back(i);
		}
	}

	set<string> st;

	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			A per = a[i][j];
			if (per.id.size() == 18)
			{
				auto& vec = mp[per.id];
				for (int k = 0; k < vec.size(); k++)
				{
					if (vec[k] == i)
					{
						bool flag = 1;
						if (k == 0 || vec[k] - vec[k - 1] >= P + 1)
						{
							if (num[i] > 0)
							{
								flag = 0;
								num[i]--;
								cout << per.name << ' ' << per.id;
								cout << endl;
								st.emplace(per.id);
							}
						}
						if (flag)
							vec.erase(vec.begin() + k);
						break;
					}
				}
			}
		}
	}

	vector<pair<string, string>> ans;
	set<pair<string, string>> tmp;
	for (int i = 0; i < D; i++)
	{
		for (auto per : a[i])
		{
			if (st.count(per.id) && per.status == 1)
			{
				if (!tmp.count(make_pair(per.name, per.id)))
					ans.push_back(make_pair(per.name, per.id));
				tmp.insert(make_pair(per.name, per.id));
			}
        }
    }

	for (auto& [x, y] : ans)
	{
		cout << x << ' ' << y << '\n';
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
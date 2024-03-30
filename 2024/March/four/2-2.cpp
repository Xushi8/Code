// // 2024/03/30 19:42:47
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// #include <numeric>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// constexpr int N = 1000005;

// struct node
// {
// 	string ming, xing;
// 	bool sex;

// 	node() = default;
// 	node(string ming1, string xing1, bool sex1)
// 	{
// 		ming = ming1;
// 		xing = xing1;
// 		sex = sex1;
// 	}
// };

// bool operator<(node const& x, node const& y)
// {
// 	// if (x.xing != y.xing)
// 	// return x.xing < y.xing;
// 	// else
// 	// return x.ming < y.ming;

// 	if (x.ming != y.ming)
// 		return x.ming < y.ming;
// 	else
// 		return x.xing < y.xing;
// }

// bool get_sex(string& xing)
// {
// 	if (xing.back() == 'm')
// 	{
// 		xing.pop_back();
// 		return 1;
// 	}
// 	else if (xing.back() == 'f')
// 	{
// 		xing.pop_back();
// 		return 0;
// 	}
// 	else if (xing.back() == 'n')
// 	{
// 		xing.erase(xing.end() - 4, xing.end());
// 		return 1;
// 	}
// 	else
// 	{
// 		xing.erase(xing.end() - 7, xing.end());
// 		return 0;
// 	}
// }

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int n;
// 	cin >> n;
// 	vector<node> arr(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		string ming, xing;
// 		cin >> ming >> xing;
// 		bool sex = get_sex(xing);
// 		arr[i].ming = ming;
// 		arr[i].sex = sex;
// 		arr[i].xing = xing;
// 	}

// 	sort(arr.begin(), arr.end());

// 	map<string, string> par;
// 	for (auto [ming, xing, sex] : arr)
// 	{
// 		par[ming] = xing;
// 	}

// 	int q;
// 	cin >> q;
// 	while (q--)
// 	{
// 		string ming1, xing1, ming2, xing2;
// 		cin >> ming1 >> xing1 >> ming2 >> xing2;
// 		node a, b;
// 		auto it = lower_bound(arr.begin(), arr.end(), node{ming1, xing1, 0});

// 		if (it == arr.end() || it->ming != ming1 || it->xing != xing1)
// 		{
// 			cout << "NA" << '\n';
// 			continue;
// 		}
// 		a = *it;

// 		it = lower_bound(arr.begin(), arr.end(), node{ming2, xing2, 0});
// 		if (it == arr.end() || it->ming != ming2 || it->xing != xing2)
// 		{
// 			cout << "NA" << '\n';
// 			continue;
// 		}
// 		b = *it;

// 		if (a.sex == b.sex)
// 		{
// 			cout << "Whatever" << '\n';
// 		}
// 		else
// 		{
// 			set<string> zuxian;
// 			string now_par = a.ming;
// 			for (int i = 0; i < 4; i++)
// 			{
// 				now_par = par[now_par];
// 				zuxian.emplace(now_par);
// 			}

// 			now_par = b.ming;
// 			bool flag = 1;
// 			for (int i = 0; i < 4; i++)
// 			{
// 				now_par = par[now_par];
// 				if (zuxian.count(now_par) != 0)
// 				{
// 					flag = 0;
// 					break;
// 				}
// 			}

// 			cout << (flag ? "Yes" : "No") << '\n';
// 		}
// 	}

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/03/30 20:55:09
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

struct person
{
	string name, par_name;
	bool sex;
};

bool operator<(person const& x, person const& y)
{
	return x.name < y.name;
}

struct person_nosex
{
	string name, par_name;
};

bool operator<(person_nosex const& x, person_nosex const& y)
{
	return x.name < y.name;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, string> par;
	set<person> persons;
	set<person_nosex> persons_nosex;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, xing;
		cin >> name >> xing;
		bool sex;
		if (xing.back() == 'm')
		{
			xing.pop_back();
			sex = 1;
		}
		else if (xing.back() == 'f')
		{
			xing.pop_back();
			sex = 0;
		}
		else if (xing.back() == 'n')
		{
			xing.erase(xing.end() - 4, xing.end());
			sex = 1;
		}
		else
		{
			xing.erase(xing.end() - 7, xing.end());
			sex = 0;
		}

		persons.insert({name, xing, sex});
		persons_nosex.insert({name, xing});

		par[name] = {xing};
	}

	int q;
	cin >> q;
	while (q--)
	{
		person_nosex a, b;
		cin >> a.name >> a.par_name >> b.par_name >> b.par_name;
		if (persons_nosex.count(a) == 0 || persons_nosex.count(b) == 0)
		{
			cout << "NA" << '\n';
		}
		else
		{
			if ((persons.count({a.par_name, a.par_name, 0}) == 1 && persons.count({b.par_name, b.par_name, 0})) || (persons.count({a.par_name, a.par_name, 1}) == 1 && persons.count({b.par_name, b.par_name, 1})))
				cout << "Whatever" << '\n';
			else
			{
				set<string> st;
				string now_par = a.name;
				for (int i = 0; i < 4; i++)
				{
					now_par = par[now_par];
					st.insert(now_par);
				}

				now_par = b.name;
				bool flag = 1;
				for (int i = 0; i < 4; i++)
				{
					now_par = par[now_par];
					if (st.count(now_par) == 1)
					{
						flag = 0;
						break;
					}
				}
				cout << (flag ? "Yes" : "No") << '\n';
			}
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
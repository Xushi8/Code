// 2024/04/22 14:12:17
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a)
		cin >> x;
	for (auto& x : b)
		cin >> x;

	priority_queue<int, vector<int>, greater<>> less_que;
	priority_queue<int, vector<int>, less<>> big_que;

	int index = 1;
	int tot = 0;
	for (auto x : b)
	{
		while (big_que.size() + less_que.size() < x)
		{
			int y = a[tot++];
			if (less_que.empty() || y >= less_que.top())
				less_que.emplace(y);
			else
				big_que.emplace(y);
		}

		while (big_que.size() > index)
		{
			less_que.emplace(big_que.top());
			big_que.pop();
		}

		while (big_que.size() < index)
		{
			big_que.emplace(less_que.top());
			less_que.pop();
		}

		cout << big_que.top() << '\n';
		index++;
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
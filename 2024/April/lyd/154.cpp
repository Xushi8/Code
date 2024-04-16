// 2024/04/15 18:46:56
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

struct max_que
{
	deque<int> que;
	void emplace(int x)
	{
		while (!que.empty() && que.back() < x)
			que.pop_back();
		que.emplace_back(x);
	}

	void pop(int x)
	{
		if (que.front() == x)
		{
			que.pop_front();
        }
	}

	int top()
	{
		return que.front();
    }
};

struct min_que
{
	deque<int> que;
	void emplace(int x)
	{
		while (!que.empty() && que.back() > x)
			que.pop_back();
		que.emplace_back(x);
	}

	void pop(int x)
	{
		if (que.front() == x)
		{
			que.pop_front();
		}
	}

	int top()
	{
		return que.front();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	max_que maxx;
	min_que minn;
	for (int i = 0; i < k; i++)
	{
		minn.emplace(a[i]);
	}
	for (int i = k; i < n; i++)
	{
		cout << minn.top() << ' ';
		minn.emplace(a[i]);
		minn.pop(a[i - k]);
	}
	cout << minn.top() << '\n';

	for (int i = 0; i < k; i++)
	{
		maxx.emplace(a[i]);
	}
	for (int i = k; i < n; i++)
	{
		cout << maxx.top() << ' ';
		maxx.emplace(a[i]);
		maxx.pop(a[i - k]);
	}
	cout << maxx.top() << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
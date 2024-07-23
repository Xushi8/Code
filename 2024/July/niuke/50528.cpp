// 2024/07/23 20:39:54
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}

struct less_que
{
	void push(int x)
	{
		while (!m_que.empty() && m_que.back() > x)
			m_que.pop_back();
		m_que.emplace_back(x);
	}

	void pop(int x)
	{
		if (m_que.front() == x)
		{
			m_que.pop_front();
		}
	}

	int front()
	{
		return m_que.front();
	}

private:
	deque<int> m_que;
};

struct greater_que
{
	void push(int x)
	{
		while (!m_que.empty() && m_que.back() < x)
			m_que.pop_back();
		m_que.emplace_back(x);
	}

	void pop(int x)
	{
		if (m_que.front() == x)
		{
			m_que.pop_front();
		}
	}

	int front()
	{
		return m_que.front();
	}

private:
	deque<int> m_que;
};

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
    }
	less_que q1;
	greater_que q2;
	for (int i = 0; i < k; i++)
	{
		q1.push(a[i]);
		q2.push(a[i]);
	}

	for (int i = k; i < n; i++)
	{
		cout << q1.front() << ' ';
		q1.pop(a[i - k]);
		q1.push(a[i]);
	}
	cout << q1.front() << '\n';

	for (int i = k; i < n; i++)
	{
		cout << q2.front() << ' ';
		q2.pop(a[i - k]);
		q2.push(a[i]);
	}
	cout << q2.front() << '\n';
}
// 2024/05/30 14:19:52
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> sorted = arr;

	int siz = sqrt(n);
	int tot = (n + siz - 1) / siz;
	vector<int> L(tot), R(tot), add(tot);
	vector<int> be(n);

	auto cg = [&](int index)
	{
		for (int i = L[index]; i < R[index]; i++)
		{
			sorted[i] = arr[i];
		}
		sort(sorted.begin() + L[index], sorted.begin() + R[index]);
    };
	
	for (int index = 0; index < tot; index++)
	{
		L[index] = index * siz;
		R[index] = (index + 1) * siz;
		R[index] = min(R[index], n);
		for (int j = L[index]; j < R[index]; j++)
		{
			be[j] = index;
		}

		sort(sorted.begin() + L[index], sorted.begin() + R[index]);
	}

	while (q--)
	{
		char op;
		int l, r, x;
		cin >> op >> l >> r >> x;
		l--;

		if (op == 'M')
		{
			for (int i = be[l] + 1; i < be[r - 1]; i++)
			{
				add[i] += x;
			}

			if (be[l] != be[r - 1])
			{
				for (int i = l; i < R[be[l]]; i++)
				{
					arr[i] += x;
				}
				cg(be[l]);

				for (int i = L[be[r - 1]]; i < r; i++)
				{
					arr[i] += x;
				}
				cg(be[r - 1]);
			}
			else
			{
				for (int i = l; i < r; i++)
				{
					arr[i] += x;
				}
				cg(be[l]);
            }
		}
		else
		{
			int ans = 0;

			for (int index = be[l] + 1; index < be[r - 1]; index++)
			{
				auto it = lower_bound(sorted.begin() + L[index], sorted.begin() + R[index], x - add[index]);
				ans += sorted.begin() + R[index] - it;
			}

			if (be[l] != be[r - 1])
			{
				for (int i = l; i < R[be[l]]; i++)
				{
					if (arr[i] >= x - add[be[l]])
						ans++;
				}

				for (int i = L[be[r - 1]]; i < r; i++)
				{
					if (arr[i] >= x - add[be[r - 1]])
						ans++;
				}
			}
			else
			{
				for (int i = l; i < r; i++)
				{
					if (arr[i] >= x - add[be[l]])
						ans++;
                }
            }

			cout << ans << '\n';
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
// 2023/08/08 15:03:29
#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
using i64 = int64_t;

int arr[N];
i64 d[4 * N], b[4 * N], k[4 * N];
int mod = 1;

void build(int l, int r, int p)
{
	if (l == r)
	{
		d[p] = arr[l];
		return;
	}

	int mid = l + (r - l) / 2;
	build(l, mid, p * 2);
	build(mid + 1, r, p * 2 + 1);
	d[p] = d[p * 2] + d[p * 2 + 1];
	d[p] %= mod;
}

void mul_num(int l, int r, int nl, int nr, i64 mul_val, int p)
{
	if (l <= nl && nr <= r)
	{
		d[p] *= mul_val;
		b[p] *= mul_val;
		k[p] *= mul_val;

		d[p] %= mod;
		b[p] %= mod;
		k[p] %= mod;
		return;
	}

	int mid = nl + (nr - nl) / 2;
	if (k[p] != 1)
	{
		d[p * 2] *= k[p];
		d[p * 2 + 1] *= k[p];
		b[p * 2] *= k[p];
		b[p * 2 + 1] *= k[p];
		k[p * 2] *= k[p];
		k[p * 2 + 1] *= k[p];

		d[p * 2] %= mod;
		d[p * 2 + 1] %= mod;
		b[p * 2] %= mod;
		b[p * 2 + 1] %= mod;
		k[p * 2] %= mod;
		k[p * 2 + 1] %= mod;

		k[p] = 1;
	}

	if (b[p] != 0)
	{
		d[p * 2] += b[p] * (mid - nl + 1);
		b[p * 2] += b[p];
		d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
		b[p * 2 + 1] += b[p];

		d[p * 2] %= mod;
		b[p * 2] %= mod;
		d[p * 2 + 1] %= mod;
		b[p * 2 + 1] %= mod;

		b[p] = 0;
	}

	if (l <= mid)
		mul_num(l, r, nl, mid, mul_val, p * 2);
	if (mid + 1 <= r)
		mul_num(l, r, mid + 1, nr, mul_val, p * 2 + 1);

	d[p] = d[p * 2] + d[p * 2 + 1];
	d[p] %= mod;
}

void add_num(int l, int r, int nl, int nr, i64 add_val, int p)
{
	if (l <= nl && nr <= r)
	{
		d[p] += add_val * (nr - nl + 1);
		b[p] += add_val;

		d[p] %= mod;
		b[p] %= mod;
		return;
	}

	int mid = nl + (nr - nl) / 2;
	if (k[p] != 1)
	{
		d[p * 2] *= k[p];
		d[p * 2 + 1] *= k[p];
		b[p * 2] *= k[p];
		b[p * 2 + 1] *= k[p];
		k[p * 2] *= k[p];
		k[p * 2 + 1] *= k[p];

		d[p * 2] %= mod;
		d[p * 2 + 1] %= mod;
		b[p * 2] %= mod;
		b[p * 2 + 1] %= mod;
		k[p * 2] %= mod;
		k[p * 2 + 1] %= mod;

		k[p] = 1;
	}

	if (b[p] != 0)
	{
		d[p * 2] += b[p] * (mid - nl + 1);
		b[p * 2] += b[p];
		d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
		b[p * 2 + 1] += b[p];

		d[p * 2] %= mod;
		b[p * 2] %= mod;
		d[p * 2 + 1] %= mod;
		b[p * 2 + 1] %= mod;

		b[p] = 0;
	}

	if (l <= mid)
		add_num(l, r, nl, mid, add_val, p * 2);
	if (mid + 1 <= r)
		add_num(l, r, mid + 1, nr, add_val, p * 2 + 1);

	d[p] = d[p * 2] + d[p * 2 + 1];
	d[p] %= mod;
}

i64 query(int l, int r, int nl, int nr, int p)
{
	if (l <= nl && nr <= r)
	{
		return d[p];
	}

	int mid = nl + (nr - nl) / 2;
	if (k[p] != 1)
	{
		d[p * 2] *= k[p];
		d[p * 2 + 1] *= k[p];
		b[p * 2] *= k[p];
		b[p * 2 + 1] *= k[p];
		k[p * 2] *= k[p];
		k[p * 2 + 1] *= k[p];

		d[p * 2] %= mod;
		d[p * 2 + 1] %= mod;
		b[p * 2] %= mod;
		b[p * 2 + 1] %= mod;
		k[p * 2] %= mod;
		k[p * 2 + 1] %= mod;

		k[p] = 1;
	}

	if (b[p] != 0)
	{
		d[p * 2] += b[p] * (mid - nl + 1);
		b[p * 2] += b[p];
		d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
		b[p * 2 + 1] += b[p];

		d[p * 2] %= mod;
		b[p * 2] %= mod;
		d[p * 2 + 1] %= mod;
		b[p * 2 + 1] %= mod;

		b[p] = 0;
	}

	i64 sum = 0;
	if (l <= mid)
	{
		sum += query(l, r, nl, mid, p * 2);
		sum %= mod;
	}
	if (mid + 1 <= r)
	{
		sum += query(l, r, mid + 1, nr, p * 2 + 1);
		sum %= mod;
	}

	return sum;
}

int main()
{
	int n, q;
	cin >> n >> q >> mod;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	build(1, n, 1);
	fill(k, k + 4 * N, 1);

	while (q--)
	{
		int op, l, r;
		cin >> op >> l >> r;
		int val;
		if (op == 1)
		{
			cin >> val;
			mul_num(l, r, 1, n, val, 1);
		}
		else if (op == 2)
		{
			cin >> val;
			add_num(l, r, 1, n, val, 1);
		}
		else if (op == 3)
		{
			cout << query(l, r, 1, n, 1) << '\n';
		}
	}
}
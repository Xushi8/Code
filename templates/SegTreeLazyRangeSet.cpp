template <typename T>
class SegTreeLazyRangeSet
{
	vector<T> tree, lazy;
	vector<T>* arr;
	size_t n, root, n4, end;

	void maintain(size_t cl, size_t cr, size_t p)
	{
		size_t cm = cl + (cr - cl) / 2;
		if (cl != cr && lazy[p])
		{
			lazy[p * 2] = lazy[p];
			lazy[p * 2 + 1] = lazy[p];
			tree[p * 2] = lazy[p] * (cm - cl + 1);
			tree[p * 2 + 1] = lazy[p] * (cr - cm);
			lazy[p] = 0;
		}
	}

	T range_sum(size_t l, size_t r, size_t cl, size_t cr, size_t p)
	{
		if (l <= cl && cr <= r) return tree[p];
		size_t m = cl + (cr - cl) / 2;
		T sum = 0;
		maintain(cl, cr, p);
		if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
		if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
		return sum;
	}

	void range_set(size_t l, size_t r, T val, size_t cl, size_t cr, size_t p)
	{
		if (l <= cl && cr <= r)
		{
			lazy[p] = val;
			tree[p] = (cr - cl + 1) * val;
			return;
		}
		size_t m = cl + (cr - cl) / 2;
		maintain(cl, cr, p);
		if (l <= m) range_set(l, r, val, cl, m, p * 2);
		if (r > m) range_set(l, r, val, m + 1, cr, p * 2 + 1);
		tree[p] = tree[p * 2] + tree[p * 2 + 1];
	}

	void build(size_t s, size_t t, size_t p)
	{
		if (s == t)
		{
			tree[p] = (*arr)[s];
			return;
		}
		size_t m = s + (t - s) / 2;
		build(s, m, p * 2);
		build(m + 1, t, p * 2 + 1);
		tree[p] = tree[p * 2] + tree[p * 2 + 1];
	}

public:
	explicit SegTreeLazyRangeSet<T>(vector<T> v)
	{
		n = v.size();
		n4 = n * 4;
		tree = vector<T>(n4, 0);
		lazy = vector<T>(n4, 0);
		arr = &v;
		end = n - 1;
		root = 1;
		build(0, end, 1);
		arr = nullptr;
	}

	void show(size_t p, size_t depth = 0)
	{
		if (p > n4 || tree[p] == 0) return;
		show(p * 2, depth + 1);
		for (size_t i = 0; i < depth; ++i)
			putchar('\t');
		printf("%d:%d\n", tree[p], lazy[p]);
		show(p * 2 + 1, depth + 1);
	}

	T range_sum(size_t l, size_t r)
	{
		return range_sum(l, r, 0, end, root);
	}

	void range_set(size_t l, size_t r, T val)
	{
		range_set(l, r, val, 0, end, root);
	}
};
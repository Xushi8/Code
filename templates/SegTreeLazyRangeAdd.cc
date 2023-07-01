template <typename T>
class SegTreeLazyRangeAdd {
  std::vector<T> tree, lazy;
  std::vector<T> *arr;
  std::size_t n, root, n4, end;

  void maintain(std::size_t cl, std::size_t cr, std::size_t p = 1) {
    std::size_t cm = cl + (cr - cl) / 2;
    if (cl != cr && lazy[p]) {
      lazy[p * 2] += lazy[p];
      lazy[p * 2 + 1] += lazy[p];
      tree[p * 2] += lazy[p] * (cm - cl + 1);
      tree[p * 2 + 1] += lazy[p] * (cr - cm);
      lazy[p] = 0;
    }
  }

  T range_sum(std::size_t l, std::size_t r, std::size_t cl, std::size_t cr, std::size_t p = 1) {
    if (l <= cl && cr <= r) return tree[p];
    std::size_t m = cl + (cr - cl) / 2;
    T sum = 0;
    maintain(cl, cr, p);
    if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
    if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
    return sum;
  }

  void range_add(std::size_t l, std::size_t r, T val, std::size_t cl, std::size_t cr, std::size_t p = 1) {
    if (l <= cl && cr <= r) {
      lazy[p] += val;
      tree[p] += (cr - cl + 1) * val;
      return;
    }
    std::size_t m = cl + (cr - cl) / 2;
    maintain(cl, cr, p);
    if (l <= m) range_add(l, r, val, cl, m, p * 2);
    if (r > m) range_add(l, r, val, m + 1, cr, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  void build(std::size_t s, std::size_t t, std::size_t p = 1) {
    if (s == t) {
      tree[p] = (*arr)[s];
      return;
    }
    std::size_t m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

 public:
  explicit SegTreeLazyRangeAdd<T>(std::vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = std::vector<T>(n4, 0);
    lazy = std::vector<T>(n4, 0);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  void show(std::size_t p, std::size_t depth = 0) {
    if (p > n4 || tree[p] == 0) return;
    show(p * 2, depth + 1);
    for (std::size_t i = 0; i < depth; ++i) putchar('\t');
    printf("%d:%d\n", tree[p], lazy[p]);
    show(p * 2 + 1, depth + 1);
  }

  T range_sum(std::size_t l, std::size_t r) { return range_sum(l, r, 0, end, root); }

  void range_add(std::size_t l, std::size_t r, T val) { range_add(l, r, val, 0, end, root); }
};

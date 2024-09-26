workspaceFolder to fileDirname

## tasks.json
```
{
    "version": "2.0.0",
    "options": {
        "cwd": "${fileDirname}"
    },
    "tasks": [
        {
            "type": "shell",
            "label": "single",
            "command": "/usr/local/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-fsanitize=undefined", // 检测未定义行为
                "${file}",
                "-o",
                "${workspaceFolder}/${fileBasenameNoExtension}.exe",
                // "-O3",
                "-g",
                "-ggdb3",
                "-fno-omit-frame-pointer",
                "-D_GLIBCXX_DEBUG",
                "-D_GLIBCXX_DEBUG_PEDANTIC",
                "-std=c++20",
                "-Wall", // 开启警告
                "-Wextra", // 除Wall外的警告
                "-pedantic", // 使用了扩展语法的地方将产生相应的警告信息
                "-Werror=return-type",
                "-Wshadow", // 当局部变量屏蔽（shadow）已有变量时发出警告
            ]
        }
    ]
}
```

## launch.json
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) 启动",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/${fileBasenameNoExtension}.exe",
            "args": ["<${workspaceFolder}/in.txt"],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "preLaunchTask": "single"
        }
    ]
}
```


## 逆元
```
constexpr int MOD = 1e9 + 7;
int qpow(int64_t a, size_t n)
{
    int64_t b = 1;
    while (n)
    {
        if (n & 1)
            b = b * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return b;
}

std::vector<int> fac, inv, inv_fac;

void init_inv(int n)
{
    fac.resize(n + 1);
    inv.resize(n + 1);
    inv_fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = int64_t(fac[i - 1]) * i % MOD;
    }
    inv_fac.back() = qpow(fac.back(), MOD - 2);
    for (int i = n; i > 0; i--)
    {
        inv_fac[i - 1] = int64_t(inv_fac[i]) * i % MOD;
        inv[i] = inv_fac[i] * fac[i - 1];
    }
}
```

## lca
```
void solve()
{
    int V;
    vector<vector<int>> G(V);

    vector<int> dep(V + 1); // 加一是为了将根节点的par设置为V

    // 这里__lg(V) 不加一会RE, 因为__lg是下取整
    // 必须初始化为-1
    vector<vector<int>> far(V, vector<int>(__lg(V) + 1, -1));

    auto dfs = [&](auto&& self, int u, int par) -> void
    {
        dep[u] = dep[par] + 1;
        far[u][0] = par;
        for (int i = 1; i <= __lg(dep[u]); i++) // 递推
        {
            far[u][i] = far[far[u][i - 1]][i - 1];
        }
        for (auto v : G[u])
        {
            if (v == par)
                continue;
            self(self, v, u);
        }
    };

    auto lca = [&](int x, int y)
    {
        if (dep[x] < dep[y])
            swap(x, y);
        for (int i = __lg(dep[x]); i >= 0; i--)
        {
            if (dep[far[x][i]] >= dep[y])
                x = far[x][i];
            if (x == y)
                return x;
        }
        for (int i = __lg(dep[x]); i >= 0; i--)
        {
            if (far[x][i] != far[y][i])
            {
                x = far[x][i];
                y = far[y][i];
            }
        }
        return far[x][0];
    };

    dfs(dfs, S, V);
}

// 这里提供下标从1开始的代码, 同时次数设置为常量22
void solve1()
{
    int V, q, S;
    cin >> V >> q >> S;
    vector<vector<int>> G(V + 1);
    for (int i = 0; i < V - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
            continue;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> dep(V + 1);
    vector<vector<int>> f(V + 1, vector<int>(22));
    auto dfs = [&](auto&& self, int u, int par) -> void
    {
        dep[u] = dep[par] + 1;
        f[u][0] = par;
        for (int i = 1; i <= 21; i++)
        {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (auto v : G[u])
        {
            if (v == par)
                continue;
            self(self, v, u);
        }
    };

    auto lca = [&](int x, int y)
    {
        if (dep[x] < dep[y])
            swap(x, y);
        for (int i = 21; i >= 0; i--)
        {
            if (dep[f[x][i]] >= dep[y])
                x = f[x][i];
            if (x == y)
                return x;
        }
        for (int i = 21; i >= 0; i--)
        {
            if (f[x][i] != f[y][i])
            {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    };

    dfs(dfs, S, 0);

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

// 重链
void solve2()
{
    int n, q, S;
    cin >> n >> q >> S;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> par(n + 1), dep(n + 1), top(n + 1), siz(n + 1, 1), son(n + 1);

    auto dfs1 = [&](auto&& self, int u) -> void
    {
        dep[u] = dep[par[u]] + 1;
        for (auto v : G[u])
        {
            if (v == par[u])
                continue;
            par[v] = u;
            self(self, v);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]])
                son[u] = v;
        }
    };

    auto dfs2 = [&](auto&& self, int u, int h) -> void
    {
        top[u] = h;
        if (son[u])
            self(self, son[u], h);
        for (auto v : G[u])
        {
            if (v == par[u] || v == son[u])
                continue;
            self(self, v, v);
        }
    };

    auto lca = [&](int x, int y) -> int
    {
        while (top[x] != top[y])
        {
            if (dep[top[x]] > dep[top[y]])
                x = par[top[x]];
            else
                y = par[top[y]];
        }
        return dep[x] < dep[y] ? x : y;
    };

    par[S] = 0;
    dfs1(dfs1, S);
    dfs2(dfs2, S, S);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}
```


## st表
```
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> fmin(n + 1, vector<int>(__lg(n) + 1));
    auto fmax = fmin;
    for (int i = 1; i <= n; i++)
    {
        fmin[i][0] = fmax[i][0] = a[i - 1];
    }
    for (int i = 1; i <= __lg(n); i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            fmin[j][i] = min(fmin[j][i - 1], fmin[j + (1 << (i - 1))][i - 1]);
            fmax[j][i] = max(fmax[j][i - 1], fmax[j + (1 << (i - 1))][i - 1]);
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int s = __lg(r - l + 1);
        int minn = min(fmin[l][s], fmin[r - (1 << s) + 1][s]);
        int maxx = max(fmax[l][s], fmax[r - (1 << s) + 1][s]);
        cout << maxx - minn << '\n';
    }
}
```


## KMP
```
vector<int> get_pmt(string_view s)
{
    vector<int> pmt(s.size());
    for (size_t i = 1, j = 0; i < s.size(); i++)
    {
        while (j != 0 && s[i] != s[j])
            j = pmt[j - 1];
        if (s[i] == s[j])
            j++;
        pmt[i] = j;
    }
    return pmt;
}

void kmp(string_view s, string_view t)
{
    auto pmt = get_pmt(t);
    for (size_t i = 0, j = 0; i < s.size(); i++)
    {
        while (j != 0 && s[i] != t[j])
            j = pmt[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == t.size()) // 找到了
        {
            cout << i - j + 2 << '\n';
            j = pmt[j - 1];
        }
    }
}
```

## hash
```
constexpr size_t BASE1 = 1331, BASE2 = 13331, MOD1 = 1e9 + 7, MOD2 = 998244353;
auto get_hash = [](string_view s, const size_t BASE, const size_t MOD)
{
    vector<u64> hash(s.size() + 1), p(s.size() + 1);
    p[0] = 1;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[i + 1] = hash[i] * BASE + s[i] - 'a' + 1;
        p[i + 1] = p[i] * BASE;
        hash[i + 1] %= MOD;
        p[i + 1] %= MOD;
    }
    return std::pair{hash, p};
};
auto query = [](int l, int r, vector<u64> const& hash, vector<u64> const& p, const size_t MOD)
{
    const u64 res = (hash[r] - hash[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    return res;
};
```

## 最小表示
```
size_t zuixiaobiaoshi(vector<int> const& vec)
{
    auto tmp = vec;
    tmp.insert(tmp.end(), vec.begin(), vec.end());
    const size_t n = vec.size();
    size_t i, j;
    for (i = 0, j = 1; i < n && j < n;)
    {
        size_t k;
        for (k = 0; k < n && tmp[i + k] == tmp[j + k]; k++)
        {
        }
        if (tmp[i + k] > tmp[j + k])
            i = i + k + 1;
        else
            j = j + k + 1;
        if (i == j)
            j++;
    }
    return min(i, j);
}

void func(vector<int>& vec)
{
    size_t k = zuixiaobiaoshi(vec);
    rotate(vec.begin(), vec.begin() + k, vec.end());
}
```

## dijkstra
```
auto dijkstra = [&](int s)
{
    vector<i64> dis(n, INF);
    priority_queue<pii, vector<pii>, greater<>> que;
    que.emplace(0, s);
    dis[s] = 0;
    while (!que.empty())
    {
        auto [ww, u] = que.top();
        que.pop();
        if (dis[u] < ww)
            continue;
        for (auto [v, w] : G[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                que.emplace(dis[v], v);
            }
        }
    }

    return dis;
};
```

## prim
```
auto prim = [&](int s) -> int
{
    int res = 0;
    int cnt = 0;
    vector<int> vis(n, false);
    constexpr int INF = 0x3f3f3f3f;
    vector<int> dis(n, INF);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> que;
    que.push({0, s});
    dis[s] = 0;
    while (!que.empty())
    {
        auto [ww, u] = que.top();
        que.pop();
        if (vis[u] || dis[u] < ww)
            continue;
        vis[u] = 1;
        cnt++;
        res += ww;
        for (auto [v, w] : G[u])
        {
            if (!vis[v] && dis[v] > w)
            {
                dis[v] = w;
                que.push({w, v});
            }
        }
    }
    if (cnt == n)
        return res;
    else
        return -1;
};
```

## spfa
```
auto spfa = [&](int s)
{
    vector<i64> dis(n, INF);
    queue<int> que;
    vector<int> vis(n);
    que.emplace(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!que.empty())
    {
        auto u = que.front();
        que.pop();
        vis[u] = 0;
        for (auto [v, w] : G[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    que.emplace(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis;
};
```

## int128
```
std::string to_string(i128 x)
{
    // 应做的特判
    if (x == std::numeric_limits<i128>::min())
    {
        return "-170141183460469231731687303715884105728";
    }
    std::string res;
    res.reserve(40);
    if (x < 0)
    {
        x = -x;
        res += '-';
    }
    while (x)
    {
        res += char(x % 10 + '0');
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

i128 get_i128(std::string_view s)
{
    i128 res = 0;
    i128 now = 1;
    for (int i = int(s.size()) - 1; i >= 0; i--, now *= 10)
    {
        res += (s[i] - '0') * now;
    }
    return res;
}

i128 sqrt(i128 x)
{
    if (x < 0)
        return -1;
    int len = num_len(x);
    i128 l = 0, r = 9;
    for (int i = 0; i < (len / 2); i++)
    {
        r = r * 10 + 9;
    }

    i128 res = 0;
    while (l <= r)
    {
        i128 mid = l + (r - l) / 2;
        if (mid * mid <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

std::istream& operator>>(std::istream& is, i128& x)
{
    x = 0;
    int f = 1;
    int ch = is.get();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = is.get();
    }
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = is.get();
    x *= f;
    return is;
}

std::ostream& operator<<(std::ostream& os, i128 x)
{
    if (x >= 10)
    {
        os << (x / 10);
    }
    os.put(x % 10 + '0');
    return os;
}
```

## 欧拉筛 欧拉函数
``` cpp
bool isnp[N];
int phi[N];
vector<int> primes;

void get_primes()
{
    phi[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
        {
            primes.emplace_back(i);
            phi[i] = i - 1;
        }
        for (int p : primes)
        {
            if (p * i >= N)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}
```

## 几何
```
// 二维向量
const double PI = acosl(-1);
const double EPS = 1e-10;

struct Vector2
{
    double x, y;
    explicit Vector2(double x_ = 0, double y_ = 0) :
        x(x_), y(y_) {}

    // 比较两个向量
    bool operator==(const Vector2& vec) const
    {
        return fabs(x - vec.x) < EPS && fabs(y - vec.y) < EPS;
    }
    bool operator<(const Vector2& vec) const
    {
        if (fabs(x - vec.x) < EPS)
            return y < vec.y;
        return x < vec.x;
    }

    // 向量的加法和减法
    Vector2 operator+(const Vector2& vec) const
    {
        return Vector2(x + vec.x, y + vec.y);
    }
    Vector2 operator-(const Vector2& vec) const
    {
        return Vector2(x - vec.x, y - vec.y);
    }

    // 向量的数乘
    Vector2 operator*(double a) const
    {
        return Vector2(x * a, y * a);
    }

    // 向量的模
    double norm() const
    {
        return hypot(x, y);
    }

    // 返回方向相同的单位向量
    // 零向量不可调用
    Vector2 normalize() const
    {
        return Vector2(x / norm(), y / norm());
    }

    // 从 x 轴正方向转到当前向量的角度
    double polar() const
    {
        // atan2 返回 (-PI, PI]，修正为 [0，2PI)
        // fmod 求两个实数相除的余数
        return fmod(atan2(y, x) + 2 * PI, 2 * PI);
    }

    // 内积
    double dot(const Vector2& vec) const
    {
        return x * vec.x + y * vec.y;
    }
    double cross(const Vector2& vec) const
    {
        return x * vec.y - y * vec.x;
    }

    // 当前向量映射到另一向量的结果
    // vec的长度需要大于0
    Vector2 project(const Vector2& vec) const
    {
        Vector2 r = vec.normalize();
        return r * r.dot(*this);
    }

    // 两个向量的夹角
    // 两个向量长度均需要大于 0
    double insersection_angle(const Vector2& vec) const
    {
        return acos(dot(vec) / norm() * vec.norm());
    }

    // 判断两个向量是否垂直
    // 两个向量长度均需要大于 0
    bool perpendicular(const Vector2& vec) const
    {
        return fabs(dot(vec)) < EPS;
    }

    // 平行四边形面积
    double parallelogram_area(const Vector2& vec) const
    {
        return fabs(cross(vec));
    }

    // 三角形面积，可以扩找到多边形
    double triangle_area(const Vector2& vec) const
    {
        return fabs(cross(vec)) / 2;
    }
};

// 凸包的面积
double area(const vector<Vector2>& p)
{
    double ans = 0.0;
    int n = p.size();
    for (int i = 0; i < n; ++i)
        ans += p[i].cross(p[(i + 1) % n]);
    return fabs(ans) / 2.0;
}

// 两点的距离
double dis(const Vector2& a, const Vector2& b)
{
    return (a - b).norm();
}

// 判定两个向量的方向
// ccw: counter clock wise
double ccw(const Vector2& a, const Vector2& b)
{
    // 正数: b 在 a 的逆时针 180 度内
    // 负数: b 在 a 的顺时针 180 度内
    // 0: 平行
    return a.cross(b);
}
double ccw(const Vector2& p, const Vector2& a, const Vector2& b)
{
    // 正数: 以 p 为基准点时，b 在 a 的逆时针 180 度内
    // 负数: 以 p 为基准点时，b 在 a 的顺时针 180 度内
    return ccw(a - p, b - p);
}

// 求凸包
vector<Vector2> convex_hull(vector<Vector2>& p)
{
    int n = p.size();
    sort(p.begin(), p.end());
    vector<Vector2> result(n * 2);
    int k = 0; // 当前的凸包点个数，即 result.size()
    // 构造凸包的下侧
    for (int i = 0; i < n; ++i)
    {
        while (k > 1 && (result[k - 1] - result[k - 2]).cross(p[i] - result[k - 1]) < 0)
            --k;
        result[k++] = p[i];
    }
    // 构造凸包的上侧
    int t = k;
    for (int i = n - 2; i >= 0; --i)
    {
        while (k > t && (result[k - 1] - result[k - 2]).cross(p[i] - result[k - 1]) < 0)
            --k;
        result[k++] = p[i];
    }
    result.resize(k - 1);
    return result;
}

double polygan_diameter(const vector<Vector2>& p)
{
    // p 以逆时针给出凸多边形的顶点
    int n = p.size();
    // 找最左端和最右端的点
    int left = min_element(p.begin(), p.end()) - p.begin();
    int right = max_element(p.begin(), p.end()) - p.begin();
    // 分别向 p[left] 和  p[right] 加垂线，两条垂涎有相反方向
    // 标出 a 的方向
    Vector2 calipersA(0, 1); // 卡尺的方向向量
    double ans = (p[right] - p[left]).norm();
    // toNext[i] := p[i] 到下一个顶点方向的单位向量
    vector<Vector2> toNext(n);
    for (int i = 0; i < n; ++i)
    {
        // normalize() 返回方向相同的单位向量
        toNext[i] = (p[(i + 1) % n] - p[i]).normalize();
    }
    // a, b 分别表示两条直线正在以哪个顶点为中心旋转
    int a = left, b = right;
    // 一直执行到两条直线旋转半圈后方向互换为止
    while (a != right || b != left)
    {
        // 查看 a, b 哪个到下一个顶点的角度更小
        double cosThetaA = calipersA.dot(toNext[a]);
        double cosThetaB = -calipersA.dot(toNext[b]);
        if (cosThetaA > cosThetaB)
        {
            // ThetaA < ThetaB
            // [0, PI] 的余弦值递减，不用计算实际角度就可以比较角度的大小关系
            calipersA = toNext[a];
            a = (a + 1) % n;
        }
        else
        {
            calipersA = toNext[b] * (-1);
            b = (b + 1) % n;
        }
        ans = max(ans, (p[a] - p[b]).norm());
    }
    return ans;
}

// 返回凸包直径
double get_D(vector<Vector2> const& vec)
{
    auto t = vec;
    vector<Vector2> ch = convex_hull(t);
    double D = polygan_diameter(ch);
    return D;
}

// 返回点 P 以点 O 为圆心逆时针旋转 alpha 后所在的位置
Vector2 rotate(Vector2 O, double alpha, Vector2 P)
{
    Vector2 new_P;
    Vector2 OP = P - O;
    new_P.x = OP.x * cos(alpha) - OP.y * sin(alpha) + O.x;
    new_P.y = OP.y * cos(alpha) + OP.x * sin(alpha) + O.y;
    return new_P;
}

// 直线
struct Line
{
    // line: a+pb, a 是点, b 是方向向量
    Vector2 a;
    Vector2 b;
    double deg; // 极角
    Line(Vector2 a, Vector2 b) :
        a(a), b(b)
    {
        deg = b.polar();
    }
    bool operator<(const Line& l) const
    {
        // 方向向量的极角序
        return deg < l.deg;
    }
};

bool on_left(const Line& l, const Vector2& p)
{
    // 点 p 是否在有向直线 l 左侧
    return l.b.cross(p - l.a) > EPS;
}

// 直线与直线相交
bool line_intersection(const Line& l1, const Line& l2, Vector2& x)
{
    double det = l1.b.cross(l2.b); // 两个方向向量的外积
    // 平行或重叠返回false
    if (fabs(det) < EPS)
        return false;
    // 两条有向直线的交点
    Vector2 u = l1.a - l2.a;
    double t = l2.b.cross(u) / det;
    x = l1.a + l1.b * t;
    return true;
}

// 直线与直线相交
bool line_intersection(Vector2 a, Vector2 b, Vector2 c, Vector2 d, Vector2& x)
{
    // 平行或重叠返回 false
    // (b - a) 是 (a, b) 的方向向量
    // (d - c) 是 (c, d) 的方向向量
    double det = (b - a).cross(d - c);
    if (fabs(det) < EPS)
        return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

// 两条直线平行时，判断两条线段是否属于同一直线且有重叠或相接于一点
bool parallelSegments(Vector2 a, Vector2 b, Vector2 c, Vector2 d, Vector2& x)
{
    // (a, b) , (c, d) 平行时，判断是否相接于一点
    if (b < a)
        std::swap(a, b);
    if (d < c)
        std::swap(c, d);
    // 两条线段不在同一条直线以及两条线段不重叠的情况
    if (ccw(a, b, c) != 0 || b < c || d < a)
        return false;
    if (a < c)
        x = c;
    else
        x = a;
    return true;
}

// 判断交点是否落在线段上
bool inBoundingRectangle(Vector2 x, Vector2 a, Vector2 b)
{
    // x, a, b 同线
    // 判断 x 是否在包含 (a, b) 且各边平行于 x 轴，y 轴的最小四边形内部。
    if (b < a)
        std::swap(a, b);
    return x == a || x == b || (a < x && x < b);
}

// 线段与线段相交
bool segmentIntersection(Vector2 a, Vector2 b, Vector2 c, Vector2 d, Vector2& x)
{
    // 将 (a, b) , (c, d) 的交点返回 x
    // 多个交点返回 x 最小的，x 相同的情况下返回 y 最小的
    // 不相交返回 false
    if (!line_intersection(a, b, c, d, x))
    {
        // 两条线段平行
        return parallelSegments(a, b, c, d, x);
    }
    // 两条直线有交点 x
    // 仅当两条线段都包含 x 时返回真
    return inBoundingRectangle(x, a, b) && inBoundingRectangle(x, c, d);
}

bool segmentIntersection(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);
    // 两条线段在同一直线上或者端点相互重叠
    if (abs(ab - 0) < EPS && abs(cd - 0) < EPS)
    {
        if (b < a)
            std::swap(a, b);
        if (d < c)
            std::swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

// 角平分线
Line get_pingfen(Vector2 a, Vector2 b, Vector2 c)
{
    auto get_duidian = [](Vector2 a, Vector2 b, Vector2 c)
    {
        Vector2 ea = a - b;
        Vector2 eb = c - b;
        auto dis1 = dis(c, b);
        auto dis2 = dis(a, b);
        Vector2 eaaa = ea * dis1;
        Vector2 ebbb = eb * dis2;
        Vector2 bb = eaaa + ebbb;
        return bb + b;
    };
    Vector2 bb = get_duidian(a, b, c);
    return Line(b, bb);
}
```
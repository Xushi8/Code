#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>



inline void solve();

// 核心函数, S是当前经过的点的集合, cur为当前位置
int func(int S, int cur);

// 获得路径
inline void get_path(int S, int cur);

// 打印路径
inline void print_path();

int main() {
    ::std::ios::sync_with_stdio(false);
    ::std::cin.tie(0);

    solve();

    ::std::cout << ::std::flush;
    return 0;
}

inline void solve() {
    memset(dp, -1, sizeof(dp));
    memset(dis, 0x3f, sizeof(dis));

    ::std::cout << "请输入顶点数, 边数, 各个边的两端, 权重:" << ::std::endl;

    ::std::cin >> n; // 顶点数
    int e; // 边数
    ::std::cin >> e;
    for (int i = 0; i < e; i++) {
        int u, v, cost;
        ::std::cin >> u >> v >> cost;
        u--; v--;
        dis[u][v] = dis[v][u] = cost;
    }
    int ans = func(0, 0);
    ::std::cout << "最小权重为: " << ans << ::std::endl;
    get_path(0, 0);
    print_path();
}

const int INF = 0x3f3f3f3f;
int dis[22][22];
int dp[1 << 22][22];
int n;
::std::vector<int> path; // 路径

// 核心函数, S是当前经过的点的集合, cur为当前位置
int func(int S, int cur)
{
    if (dp[S][cur] >= 0) // 已查找到该方案, 直接返回
        return dp[S][cur];

    if (S == (1 << n) - 1 && cur == 0) // 已经过所有点且回到了原点
        return dp[S][cur] = 0;

    int ret = INF;
    for (int i = 0; i < n; i++)
    {
        if (((S >> i) & 1) == 0) // 如果这个点没有在本集合中
            ret = ::std::min(ret, func((S | (1 << i)), i) + dis[cur][i]); // 寻找到状态的最小值
    }

    return dp[S][cur] = ret;
}

inline void get_path(int S, int cur)
{
    for (int i = 0; i < n; i++)
    {
        if (((S >> i) & 1) == 0)
        {
            // 根据dp顺序推出路径
            if (dp[S][cur] == dp[S | (1 << i)][i] + dis[cur][i])
            {
                path.emplace_back(i);
                get_path(S | (1 << i), i);
                break;
            }
        }
    }
}

inline void print_path(){
    ::std::reverse(path.begin(), path.end());
    ::std::cout << "路径如下: \n";
    for (const int& x : path)
        ::std::cout << x + 1 << "->";
    ::std::cout << 0 + 1 << ::std::endl;
}
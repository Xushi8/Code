// // 2023/08/11 15:00:48
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
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 105;

// int trie[N][26], sum[N], fail[N];
// int cnt = 0;
// int n;
// void init()
// {
//     cnt = 0;
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j < 26; j++)
//         {
//             trie[i][j] = 0;
//         }
//         sum[i] = 0;
//         fail[i] = 0;
//     }
// }

// void add(const string& s)
// {
//     int root = 0;
//     for (char ch : s)
//     {
//         int id = ch - 'a';
//         if (trie[root][id] == 0)
//             trie[root][id] = ++cnt;
//         root = trie[root][id];
//     }

//     sum[root]++;
// }

// void add_fail()
// {
//     queue<int> que;
//     int root = 0;
//     for (int i = 0; i < 26; i++)
//     {
//         if (trie[root][i] != 0)
//         {
//             que.emplace(trie[root][i]);
//             fail[trie[root][i]] = root;
//         }
//     }

//     while (!que.empty())
//     {
//         int now = que.front(); que.pop();
//         cout << now << '\n';    
//         for (int i = 0; i < 26; i++)
//         {
//             if (trie[now][i] != 0)
//             {
//                 fail[trie[now][i]] = trie[fail[now]][i];
//                 que.push(trie[now][i]);
//             }
//             else
//             {
//                 trie[now][i] = trie[fail[now]][i];
//             }
//         }
//     }
// }


// // void build() {
// //     queue<int> q;
// //     for (int i = 0; i < 26; i++)
// //         if (trie[0][i]) q.push(trie[0][i]);
// //     while (q.size()) {
// //         int u = q.front();
// //         q.pop();
// //         for (int i = 0; i < 26; i++) {
// //             if (trie[u][i])
// //                 fail[trie[u][i]] = trie[fail[u]][i], q.push(trie[u][i]);
// //             else
// //                 trie[u][i] = trie[fail[u]][i];
// //         }
// //     }
// // }

// ull check(const string& s)
// {
//     ull ans = 0;
//     int now = 0;
//     for (char ch : s)
//     {
//         int id = ch - 'a';
//         now = trie[now][id];
//         for (int j = now; j != 0 && sum[j] != -1; j = fail[j])
//         {
//             ans += sum[j];
//             sum[j] = -1;
//         }
//     }

//     return ans;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     while (cin >> n && n)
//     {
//         string s;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> s;
//             add(s);
//         }   
//         cin >> s;
//         add_fail();
//         cout << check(s) << '\n';
//         init();
//     }

// #ifdef LOCAL
//     cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
//     cout << flush;
//     return 0;
// }

// 2023/08/11 20:55:32
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int cnt;
int trie[N][26], fail[N], e[N];
queue<int> q;
int n;

void init()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            trie[i][j] = 0;
        }
        fail[i] = 0;
        e[i] = 0;
    }
}

void insert(const string& s)
{
    int root = 0;
    for (char ch : s)
    {
        int id = ch - 'a';
        if (trie[root][id] == 0)
            trie[root][id] = ++cnt;
        root = trie[root][id];
    }
    e[root]++;
}

void build() {
    for (int i = 0; i < 26; i++)
        if (trie[0][i]) q.push(trie[0][i]);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (trie[u][i])
                fail[trie[u][i]] = trie[fail[u]][i], q.push(trie[u][i]);
            else
                trie[u][i] = trie[fail[u]][i];
        }
    }
}


int query(const char* t) {
    int u = 0, res = 0;
    for (int i = 1; t[i]; i++) {
        u = trie[u][t[i] - 'a'];  // 转移
        for (int j = u; j && e[j] != -1; j = fail[j]) {
            res += e[j], e[j] = -1;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert(s);
    }
    build();
    cin >> s;
    cout << query(s.c_str()) << '\n';

    init();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
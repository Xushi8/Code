// 2023/11/08 16:28:16
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;
int post[N], in[N];

struct node
{
    int val;
    node *l, *r;
};

node* build(int s1, int t1, int s2, int t2)
{
    if (s1 > t1)
    {
        return nullptr;
    }

    node* p = new node;
    p->val = post[t1];
    int index;
    for (index = s2; in[index] != p->val; index++)
    {
    }

    int siz = index - 1 - s2 + 1;
    p->l = build(s1, s1 + siz - 1, s2, index - 1);
    p->r = build(s1 + siz - 1 + 1, t1 - 1, index + 1, t2);

    return p;
}

void delete_tree(node* p)
{
    if (p->l != nullptr)
        delete_tree(p->l);
    if (p->r != nullptr)
        delete_tree(p->r);

    delete p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    node* root = build(0, n - 1, 0, n - 1);

    queue<node*> que;
    que.emplace(root);
    bool flag = 0;
    while (!que.empty())
    {
        node* p = que.front();
        que.pop();
        if (flag)
        {
            cout << ' ';
        }
        else
        {
            flag = 1;
        }
        cout << p->val;
        if (p->l != nullptr)
        {
            que.emplace(p->l);
        }
        if (p->r != nullptr)
        {
            que.emplace(p->r);
        }
    }

    delete_tree(root);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
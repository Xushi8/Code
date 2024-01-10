// 2023/11/26 13:09:44
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
constexpr int N = 10005;

struct node
{
    int val;
    size_t lh, rh;
    node *l, *r;

    node() = delete;

    constexpr node(int _val, int _lh = 0, int _rh = 0, node* _l = nullptr, node* _r = nullptr) :
        val(_val),
        lh(_lh),
        rh(_rh),
        l(_l),
        r(_r)
    {
    }

    ~node()
    {
        delete (this->l);
        delete (this->r);
        delete this;
    }
};

void insert(node*& root, int x)
{
    if (root == nullptr)
    {
        root = new node(x);
        return;
    }

    if (x > root->val)
    {
        insert(root->r, x);
        root->rh = max(root->r->lh, root->r->rh) + 1;
    }
    else
    {
        insert(root->l, x);
        root->lh = max(root->l->lh, root->l->rh) + 1;
    }

    if (root->lh - root->rh == 2) // 左边
    {
        if (root->l->lh > root->l->rh) // 左左
        {
            node* a = root;
            node* b = root->l;
            root = b;
            a->l = b->r;
            a->lh = b->rh;
            b->r = a;
            b->rh++;
        }
        else // 左右
        {
            node* a = root;
            node* b = root->l;
            node* c = root->l->r;
            root = c;
            b->r = c->l;
            b->rh = c->lh;
            a->l = c->r;
            a->lh = c->rh;
            c->l = b;
            c->r = a;
            c->lh = b->lh + 1;
            c->rh = a->rh + 1;
        }
    }
    else if (root->rh - root->lh == 2) // 右边
    {
        if (root->r->rh > root->r->lh) // 右右
        {
            node* a = root;
            node* b = root->r;
            root = b;
            a->r = b->l;
            a->rh = b->lh;
            b->l = a;
            b->lh++;
        }
        else // 右左
        {
            node* a = root;
            node* b = root->r;
            node* c = root->r->l;
            root = c;
            a->r = c->l;
            a->rh = c->lh;
            b->l = c->r;
            b->lh = c->rh;
            c->l = a;
            c->r = b;
            c->lh = a->lh + 1;
            c->rh = b->rh + 1;
        }
    }
    else // 合法
    {
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    node* root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(root, x);
    }

    cout << root->val;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
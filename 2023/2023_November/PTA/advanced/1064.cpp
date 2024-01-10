// 2023/11/24 21:03:56
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
    node *l, *r;

    node(int x, node* s = nullptr, node* t = nullptr) :
        val(x),
        l(s),
        r(t)
    {
    }
};

void make_tree(int now, int maxn, node*& root)
{
    if (now >= maxn)
    {
        return;
    }

    root = new node(now);
    make_tree(now * 2 + 1, maxn, root->l);
    make_tree(now * 2 + 2, maxn, root->r);
}

void get_in_order(node* root, vector<int>& order)
{
    if (root == nullptr)
    {
        return;
    }

    get_in_order(root->l, order);
    order.emplace_back(root->val);
    get_in_order(root->r, order);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr)
    {
        cin >> x;
    }

    sort(arr.begin(), arr.end());

    node* root;
    make_tree(0, n, root);

    vector<int> in_order;
    in_order.reserve(n);
    get_in_order(root, in_order);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[in_order[i]] = arr[i];
    }

    for (int& x : ans)
    {
        cout << x << " \n"[&x == &ans.back()];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}
// 2024/02/04 17:15:06
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

struct node
{
    int val;
    node *l, *r;
    node() = default;
    node(int a, node* b = nullptr, node* c = nullptr)
    {
        val = a;
        l = b;
        r = c;
    }
};

void insert(node* root)
{
    string s;
    cin >> s;
    if (!cin.eof() && s == "Push")
    {
        int val;
        cin >> val;
        root->l = new node(val);
        insert(root->l);
    }
    cin >> s;
    if (!cin.eof() && s == "Push")
    {
        int val;
        cin >> val;
        root->r = new node(val);
        insert(root->r);
    }
}

vector<int> ans;
void print(node* root)
{
    if (root == nullptr)
        return;
    print(root->l);
    print(root->r);
    ans.emplace_back(root->val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    int val;
    cin >> s >> val;
    node* root = new node(val);
    insert(root);
    print(root);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
            cout << ' ';
        cout << ans[i];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
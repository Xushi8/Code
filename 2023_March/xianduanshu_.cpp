#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<int> arr(100005), tree(400005), mark(400005);

void build_tree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    int left_node = 2 * node;
    int right_node = 2 * node + 1;

    build_tree(left_node, start, mid);
    build_tree(right_node, mid + 1, end);
    tree[node] = tree[left_node] + tree[right_node];
}

// // 单点
// void update_tree(int node, int start, int end, int index, int add_val)
// {
//     if (start == end)
//     {
//         arr[index] += add_val;
//         tree[node] += add_val;
//         return;
//     }

//     int mid = (start + end) / 2;
//     int left_node = 2 * node;
//     int right_node = 2 * node + 1;
//     if (index <= mid)
//     {
//         update_tree(node, start, mid, index, add_val);
//     }
//     else
//     {
//         update_tree(node, mid + 1, end, index, add_val);
//     }

//     tree[node] = tree[left_node] + tree[right_node];
// }

void update_tree(int node, int start, int end, int L, int R, int add_val)
{
    if (L <= start && end <= R)
    {
        tree[node] += (end - start + 1) * add_val;
        mark[node] += add_val;
        return;
    }

    int mid = (start + end) / 2;
    if (mark[node] != 0 && start != end)
    {
        tree[node * 2] += mark[node] * (mid - start + 1);
        tree[node * 2 + 1] += mark[node] * (end - mid);
        mark[node * 2] += mark[node];
        mark[node * 2 + 1] += mark[node];
        mark[node] = 0;
    }
    if (L <= mid) update_tree(node * 2, start, mid, L, R, add_val);
    if (R > mid) update_tree(node * 2 + 1, mid + 1, end, L, R, add_val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query_tree(int node, int start, int end, int L, int R)
{
    if (L <= start && end <= R) return tree[node];

    int mid = (start + end) / 2;
    if (mark[node] != 0 && start != end)
    {
        tree[node * 2] += mark[node] * (mid - start + 1);
        tree[node * 2 + 1] += mark[node] * (end - mid);
        mark[node * 2] += mark[node];
        mark[node * 2 + 1] += mark[node];
        mark[node] = 0;
    }

    int sum = 0;
    if (L <= mid) sum += query_tree(node * 2, start, mid, L, R);
    if (R > mid) sum += query_tree(node * 2 + 1, mid + 1, end, L, R);
    return sum;
}

// 单点
// int query_tree(int node, int start, int end, int L, int R)
// {
//     if (R < start || L > end) return 0;
//     if (L <= start && end <= R) return tree[node];

//     int mid = (start + end) / 2;
//     int left_node = 2 * node;
//     int right_node = 2 * node + 1;
    
//     return query_tree(left_node, start, mid, L, R) + query_tree(right_node, mid + 1, end, L, R);
// }

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build_tree(1, 1, n); 
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            int d;
            cin >> d;
            update_tree(1, 1, n, b, c, d);
        }
        else
        {
            cout << query_tree(1, 1, n, b, c) << '\n';
        }
    }

    cout << flush;
    system("pause");
    return 0;
}
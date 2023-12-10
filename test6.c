#include <stdio.h>
#include <stdbool.h>

typedef int typevalue;
typevalue L[100], R[100];

// 6.33
// u表示当前节点，v表示目标节点
bool func_6_33(typevalue L[], typevalue R[], size_t n, typevalue u, typevalue v)
{
    if (u == 0)
        return false;

    if (u == v)
        return true;

    return func_6_33(L, R, n, L[u], v) | func_6_33(L, R, n, R[u], v);
}

bool check(typevalue L[], typevalue R[], size_t n, typevalue u, typevalue v)
{
    return func_6_33(L, R, n, L[v], v) | func_6_33(L, R, n, R[v], v);
}

// 6.42
struct node
{
    typevalue val;
    struct node *L, *R;
    struct node* par;
    size_t deep;
};
typedef struct node node;

size_t func_6_42(node* root, size_t cnt)
{
    if (root == NULL)
    {
        return cnt;
    }

    if (root->L == NULL && root->R == NULL)
    {
        cnt++;
        return cnt;
    }

    cnt = func_6_42(root->L, cnt);
    cnt = func_6_42(root->R, cnt);
    return cnt;
}

// 6.43;
void func_6_43(node* root)
{
    if (root == NULL)
    {
        return;
    }
    func_6_43(root->L);
    func_6_43(root->R);
    swap(root->L, root->R);
}

// 6.45
void delete_tree(node* root)
{
    if (root == NULL)
    {
        return;
    }

    delete_tree(root->L);
    delete_tree(root->R);
    free(root);
}

void func_6_45(node* root, typevalue x)
{
    if (root == NULL)
    {
        return;
    }

    if (root->val == x)
    {
        delete_tree(root);
        return;
    }

    delete_tree(root->L);
    delete_tree(root->R);
}

// 6.46
node* cloneTree(node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // node* res = new node{root->val, nullptr, nullptr};
    node* clone = (node*)malloc(sizeof(node));
    clone->val = root->val;

    // 使用栈进行深度优先遍历
    stack<node*> stk;
    stk.push(root);
    stack<node*> clone_stk;
    clone_stk.push(res);

    while (!stk.empty())
    {
        node* cur = stk.top();
        stk.pop();
        node* clone_cur = clone_stk.top();
        clone_stk.pop();

        if (cur->R != NULL)
        {
            clone_cur->R = (node*)malloc(sizeof(node));
            clone_cur->R->val = cur->R->val;
            stk.push(cur->R);
            clone_stk.push(clone_cur->R);
        }

        if (cur->L != NULL)
        {
            clone_cur->L = (node*)malloc(sizeof(node));
            clone_cur->L->val = cur->L->val;
            stk.push(cur->L);
            clone_stk.push(clone_cur->L);
        }
    }

    return res;
}

// 6.48

// 在节点中增加两个值，分别是它们的深度和父节点
node* func_6_48(node* p, node* q, node* root)
{
    // 令深度相同
    while (p->deep != q->deep)
    {
        if (p->deep < q->deep)
        {
            q = q->par;
        }
        else
        {
            p = p->par;
        }
    }

    while (p != q)
    {
        p = p->par;
        q = q->par;
    }

    return p;
}

// 6.51
// 后序遍历
void func_6_51(node* root)
{
    if (root == NULL)
    {
        return;
    }

    func_6_51(root->L);
    func_6_51(root->R);
    cout << root->val;
}

// 6.54
void insert(node*& root, typevalue x)
{
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->val = x;
        root->L = root->R = NULL;
        return;
    }

    if (x > root->val)
    {
        insert(root->L, x);
    }
    else if (x < root->val)
    {
        insert(root->R, x);
    }
    else // 相等则什么也不做
    {
    }
}

void func_6_54(node*& root, list sa)
{
    for (size_t i = 1; i <= sa.last; i++)
    {
        insert(root, sa[i]);
    }
}


// 6.56
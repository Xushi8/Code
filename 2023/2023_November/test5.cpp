#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int val;
    struct node* L;
    struct node* R;
};

// 定义复制二叉树函数
node* cloneTree(node* root)
{
    if (!root)
    {
        return nullptr;
    }

    node* res = new node{root->val, nullptr, nullptr};
    

    // 使用栈进行深度优先遍历
    std::stack<node*> s;
    s.push(root);
    std::stack<node*> cloneStack;
    cloneStack.push(res);

    while (!s.empty())
    {
        node* current = s.top();
        s.pop();
        node* clonedCurrent = cloneStack.top();
        cloneStack.pop();

        // 处理右子节点
        if (current->R)
        {
            clonedCurrent->R = new node{current->R->val, nullptr, nullptr};
            s.push(current->R);
            cloneStack.push(clonedCurrent->R);
        }

        // 处理左子节点
        if (current->L)
        {
            clonedCurrent->L = new node{current->L->val, nullptr, nullptr};
            s.push(current->L);
            cloneStack.push(clonedCurrent->L);
        }
    }

    // 返回新树的克隆版本
    return res;
}

int main()
{
    // 示例用法
    node* root = new node{1, new node{2, new node{4, nullptr, nullptr}, new node{5, nullptr, nullptr}}, new node{3, nullptr, nullptr}};

    node* res = cloneTree(root);

    // 在这里可以对克隆树进行操作或输出
    cout << root << ' ' << res << endl;

    return 0;
}
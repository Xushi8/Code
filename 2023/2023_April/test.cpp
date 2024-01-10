#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
#define Type char

//要求1.二叉树中的结点个数2.叶子结点个数3.某结点层次4.二叉树的宽度

struct TreeNode
{
    Type val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(Type x = ' '):val(x), left(NULL), right(NULL) {}
};

class Tree {
    bool flag;
public:
    TreeNode* createFromArray(char* pre, char* in, int n)//pre存放先序序列，in存放中序序列
    {
        TreeNode* b;
        char* p;
        int k;
        if (n <= 0)    return NULL;
        b = new TreeNode();
        b->val = *pre;
        for (p = in;p < in + n;p++)
        {
            if (*p == *pre)
                break;
        }
        k = p - in;
        b->left = createFromArray(pre + 1, in, k);
        b->right = createFromArray(pre + k + 1, p + 1, n - k - 1);
        return b;
    }

    void print(TreeNode* tr)
    {
        queue<TreeNode*>q;
        TreeNode* tmp;
        q.push(tr);//根节点入队
        while (!q.empty())
        {
            int width = q.size();
            for (int i = 0; i < width;i++)
            {
                tmp = q.front();
                printf("%c ", tmp->val);
                q.pop();
                if (tmp->left != NULL)
                {
                    q.push(tmp->left);
                }
                if (tmp->right != NULL)
                {
                    q.push(tmp->right);
                }
            }
            printf("\n");
        }
    }

    void preorder(TreeNode* Bt, Type x)
    {
        if (Bt == NULL)  return;
        if ((Bt->left != NULL || Bt->right != NULL) && flag == false)
        {
            if (Bt->left != NULL && Bt->left->val == x)
            {
                flag = true;
                printf("%c的双亲结点为:%c\n", x, Bt->val);
                return;
            }
            else if (Bt->right != NULL && Bt->right->val == x)
            {
                flag = true;
                printf("%c的双亲结点为:%c\n", x, Bt->val);
                return;
            }
            else
            {
                if (Bt->left != NULL)
                {
                    preorder(Bt->left, x);
                }
                if (Bt->right != NULL)
                {
                    preorder(Bt->right, x);
                }
            }
        }
    }
};

int main()
{
    Type a[] = { 'A','B','D','I','E','C','G','H' };//前序
    Type b[] = { 'I','D','B','E','A','G','C','H' };//中序 
    int n = 8;
    int choose = 0;
    TreeNode* new_BT;//创建结点
    Tree BT1;//创建类
    new_BT = BT1.createFromArray(a, b, n);
    BT1.print(new_BT);
    BT1.preorder(new_BT, 'C');
    system("pause");
    return 0;
}
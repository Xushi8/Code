#include<stdio.h>
#include<stdlib.h>

typedef struct tree 
{
    int element;
    tree* left;
    tree* right;
}tree;

tree* insert(int n, tree* p);
tree* find_element(int n, tree* p);
tree* find_min(tree* p);
tree* find_max(tree* p);
tree* delete_tree(int n, tree* p);
void print_tree(tree* p);

int main()
{
    tree *root, *min, *max;
    root = insert(9, NULL);
    insert(8, root);
    insert(7, root);
    insert(5, root);
    insert(83, root);
    insert(2, root);
    insert(2, root);
    min = find_min(root);
    max = find_max(root);
    printf("max = %d\nmin = %d\n", max->element, min->element);
    print_tree(root);
    printf("\n");
    delete_tree(83, root);
    delete_tree(9, root);
    print_tree(root);

    return 0;
}

tree* insert(int n, tree* p)
{
    tree* tmp;
    if(p == NULL)
    {
        p = (tree*)malloc(sizeof(tree));
        if(p == NULL)
        {
            perror("insert");
            return NULL;
        }
        else
        {
            p->element = n;
            p->left = NULL;
            p->right = NULL;
            return p;
        }
    }
    else if(p->element > n)
    {
        p->left = insert(n, p->left);
    }
    else if(p->element < n)
    {
        p->right = insert(n, p->right);
    }

    return p;
}

tree* find_element(int n, tree* p)
{
    if(p == NULL)
    {
        return NULL;
    }
    
    if(p->element > n)
    {
        return find_element(n, p->left);
    }
    else if(p->element < n)
    {
        return find_element(n, p->right);
    }
    else
    {
        return p;
    }
}

tree* find_min(tree* p)
{
    if(p == NULL)
    {
        return NULL;
    }

    while(p->left != NULL)
    {
        p = p->left;
    }

    return p;
}

tree* find_max(tree* p)
{
    if(p == NULL)
    {
        return NULL;
    }

    while(p->right != NULL)
    {
        p = p->right;
    }

    return p;
}

tree* delete_tree(int n, tree* p)
{
    tree* tmp;
    if(p == NULL)
    {
        return NULL;
    }
    else if(p->element > n)
    {
        p->left = delete_tree(n, p->left);
    }
    else if(p->element < n)
    {
        p->right = delete_tree(n, p->right);
    }
    else if(p->left != NULL && p->right != NULL)//两个儿子
    {
        tmp = find_min(p);
        p->element = tmp->element;
        p->right = delete_tree(tmp->element, p->right);
        free(tmp);
    }
    else//一个或没有儿子
    {
        if(p->left == NULL)
        {
            p = p->right;
        }
        else if(p->right == NULL)
        {
            p = p->left;
        }

        return p;
    }

    return p;
}

void print_tree(tree* p)
{
    if(p == NULL)
    {
        puts("空树");
    }

    if(p->left != NULL)
    {
        print_tree(p->left);
    }

    printf("%d ", p->element);

    if(p->right != NULL)
    {
        print_tree(p->right);
    }

}
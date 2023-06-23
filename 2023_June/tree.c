#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
    int element;
    struct tree* left;
    struct tree* right;
};

struct tree* insert(int n, struct tree* p);
struct tree* find_element(int n, struct tree* p);
struct tree* find_min(struct tree* p);
struct tree* find_max(struct tree* p);
struct tree* delete_tree(int n, struct tree* p);
void print_tree(struct tree* p);
void print_tree_pre(struct tree* p);
void print_tree_mid(struct tree* p);

int main()
{
    struct tree* root = NULL;
    // root = insert(9, NULL);
    // insert(83, root);
    // insert(57, root);
    // insert(3272, root);
    // insert(43, root);
    // insert(83, root);
    // insert(7, root);
    // insert(5, root);
    // insert(83, root);
    // insert(88, root);
    // insert(2, root);
    // insert(2, root);
    // min = find_min(root);
    // max = find_max(root);
    // printf("max = %d\nmin = %d\n", max->element, min->element);
    // print_struct tree(root);
    // printf("\n");
    // delete_struct tree(83, root);
    // delete_struct tree(9, root);
    // delete_struct tree(3272, root);
    // print_struct tree(root);

    int tt;
    scanf("%d", &tt);
    char str[10];
    while (tt--)
    {
        scanf("%s", str);
        if (strcmp(str, "insert") == 0)
        {
            int tmp;
            scanf("%d", &tmp);
            if (root == NULL)
            {
                root = insert(tmp, NULL);
            }
            else
            {
                insert(tmp, root);
            }
        }
        else if (strcmp(str, "find") == 0)
        {
            int tmp;
            scanf("%d", &tmp);
            if (find_element(tmp, root) == NULL)
            {
                puts("no");
            }
            else
            {
                puts("yes");
            }
        }
        else if (strcmp(str, "delete") == 0)
        {
            int tmp;
            scanf("%d", &tmp);
            delete_tree(tmp, root);
        }
        else
        {
            print_tree_mid(root);
            putchar('\n');
            print_tree_pre(root);
            putchar('\n');
        }
    }

    return 0;
}

struct tree* insert(int n, struct tree* p)
{
    if (p == NULL)
    {
        p = (struct tree*)malloc(sizeof(struct tree));
        if (p == NULL)
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
    else if (p->element > n)
    {
        p->left = insert(n, p->left);
    }
    else if (p->element < n)
    {
        p->right = insert(n, p->right);
    }

    return p;
}

struct tree* find_element(int n, struct tree* p)
{
    if (p == NULL)
    {
        return NULL;
    }

    if (p->element > n)
    {
        return find_element(n, p->left);
    }
    else if (p->element < n)
    {
        return find_element(n, p->right);
    }
    else
    {
        return p;
    }
}

struct tree* find_min(struct tree* p)
{
    if (p == NULL)
    {
        return NULL;
    }

    while (p->left != NULL)
    {
        p = p->left;
    }

    return p;
}

struct tree* find_max(struct tree* p)
{
    if (p == NULL)
    {
        return NULL;
    }

    while (p->right != NULL)
    {
        p = p->right;
    }

    return p;
}

struct tree* delete_tree(int n, struct tree* p)
{
    struct tree* tmp;
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->element > n)
    {
        p->left = delete_tree(n, p->left);
    }
    else if (p->element < n)
    {
        p->right = delete_tree(n, p->right);
    }
    else if (p->left != NULL && p->right != NULL)//两个儿子
    {
        tmp = find_min(p->right);
        p->element = tmp->element;
        p->right = delete_tree(p->element, p->right);
    }
    else//一个或没有儿子
    {
        tmp = p;
        if (p->left == NULL)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
        free(tmp);
    }

    return p;
}

void print_tree_mid(struct tree* p)
{
    // if (p == NULL)
    // {
    //     puts("空树");
    // }

    if (p->left != NULL)
    {
        print_tree_mid(p->left);
    }

    printf(" %d", p->element);

    if (p->right != NULL)
    {
        print_tree_mid(p->right);
    }
}

void print_tree_pre(struct tree* p)
{
    printf(" %d", p->element);
    
    if (p->left != NULL)
    {
        print_tree_pre(p->left);
    }

    if (p->right != NULL)
    {
        print_tree_pre(p->right);
    }
}
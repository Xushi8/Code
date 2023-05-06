#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// typedef struct tree
// {
//     int element;
//     tree* left;
//     tree* right;
// }tree;


// tree* insert(int n, tree* p)
// {
//     if (p == NULL)
//     {
//         p = (tree*)malloc(sizeof(tree));
//         if (p == NULL)
//         {
//             perror("insert");
//             return NULL;
//         }
//         else
//         {
//             p->element = n;
//             p->left = NULL;
//             p->right = NULL;
//             return p;
//         }
//     }
//     else if (p->element > n)
//     {
//         p->left = insert(n, p->left);
//     }
//     else if (p->element < n)
//     {
//         p->right = insert(n, p->right);
//     }

//     return p;
// }

// tree* find_element(int n, tree* p)
// {
//     if (p == NULL)
//     {
//         return NULL;
//     }

//     if (p->element > n)
//     {
//         return find_element(n, p->left);
//     }
//     else if (p->element < n)
//     {
//         return find_element(n, p->right);
//     }
//     else
//     {
//         return p;
//     }
// }

// void print1(tree* p)
// {

//     if (p->left != NULL)
//     {
//         print1(p->left);
//     }

//     // printf(" %d", p->element);
//     cout << ' ' << p->element;

//     if (p->right != NULL)
//     {
//         print1(p->right);
//     }
// }

// void print2(tree* p)
// {
//     // printf(" %d", p->element);
//     cout << ' ' << p->element;
//     if (p->left != NULL)
//     {
//         print2(p->left);
//     }
//     if (p->right != NULL)
//     {
//         print2(p->right);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     tree* root = NULL;
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         string a;
//         int b;
//         cin >> a;
//         if (a == "insert")
//         {
//             cin >> b;
//             if (root == NULL)
//             {
//                 root = insert(b, NULL);
//             }
//             else
//             {
//                 insert(b, root);
//             }
//         }
//         else if (a == "find")
//         {
//             cin >> b;
//             if (find_element(b, root) != NULL) cout << "yes\n";
//             else cout << "no\n";
//         }
//         else
//         {
//             print1(root);
//             // printf("\n");
//             cout << '\n';
//             print2(root);
//             // printf("\n");
//             cout << '\n';
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// unsigned long long sum[200009];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     cin >> sum[0];
//     for (int i = 1; i < n; i++)
//     {
//         cin >> sum[i];
//         sum[i] += sum[i - 1];
//     }

//     unsigned long long ans = 0;
//     ans += sum[0] * (sum[n - 1] - sum[0]);
//     for (int i = 1; i < n; i++)
//     {
//         ans += (sum[i] - sum[i - 1]) * (sum[n - 1] - sum[i]);
//     }
//     cout << ans;

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int prime[10000008];
// bool isnp[100000008];

// int main()
// {
//     int tot = 0;
//     for (int i = 2; i < 100000008; i++)
//     {
//         if (!isnp[i]) prime[tot++] = i;;

//         for (int j = 0; j < 100000008; j++)
//         {
//             if (prime[j] * i > 100000008) break;

//             isnp[prime[j] * i] = 1;

//             if (i % prime[j] == 0) break;
//         }
//     }
//     int ans = 0;
//     int tt;
//     scanf("%d", &tt);
//     while (tt--)
//     {
//         int a;
//         scanf("%d", &a);
//         int left = 0, right = tot;
//         int mid = (right + left) / 2;
//         while (left < right)
//         {
//             mid = (right + left) / 2;
//             if (prime[mid] > a)
//             {
//                 right = mid;
//             }
//             else if (prime[mid] < a)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 ans++;
//                 break;
//             }
//         }
//     }
//     printf("%d", ans);

//     system("pause");
//     return 0;
// }



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    cout << flush;
    system("pause");
    return 0;
}
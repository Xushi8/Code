#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// int main()
// {
//     int a, b,c,d;
//     scanf("%d%d", &a, &b);
//     c = a, d = b;
//     int tmp;
//     do
//     {
//         tmp = a % b;
//         a = b;
//         b = tmp;
//     } while (tmp);

//     printf("%d %d", a, c * d / a);

//     return 0;
// }

// int main()
// {
//     int ch;
//     int zimu = 0;
//     int shuzi = 0;
//     int kongge = 0;
//     int others = 0;
//     while ((ch = getchar()) != EOF && ch != '\n')
//     {
//         if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//         {
//             zimu++;
//         }
//         else if (ch >= '0' && ch <= '9')
//         {
//             shuzi++;
//         }
//         else if (ch == ' ')
//         {
//             kongge++;
//         }
//         else
//         {
//             others++;
//         }
//     }
//     printf("%d %d %d %d", zimu, shuzi, kongge, others);

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int tmp = 2;
//     int sum = 0;
//     while (n--)
//     {
//         sum += tmp;
//         tmp = tmp * 10 + 2;
//     }
//     printf("%d", sum);

//     return 0;
// }

// int main()
// {
//     long long n;
//     scanf("%lld", &n);
//     long long tmp = 1;
//     long long sum = 0;
//     long long i = 1;
//     while (n--)
//     {
//         sum += tmp;
//         i++;
//         tmp = tmp * i;
//     }
//     printf("%lld", sum);

//     return 0;
// }

// int main()
// {
//     int a, b, c;
//     scanf("%d%d%d", &a, &b, &c);
//     double sum = 0;
//     int i;
//     for (i = 1; i <= a; i++)
//     {
//         sum += i;
//     }
//     for (i = 1; i <= b; i++)
//     {
//         sum += i * i;
//     }
//     for (i = 1; i <= c; i++)
//     {
//         sum += 1.0 / i;
//     }
//     printf("%.2lf", sum);


//     return 0;
// }

// int main()
// {
//     for (int i = 100; i <= 999; i++)
//     {
//         int a, b, c;
//         c = i % 10;
//         b = i / 10 % 10;
//         a = i / 10 / 10;
//         if (i == a * a * a + b * b * b + c * c * c)
//         {
//             printf("%d\n", i);
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int i = 0, j = 0, k = 0;
//     int arr[100] = { 0 };
//     for (i = 2; i <= n;i++)
//     {
//         for (j = 1; j <= i / 2 + 1; j++)
//         {
//             if (i % j == 0)
//             {
//                 arr[k++] = j;
//             }
//         }

//         int sum = 0;
//         for (int tmp = 0; tmp < k; tmp++)
//         {
//             sum += arr[tmp];
//         }
//         if (i == sum)
//         {
//             printf("%d its factors are", i);
//             for (int tmp = 0; tmp < k; tmp++)
//             {
//                 printf(" %d", arr[tmp]);
//                 arr[tmp] = 0;
//             }
//             putchar('\n');
//         }
//         k = 0;
//     }

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     double i, j, k;
//     i = 1.0; j = 1.0;
//     double sum = 0.0;
//     for (int tmp = 0; tmp < n; tmp++)
//     {
//         k = i + j;
//         sum += k / i;
//         j = i, i = k;
//     }
//     printf("%.2lf", sum);

//     return 0;
// }

// int main()
// {
//     int n;
//     double m;
//     scanf("%lf %d", &m, &n);
//     double sum = 0.0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += m*1.5;
//         m /= 2.0;
//     }
//     sum -= m;
//     printf("%.2lf %.2lf", m, sum);

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int tmp = 1;
//     while (--n)
//     {
//         tmp++;
//         tmp *= 2;
//     }
//     printf("%d", tmp);

//     return 0;
// }

// int main()
// {
//     double a;
//     scanf("%lf", &a);
//     double tmp1, tmp2;
//     tmp2 = 1.0;
//     while (1)
//     {
//         tmp1 = tmp2;
//         tmp2 = 0.5*(tmp1 + a / tmp1);
//         if (abs(tmp1 - tmp2) < 0.00001)
//         {
//             printf("%.3lf", tmp2);
//             break;
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int i, j;
//     for (i = 2; i <= n; i++)
//     {
//         for (j = 2; j < i; j++)
//         {
//             if (i % j == 0)
//             {
//                 break;
//             }
//         }
//         if (j == i)
//         {
//             printf("%d\n", i);
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int arr[10];
//     int i, j;
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     for (i = 0; i < 10; i++)
//     {
//         for (j = 0; j < 10 - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//             }
//         }
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d\n", arr[i]);
//     }

//     return 0;
// }

// int main()
// {
//     int arr[3][3];
//     int i, j;
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     printf("%d %d", arr[0][0] + arr[1][1] + arr[2][2], arr[0][2] + arr[1][1] + arr[2][0]);

//     return 0;
// }

// int main()
// {
//     int arr[9];
//     for (int i = 0; i < 9; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     int n;
//     scanf("%d", &n);
//     int judge = 0;
//     for (int i = 0; i < 9; i++)
//     {
//         if (arr[i] < n)
//         {
//             printf("%d\n", arr[i]);
//             continue;
//         }

//         if (judge == 0)
//         {
//             printf("%d\n%d\n", n, arr[i]);
//             judge++;
//         }
//         else
//         {
//             printf("%d\n", arr[i]);
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int arr[10];
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("%d", arr[--i]);
//     for (--i; i >= 0; i--)
//     {
//         printf(" %d", arr[i]);
//     }

//     return 0;
// }

// int yue(int m, int n)
// {
//     int tmp = 0;
//     do
//     {
//         tmp = m % n;
//         m = n;
//         n = tmp;
//     } while (tmp);

//     return m;
// }
// int bei(int m, int n)
// {
//     int tmp = yue(m, n);
//     return m * n / tmp;
// }

// int main()
// {
//     int m, n;
//     scanf("%d%d", &m, &n);
//     printf("%d %d", yue(m, n), bei(m, n));

//     return 0;
// }

// int main()
// {
//     int a, b, c;
//     scanf("%d%d%d", &a, &b, &c);
//     int tmp = b * b - 4 * a * c;
//     double x = -(double)b * 0.5 / (double)a;
//     if (tmp == 0)
//     {
//         printf("x1=%.3lf x2=%.3lf", x, x);
//     }
//     else if (tmp > 0)
//     {
//         printf("x1=%.3lf+%.3lf x2=%.3lf-%.3lf", x, sqrt(tmp) * 0.5 / (double)a, x, sqrt(tmp) * 0.5 / (double)a);
//     }
//     else
//     {
//         printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi", x, sqrt(-tmp) * 0.5 / (double)a, x, sqrt(-tmp) * 0.5 / (double)a);
//     }

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int i;
//     for (i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             break;
//         }
//     }
//     if (n == i)
//     {
//         puts("prime");
//     }
//     else
//     {
//         puts("not prime");
//     }

//     return 0;
// }

// int main()
// {
//     int arr[3][3];
//     int i, j;
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j <= i; j++)
//         {
//             int tmp = arr[i][j];
//             arr[i][j] = arr[j][i];
//             arr[j][i] = tmp;
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         putchar('\n');
//     }

//     return 0;
// }

// char str[10005];
// int main()
// {
//     gets(str);
//     int right = strlen(str) - 1;
//     int left = 0;
//     while (left < right)
//     {
//         char tmp = str[left];
//         str[left] = str[right];
//         str[right] = tmp;
//         right--;
//         left++;
//     }
//     puts(str);

//     return 0;
// }

// char s1[20005];
// char s2[10005];
// int main()
// {
//     gets(s1);
//     gets(s2);
//     strcat(s1, s2);
//     puts(s1);

//     return 0;
// }

// char s1[10005];
// char s2[10005];
// int main()
// {
//     gets(s1);
//     int i = 0;
//     int j = 0;
//     while (s1[i] != '\0')
//     {
//         if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
//         {
//             s2[j] = s1[i];
//             j++;
//         }
//         else if (s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U')
//         {
//             s2[j] = s1[i];
//             s2[j] = tolower(s2[j]);
//             j++;
//         }

//         i++;
//     }
//     puts(s2);

//     return 0;
// }

// int main()
// {
//     char arr[5];
//     gets(arr);
//     int i;
//     putchar(arr[0]);
//     for (i = 1; i < 4; i++)
//     {
//         printf(" %c", arr[i]);
//     }

//     return 0;
// }

// int main()
// {
//     int zimu = 0, shuzi = 0, kongge = 0, qita = 0;
//     int ch;
//     while ((ch = getchar()) != EOF && ch != '\n')
//     {
//         if (ch >= '0' && ch <= '9')
//         {
//             shuzi++;
//         }
//         else if (ch == ' ')
//         {
//             kongge++;
//         }
//         else if ((ch >= 'a' && ch <= 'z') || (ch>='A' && ch<='Z'))
//         {
//             zimu++;
//         }
//         else
//         {
//             qita++;
//         }
//     }

//     printf("%d %d %d %d", zimu, shuzi, kongge, qita);

//     return 0;
// }

// int main()
// {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     printf("%d %d", b, a);

//     return 0;
// }

// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     printf("%d", a % b);

//     return 0;
// }

// int main()
// {
//     double a, b, c;
//     scanf("%lf%lf%lf", &a, &b, &c);
//     double s = (a + b + c) / 2.0;
//     printf("%.3lf", sqrt(s * (s - a) * (s - b) * (s - c)));

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//     {
//         puts("L");
//     }
//     else
//     {
//         puts("N");
//     }

//     return 0;
// }

// int main()
// {
//     float x;
//     scanf("%f", &x);
//     printf("%6.2f\n", x);
//     printf("%6.2f%6.2f\n", x, x, x);
//     printf("%6.2f%6.2f%6.2f\n", x, x, x);

//     return 0;
// }

// int main()
// {
//     double a, b, c;
//     scanf("%lf%lf%lf", &a, &b, &c);
//     a = a > b ? a : b;
//     a = a > c ? a : c;
//     printf("%.3lf\n%.3lf", a, a);

//     return 0;
// }

// int main()
// {
//     char arr[10000];
//     int ch;
//     int i = 0;
//     while ((ch = getchar()) != EOF)
//     {
//         if (ch >= 'a' && ch < 'z')
//         {
//             ch++;
//         }
//         else if (ch == 'z')
//         {
//             ch = 'a';
//         }

//         arr[i++] = ch;
//     }
//     arr[i] = '\0';
//     puts(arr);

//     return 0;
// }
// 
// int main()
// {
//     int a, b, c;
//     scanf("%d%d%d", &a, &b, &c);
//     if (a > b)
//     {
//         int tmp = a;
//         a = b;
//         b = tmp;
//     }
//     if (b > c)
//     {
//         int tmp = b;
//         b = c;
//         c = tmp;
//     }
//     if (a > b)
//     {
//         int tmp = a;
//         a = b;
//         b = tmp;
//     }
//     printf("%d %d %d ", a, b, c);

//     return 0;
// }

// int main()
// {
//     char s1[55], s2[55], s3[55], tmp[55];
//     gets(s1), gets(s2), gets(s3);
//     if (strcmp(s1, s2) > 0)
//     {
//         strcpy(tmp, s1);
//         strcpy(s1, s2);
//         strcpy(s2, tmp);
//     }
//     if (strcmp(s2, s3) > 0)
//     {
//         strcpy(tmp, s2);
//         strcpy(s2, s3);
//         strcpy(s3, tmp);
//     }
//     if (strcmp(s1, s2) > 0)
//     {
//         strcpy(tmp, s1);
//         strcpy(s1, s2);
//         strcpy(s2, tmp);
//     }
//     puts(s1), puts(s2), puts(s3);

//     return 0;
// }

// int main()
// {
//     int arr[10];
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     int min_index = 0, max_index = 0, min_num = arr[0], max_num = arr[0];
//     for (i = 0; i < 10; i++)
//     {
//         if (arr[i] < min_num)
//         {
//             min_num = arr[i];
//             min_index = i;
//         }
//         if (arr[i] > max_num)
//         {
//             max_num = arr[i];
//             max_index = i;
//         }
//     }
//     int tmp;
    
//     tmp = arr[0];
//     arr[0] = arr[min_index];
//     arr[min_index] = tmp;

//     tmp = arr[9];
//     arr[9] = arr[max_index];
//     arr[max_index] = tmp;
    
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// int main()
// {
//     int a, b;
//     int s1[1000];
//     int s2[1000];
//     scanf("%d", &a);
//     int i, j;
//     for (i = 0; i < a; i++)
//     {
//         scanf("%d", &s1[i]);
//     }
//     scanf("%d", &b);
//     for (j = b, i = 0; j < a; j++, i++)
//     {
//         s2[j] = s1[i];
//     }
//     for (i = 0, j = a - b; j < a; j++, i++)
//     {
//         s2[i] = s1[j];
//     }
//     for (i = 0; i < a; i++)
//     {
//         printf("%d ", s2[i]);
//     }

//     return 0;
// }

// int arr[1000];
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         arr[i] = 1;
//     }
    
//     int alive = n;
//     int count = 0;
//     int index;
//     while (alive > 1)
//     {
//         index = 0;
//         while (index < n)
//         {
//             if (arr[index] != 0)
//             {
//                 count++;
//                 if (count == 3)
//                 {
//                     arr[index] = 0;
//                     count = 0;
//                     alive--;
//                 }
//             }

//             index++;
//         }
//     }
    
//     for (i = 0; i < n; i++)
//     {
//         if (arr[i] == 1)
//         {
//             printf("%d", i + 1);
//             break;
//         }
//     }

//     return 0;
// }

// int main()
// {
//     char arr[10000];
//     int a,b;
//     scanf("%d", &a);
//     scanf("%s", arr);
//     scanf("%d", &b);
//     strcpy(arr, arr + b - 1);
//     puts(arr);

//     return 0;
// }


// typedef struct shijian
// {
//     int year;
//     int mon;
//     int day;
// }shijian;
// int runnian(int n)
// {
//     return ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0);
// }
// int main()
// {
//     shijian tmp;
//     scanf("%d%d%d", &tmp.year, &tmp.mon, &tmp.day);
//     int judge = runnian(tmp.year);
//     int ret = 0;
//     if (judge != 0)
//     {
//         int arr[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//         for (int i = 0; i < tmp.mon - 1; i++)
//         {
//             ret += arr[i];
//         }
//         ret += tmp.day;
//     }
//     else
//     {
//         int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//         for (int i = 0; i < tmp.mon-1; i++)
//         {
//             ret += arr[i];
//         }
//         ret += tmp.day;
//     }

//     printf("%d", ret);

//     return 0;
// }

// typedef struct Student
// {
//     int a, b, c;
//     char name[24];
//     char num[24];
// }Student;
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     Student* student = (Student*)malloc(sizeof(Student) * n);
//     Student* tmp = student;
//     Student* ret = student;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%s%s%d%d%d", student->num, student->name, &student->a, &student->b, &student->c);
//         student++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         printf("%s,%s,%d,%d,%d\n", tmp->num, tmp->name, tmp->a, tmp->b, tmp->c);
//         tmp++;
//     }
//     free(ret);


//     return 0;
// }

// typedef struct Student
// {
//     int a, b, c;
//     char name[48];
//     char num[48];
// }Student;
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int sum1 = 0; int sum2 = 0; int sum3 = 0;
//     int max_code = -1;
//     Student* student = (Student*)malloc(sizeof(Student) * n);
//     Student* tmp = student;
//     Student* ret = student;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%s%s%d%d%d", student->num, student->name, &student->a, &student->b, &student->c);
//         sum1 += student->a;
//         sum2 += student->b;
//         sum3 += student->c;
//         int tmp1 = student->a + student->b + student->c;
//         if (tmp1 > max_code) max_code = tmp1;
//         student++;
//     }
//     printf("%.0lf %.0lf %.0lf\n", (double)sum1 / (double)n, (double)sum2 / (double)n, (double)sum3 / (double)n);
//     for (int i = 0; i < n; i++)
//     {
//         int tmp1 = tmp->a + tmp->b + tmp->c;
//         if (tmp1 == max_code)
//         {
//             printf("%s %s %d %d %d\n", tmp->num, tmp->name, tmp->a, tmp->b, tmp->c);
//             break;
//         }
//         tmp++;
//     }
//     free(ret);

//     return 0;
// }

typedef struct Student Student;

struct Student
{
    int num;
    int codes;
    Student* next;
};
void insert(Student* p)
{
    Student* tmp = (Student*)malloc(sizeof(Student));
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
    scanf("%d%d", &tmp->num, &tmp->codes);
    tmp->next = NULL;
}
void selectsort(Student* p)
{
    Student* q = p;
    Student* tmp = p;
    Student* small = p;
    int flag;

    for (p = p->next; p->next != NULL; p = p->next)
    {
        small = p;
        for (q = p->next; q; q = q->next)
        {
            if (q->num < small->num)
            {
                small = q;
            }
        }

        if (small != p)
        {
            flag = p->num;
            p->num = small->num;
            small->num = flag;

            flag = p->codes;
            p->codes = small->codes;
            small->codes = flag;
        }
    }
}
int main()
{
    int size = sizeof(Student);
    int a, b;
    scanf("%d %d", &a, &b);
    Student* head1 = (Student*)malloc(size);
    head1->next = NULL;
    Student* head2 = (Student*)malloc(size);
    head2->next = NULL;
    for (int i = 0; i < a; i++)
    {
        insert(head1);
    }
    for (int i = 0; i < b; i++)
    {
        insert(head2);
    }
    Student* p = head1;
    while (p->next != NULL)
        p = p->next;

    p->next = head2->next;
    p = head1;
    selectsort(p);
    p = p->next;
    while (p)
    {
        printf("%d %d\n", p->num, p->codes);
        p = p->next;
    }


    return 0;
}
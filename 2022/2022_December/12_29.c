#include"test1.h"

// int main()
// {
//     unsigned long long sum = 0;
//     int n;
//     scanf("%d", &n);
//     unsigned long long ret = 1;
//     for(int i = 1; i<=n; i++)
//     {
//         ret *= i;
//         sum += ret;
//     }
//     printf("%llu", sum);
//     return 0;
// }

// int judge(char s1[])
// {
//     int a = strlen(s1)-1;
//     int i;
//     int count = 0;
//     for(i = 0; i<=a; i++)
//     {
//         if(s1[i] == s1[a-i])
//         {
//             count++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     if(count == a+1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int main()
// {
//     char s1[105] = {0};
//     char s2[105] = {0};
//     char s3[105] = {0};
//     int n;
//     scanf("%d", &n);
//     scanf("%s", s1);
//     int a = strlen(s1)-1;
//     int i;
//     int ans = -1;
//     int m = 30;
//     int count = 0;
//     while(m--)
//     {
//         count++;
//         a = strlen(s1)-1;
//         for(i = 0; i<=a; i++)
//         {
//             s2[i] = s1[a-i];
//         }

//         for(i = a; i>=0; i--)
//         {
//             s3[i+1] += s1[i] + s2[i] - 2*'0';
//             if(s3[i+1] - '0' >= n)
//             {
//                 s3[i+1] -= n;
//                 s3[i]++;
//             }
//         }
//         if(s3[0] == 0)
//         {
//             for(i = 0; i<a+1; i++)
//             {
//                 s3[i] = s3[i+1];
//             }
//             a--;
//         }
//         for(i = 0; i<a+2; i++)
//         {
//             s1[i] = s3[i];
//         }
//         for(i = 0; i<105; i++)
//         {
//             s3[i] = '0';
//         }

//         if(judge(s1) == 1)
//         {
//             ans = count;
//             break;
//         }
//     }

//     if(ans > 0)
//     {
//         printf("STEP=%d\n", ans);
//     }
//     else
//     {
//         puts("Impossible!");
//     }
    

//     return 0;
// }

// int main()
// {
//     int num;
//     scanf("%d", &num);
//     int arr[32] = {0};
//     int i = 31;
//     do
//     {
//         arr[i] = num%2;
//         num/=2;
//         i--;
//     } while (num);
//     for(i = 0; i<16; i++)
//     {
//         int tmp = arr[i];
//         arr[i] = arr[i+16];
//         arr[i+16] = tmp;
//     }
//     unsigned int sum = 0;
//     for(i = 31; i>=0; i--)
//     {
//         sum += arr[i]*pow(2, 31-i);
//     }
//     printf("%u", sum);
    
//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%u", (n>>16) + (n<<16));
//     return 0;
// }

int main()
{
    print();
    system("pause");
    return 0;
}
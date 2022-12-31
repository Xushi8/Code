#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int main()
// {
// 	int n;
// 	scanf("%d", &n);
// 	int arr[n];
// 	int i;
// 	int count = 0;
// 	for(i = 0; i<n; i++)
// 	{
// 		scanf("%d", &arr[i]);
// 		if(arr[i] == 5)
// 		{
// 			count++;
// 		}
// 	}
// 	if(count == n)
// 	{
// 		printf("-1");
// 	}
// 	else if(count < n && count%9 == 0)
// 	{
// 		for(int i = 0; i<count; i++)
// 		{
// 			printf("5");
// 		}
// 		for(int i = 0; i<n-count; i++)
// 		{
// 			printf("0");
// 		}
// 	}
// 	else
// 	{
// 		int ret = count/9;
// 		if(ret != 0)
// 		{
// 			for(int i = 0; i<ret*9; i++)
// 			{
// 				printf("5");
// 			}
// 			for(int i = 0; i<n-count; i++)
// 			{
// 				printf("0");
// 			}
// 		}
// 		else
// 		{
// 			printf("0");
// 		}
// 	}
// 	return 0;
// } 

// int main()
// {
// 	int n;
// 	scanf("%d", &n);
// 	int data[n][n];
// 	memset(data,0,sizeof(data));
// 	int arr[2][n];
// 	memset(arr,0,sizeof(arr));
// 	int i,j;
// 	for(i = 0; i<n; i++)
// 	{
// 		for(j = 0; j<n; j++)
// 		{
// 			scanf("%d", &data[i][j]);
// 			arr[0][i] += data[i][j];
// 		}
// 	}

// 	for(j = 0; j<n; j++)
// 	{
// 		for(i = 0; i<n; i++)
// 		{
// 			arr[1][j] += data[i][j];
// 		}
// 	}
	
// 	int max = -1;
// 	int judge = 0;
// 	for(i = 0; i<n; i++)
// 	{
// 		for(j = 0; j<n; j++)
// 		{
// 			if(data[i][j] == 0)
// 			{
// 				int sum = arr[0][i]+arr[1][j];
// 				if(sum>max)
// 				{
// 					max = sum;
// 					judge = 1;
// 				}
// 			}
// 		}
// 	}	
// 	if(judge == 0)
// 	{
// 		puts("Bad Game!");
// 	}
// 	else
// 	{
// 		printf("%d", max);
// 	}
	

// 	return 0;
// }

// int main()
// {
// 	double a;
// 	double sum = 0;
// 	while(scanf("%lf", &a) != EOF)
// 	{
// 		sum += a*1e6;
// 	}
// 	printf("%.5lf", sum/1e6);
// 	return 0;
// }

// int main()
// {
// 	long double a;
// 	scanf("%20Lf", &a);
// 	printf("%.8Lf", a*100000000/23/100000000);
// 	return 0;
// }


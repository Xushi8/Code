#include<stdio.h>
#include<stdlib.h>
int arr1[100000001] = {0};
int arr2[100000001] = {0};
int main()
{

    int i, j;
    for(i = 0; i<=1000; i++)
    {
        scanf("%d", &arr1[i]);
        if(getchar()=='\n')
        {
            break;
        }
    }
    for(j = 1; j<=i; j++)
    {
        arr2[abs(arr1[j]-arr1[j+1])] = 1;
    }
    for(j = 1; j<=i-1; j++)
    {
        if(arr2[j]==0)
        {
            printf("Not jolly\n");
            system("pause");
            return 0;
        }
    }
    printf("Jolly\n");

    system("pause");
    return 0;
}
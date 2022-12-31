#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* int main()
{
    int i;
    srand((unsigned int)time(NULL));
    int count1, count2, count3, count4, count5, count6;
    for(i = 0; i<=6000000; i++)
    {
        int count = rand()%6+1;
        printf("%d ", count);
        switch(count)
        {
            case 1:
            count1++;
            break;
            case 2:
            count2++;
            break;
            case 3:
            count3++;
            break;
            case 4:
            count4++;
            break;
            case 5:
            count5++;
            break;
            case 6:
            count6++;
            break;
        }
    }
    printf("%d %d %d %d %d %d",count1,count2, count3, count4, count5,count6);
    system("pause");
    return 0;
} */

int main()
{
    srand((unsigned int)time(NULL));
    int x, y;
    int sum;
    x = rand()%6+1;
    y = rand()%6+1;
    sum = x+y;
    if(sum == 7 || sum == 11)
    {
        printf("玩家胜利\n");
        system("pause");
        return 0;
    }
    else if(sum == 2 ||sum == 3 || sum ==12)
    {
        printf("庄家胜利\n");
        system("pause");
        return 0;
    }
    while(1)
    {
        x = rand()%6+1;
        y = rand()%6+1;
        sum = x+y;
        switch(sum)
        {
            case 4:
            case 5:
            case 6:
            puts("玩家胜利");
            system("pause");
            return 0;
            case 8:
            case 9:
            case 10:
            puts("玩家胜利");
            system("pause");
            return 0;
            case 7:
            puts("庄家胜利");
            system("pause");
            return 0;
        }
    }

    system("pause");
    return 0;
}
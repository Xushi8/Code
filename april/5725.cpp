// 2023/04/27 12:08:53
#include <bits/stdc++.h>
using namespace std;



int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin >> n;
    int a = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%02d", a++);
        }
        printf("\n");
    }
    printf("\n");
    a = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1 && i != n - 1)
            {
                printf("  ");
            }
            else
            {
                printf("%02d", a++);
            }
        }
        printf("\n");
    }

    cout << endl;
    return 0;
}
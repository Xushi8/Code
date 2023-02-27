#include <iostream>
using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     //关闭IO后，cin/cout将使用独立缓冲区，而不是将输出同步至scanf/printf的缓冲区，从而减少IO耗时
//     cout << "a\n";
//     //cout下，使用'\n'换行时，内容会被缓冲而不会被立刻输出，应该使用endl来换行并立刻刷新缓冲区
//     int ch;
//     while((ch = getchar()) != '\n')
//         putchar(ch);
    
//     printf("b\n");
//     //printf的'\n'会刷新printf的缓冲区，导致输出错位
//     cout << "c\n";
//     system("pause");
//     return 0;//程序结束时，cout的缓冲区才会被输出
// }

// int main()
// {
//     cout << "a\n";
//     cout << "dfs";
//     cout << "34343";
//     printf("b\n");
//     cout << "c \n";

    
//     system("pause");
//     return 0;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << "a\n";
    printf("5\n");
    int a;
    cin >> a;
    cout << a << endl;
    

    system("pause");
    return 0;
}


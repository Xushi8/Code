#include <bits/stdc++.h>
using namespace std;


char str[1000005], tmp[1005];
int ne[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // bool a = 1, b = 0;
    // bool x = a and b;
    // cout << x << endl;
    // bool y = a or b;
    // cout << y << endl;

    // cout << CHAR_BIT << endl;
    // uint8_t a = 0b00001011;

    // cin >> str + 1;
    // size_t str_len = strlen(str + 1);
    // int tt;
    // cin >> tt;

    int tt;
    scanf("%s %d", str + 1, &tt);
    size_t str_len = strlen(str + 1);
    
    while (tt--)
    {
        // cin >> tmp + 1;
        scanf("%s", tmp + 1);
        
        // size_t len = strlen(tmp + 1);
        // for (size_t i = 2, j = 0; i <= len; i++)
        // {
        //     while (j && tmp[i] != tmp[j + 1])
        //         j = ne[j];
        //     if (tmp[i] == tmp[j + 1])
        //         j++;
        //     ne[i] = j;
        // }
        // int flag = 0;
        // for (size_t i = 1, j = 0; i <= str_len; i++)
        // {
        //     while (j && str[i] != tmp[j + 1])
        //         j = ne[j];
        //     if (str[i] == tmp[j + 1])
        //         j++;
        //     if (j == len)
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }
        // cout << flag << '\n';

        char* p = strstr(str + 1, tmp + 1);
        if (p == nullptr) puts("0");
        else puts("1");

        // memset(ne, 0, len * 4 + 4);
    }

    cout << flush;
    ::system("pause");
    return 0;
}
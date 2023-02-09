#include<bits/stdc++.h>
using namespace std;
int n, m;

int _2_to_10(int j)
{
    int ret_val = 0;
    char buf[64];
    sprintf(buf, "%d", j);
    int len = (int)strlen(buf);
    reverse(buf, buf + len);
    int tmp = 1;
    for (int i = 0; i < len; i++)
    {
        ret_val += (buf[i] - '0') * tmp;
        tmp *= 2;
    }
    return ret_val;
}
int _10_to_2(int j)
{
    char buf[64] = {0};
    int i = 0;
    while (j)
    {
        buf[i++] = (char)(j % 2 + '0');
        j /= 2;
    }
    reverse(buf, buf + (int)strlen(buf));
    return atoi(buf);
}
int main()
{
    do
    {
        //system("cls");
        cout << "请操作的数字, 2为二进制, 10位十进制" << endl;
        cin >> n;
        switch (n)
        {
        case 2:
            cout << "请输入数字" << endl;
            cin >> m;
            cout << "转换成十进制是: " << _2_to_10(m) << endl;
            break;
        case 10:
            cout << "请输入数字" << endl;
            cin >> m;
            cout << "转换成二进制是: " << _10_to_2(m) << endl;
            break;
        default:
            break;
        }
    } while (n);

    system("pause");
    return 0;
}
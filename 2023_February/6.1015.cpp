#include<bits/stdc++.h>
using namespace std;
int n, m;

char a[100], b[100], tmp[100];
void ADD()
{
    memset(tmp, -1, sizeof(tmp));
    for (int i = 0; i < strlen(a); i++)
    {
        tmp[i] += a[i] + b[i];
        tmp[i + 1] = tmp[i] / n;
        tmp[i] %= n;
    }
    reverse(tmp, tmp + strlen(tmp));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> a;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            a[i] -= '0';
        }
        else
        {
            a[i] = a[i] - 'a' + 11;
        }
    }
    
    int ans = 0;
    while (1)
    {
        memcpy(b, a, strlen(a) + 1);
        reverse(b, b + strlen(b));
        ADD();
        ans++;
        memcpy(a, tmp, strlen(tmp) + 1);
        memcpy(b, a, strlen(a) + 1);
        reverse(b, b + strlen(b));
        if (strcmp(a, b) == 0)
            break;
        if (ans > 30)
            break;

    }
    if (ans > 30) cout << "Impossible!" << endl;
    else cout << "STEP=" << ans << endl;

    system("pause");
    return 0;
}
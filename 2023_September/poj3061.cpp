#include <cstdio>


int arr[100005];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int n, S;
        scanf("%d%d", &n, &S);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int sum = 0;
        int s = 0, t = 0;
        int ans = 0x3f3f3f3f;
        while (1)
        {
            while (t < n && sum < S)
            {
                sum += arr[t++];
            }

            if (sum < S)
                break;

            ans = min(ans, t - s);
            sum -= arr[s++];
        }

        printf("%d\n", ans == 0x3f3f3f3f ? 0 : ans);
    }

    return 0;
}
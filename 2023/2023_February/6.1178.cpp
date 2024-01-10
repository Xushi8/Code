#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;
int n, m;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    vector<int> mon(tt), sec(tt);
    for (int i = 0; i < tt; i++)
    {
        cin >> mon[i] >> sec[i];
    }
    int max_ = -1;
    int arr[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    for (int i = 0; i < tt - 1; i++)
    {
        int tmp = 0;
        if (mon[i] == mon[i + 1])
        {
            tmp = abs(sec[i + 1] - sec[i]);
        }
        else
        {
            if (mon[i] > mon[i + 1])
            {
                for (int j = mon[i + 1] + 1; j < mon[i]; j++)
                {
                    tmp += arr[j];
                }
                tmp += sec[i];
                tmp += arr[mon[i + 1]] - sec[i + 1];
            }
            else
            {
                for (int j = mon[i] + 1; j < mon[i + 1]; j++)
                {
                    tmp += arr[j];
                }
                tmp += sec[i + 1];
                tmp += arr[mon[i]] - sec[i];
            }
        }

        if (tmp > max_) max_ = tmp;
        
    }
    max_--;
    double tmp = (((double)max_ / 366.0) * 3600 * 24);

    
    printf("%.0lf", tmp + 0.5);

    system("pause");
    return 0;
}
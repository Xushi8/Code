#include<bits/stdc++.h>
using namespace std;

#define sort random_shuffle

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    sort(arr, arr + 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    const int tmp = 10;
    *(int*)&tmp = 20;
    cout << tmp << endl;
    int a = 0;
    a = tmp;
    cout << a << endl;

    system("pause");
    return 0;
}
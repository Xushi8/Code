#include <bits/stdc++.h>

using namespace std;

//int main()
//{
//    int a;
//    cin >> a;
//    for(int i = 0; i < 1000; i++)
//    {
//
//        cout << a <<endl;
//    }
//    return 0;
//}



int main()
{
    vector<vector<int>> arr(100, vector<int>(100));
    for(int i = 0; i < 100; i++)
    {

        for(int j = 0; j < 100; j++)
        {

            arr[i][j] = i * j;
        }
    }

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            cout << arr[i][j] << ' ';
        }
    }
    cout << flush;

    return 0;
}

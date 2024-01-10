// 2023/05/01 11:52:42
#include <bits/stdc++.h>
using namespace std;

// bool is_power_of_two(uint64_t n)
// {
//     if (n == 0 || n == 1)
//         return false;
    
//     bool flag = 1;
//     for (int i = 0; i < 64; i++)
//     {
//         if (n >> i & 1)
//         {
//             if (flag)
//             {
//                 flag = 0;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

bool is_power_of_two(uint64_t n)
{
    return (n != 0) && ((n & -n) == n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ofstream ofs;
    ofs.open("is_power_of_two");
    for (int i = 0; i < 100000000; i++)
    {
        ofs << is_power_of_two(i) << '\n';
    }


    
    ofs.close();
    ofs.open("is_power_of_two");
    ofs.close();
    cout << endl;
    return 0;
}
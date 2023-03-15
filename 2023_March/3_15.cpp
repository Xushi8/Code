#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, jiange;
//     cin >> n >> jiange;
//     queue<string> name;
//     queue<int> q;
//     for (int i = 0; i < n; i++)
//     {
//         string _name;
//         int tmp;
//         cin >> _name >> tmp;
//         name.push(_name);
//         q.push(tmp);
//     }

//     int time = 0;
//     while (!q.empty())
//     {
//         if (q.front() <= jiange)
//         {
//             cout << name.front() << ' ' << time + q.front() << '\n';
//             time += q.front();
//             q.pop();
//             name.pop();
//         }
//         else
//         {
//             q.front() -= jiange;
//             q.push(q.front());
//             q.pop();
//             name.push(name.front());
//             name.pop();
//             time += jiange;
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    cout << flush;
    system("pause");
    return 0;
}
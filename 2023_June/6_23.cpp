// 2023/05/25 15:17:41
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int V, E;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll arr[105][105];

struct edge
{
    edge(ll a, ll b, ll c)
    {
        from = a;
        to = b;
        cost = c;
    }
    ll from, to, cost;
};
vector<edge> G;
ll dis[105];
// bool find_negative_circle()
// {
//     memset(dis, 0, sizeof(dis));
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < E; j++)
//         {
//             const edge& e = G[j];
//             if (dis[e.to] > dis[e.from] + e.cost)
//             {
//                 dis[e.to] = dis[e.from] + e.cost;
//                 if (i == V - 1)
//                     return true;
//             }
//         }
//     }
//     return false;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(arr, 0x3f, sizeof(arr));
    cin >> V >> E;
    for (int i = 0; i < V; i++)
    {
        arr[i][i] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
        // G.emplace_back(a, b, c);
    }


    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (arr[i][k] != INF && arr[k][j] != INF && arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];

    bool flag = 0;
    for (int i = 0; i < V; i++)
    {
        if (arr[i][i] < 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << "NEGATIVE CYCL\n";
    else
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                if (arr[i][j] >= 0x3f3f3f3f3f)
                    cout << "INF ";
                else
                    cout << arr[i][j] << ' ';
            cout << '\n';
        }
    }





    cout << flush;
    return 0;
}
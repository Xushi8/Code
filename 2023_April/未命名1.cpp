#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
	int to, cost;
	edge(const int& a, const int& b)
	{
		to = a;
		cost = b;	
	}	
};
const int max_v = 1005, inf = 0x3f3f3f3f;
vector<edge> G[max_v];
int dis[max_v];
typedef pair<int, int> P;
void dijkstra(int start)
{
	priority_queue<P, vector<P>, greater<P>> que;
	fill(dis, dis + max_v, inf);
	dis[start] = 0;
	que.emplace_back(0, start);
	while(!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
    	int a, b, c;
    	cin >> a >> b >> c;
	}
    
    cout << flush;
    return 0;
}

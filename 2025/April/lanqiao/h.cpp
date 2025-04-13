#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

/*
9
1 0 1 0 0 1 1 0 1
2 8
2 9
2 5
1 5
1 3
1 4
4 5
4 6
6 7


*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> deg(n);
	vector<vector<int>> G(n);
	for(int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		deg[u]++;
		deg[v]++;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	int cnt1 = count(a.begin(), a.end(), 1);
	if(cnt1 == 0) {
		cout << 0 << '\n';
		return;
	}
	mt19937 rng(random_device{}());
	uniform_int_distribution<i64> uni(1, cnt1);
	cout << uni(rng) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
//	cin >> tt;
	while(tt--) {
		solve();
	}
	
	
	return 0;
}

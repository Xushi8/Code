#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

/*


4
3 2 4 1
2 2 2 2
4 3 0 9

1
1 1 1



*/

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(3, vector<int>(n));
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	array<int, 3> now{};
	i64 ans = 0;
	
	int m;
	cin >> m;
	while(m--) {
		array<int, 3> t;
		for(int i = 0; i < 3; i++) {
			int x;
			cin >> x;
			now[i] = (now[i] + x) % n;
			t[i] = a[i][now[i]];
		}
		
//		cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
		
		if(t[0] + 1 == t[1] && t[1] + 1 == t[2]) {
			ans += 200;
			continue;
		}
		
		sort(t.begin(), t.end());
		
		if(t[0] + 1 == t[1] && t[1] + 1 == t[2]) {
			ans += 100;
			continue;
		}
		
		
		if(t[0] == t[1] && t[1] == t[2]) {
			ans += 200;
			continue;
		}
		if((t[0] == t[1] && t[1] != t[2]) || (t[0] != t[1] && t[1] == t[2])) {
			ans += 100;
			continue;
		}
	}
	
	cout << ans << '\n';
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

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<pii> a;
	for(int i = 0; i < n; ) {
		int j;
		for(j = i + 1; j < n && (s[i] == s[j] || s[i] + 1 == s[j]); j++) {}
		
		if(j - i > 1) {
			a.emplace_back(i, j - 1);
		}
		i = j;
	}
	
	if(a.empty()) {
		cout << (n + (n - 1)) << '\n';
		return;
	}
	
	i64 ans = 0;
	for(int l = 0; l < n; l++) {
		auto it = upper_bound(a.begin(), a.end(), pii{l, -1});
		if(it != a.begin()) {
			it--;
		}
		
		if(it == a.end() || it->second < l || it->first > l) { // 不在 
			if(it == a.end()) {
				ans += 2;
				continue;
			}
			if(it->first == l + 1 || (it + 1 != a.end() && (it + 1)->first == l + 1)) { // 这个或下一个相邻 
				int nr;
				if(it->first == l + 1) { // 这个相邻 
					nr = it->second;
				} else { // 下一个相邻 
					nr = (it + 1)->second;
				}
				ans += nr - l + 1;
				continue;
			}
			
			ans += 2;
			if(l == n - 1) {
				ans--;
			}
		} else { // 在 
			if(it + 1 != a.end() && (it + 1)->first == it->second + 1) { // 下一个正好与这个相邻 
				int nr = (it + 1)->second;
				ans += nr - l + 1;
			} else { // 不相邻 
				int nr = it->second + 1;
				nr = min(nr, n - 1);
				ans += nr - l + 1;
			}
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

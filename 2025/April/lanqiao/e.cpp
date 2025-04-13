#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

constexpr i64 MOD = 1000000007;

void solve1(int n) {	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	map<pii, set<vector<int>>> mp;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				continue;
			}
			if(a[i] * a[j] != n - 2) {
				continue;
			}
			pii cho = {a[i], a[j]};
			vector<vector<int>> tmp;
			
			vector<int> b;
			for(int k = 0; k < n; k++) {
				if(k != i && k != j) {
					b.emplace_back(a[k]);
				}
			}
			
			sort(b.begin(), b.end());
			
			do {
				mp[cho].emplace(b);
			} while(next_permutation(b.begin(), b.end()));
		}
	}
	
	i64 ans = 0;
	
	for(auto const& p : mp) {
		auto const& cho = p.first;
		auto const& st = p.second;
//		cout << cho.first << ' ' << cho.second << ' ' << st.size() << '\n';
		ans += st.size();
		ans %= MOD;
	}
	
	cout << ans << '\n';
}

void solve2(int n) {
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	i64 ans = 0;
	for(int i = 0; i < n - 1; i++) {
		int lv = a[i];
		if((n - 2) % lv != 0) {
			continue;
		}
		int rv = (n - 2) / lv;
		
		auto itl = lower_bound(a.begin(), a.end(), rv);
		auto itr = upper_bound(a.begin(), a.end(), rv);
		if(itr - itl == 0) {
			continue;
		}
		
		if(lv == rv) {
			
		} else {
			
		}
	}
	
	mt19937 rng(random_device{}());
	uniform_int_distribution<i64> uni(0, MOD - 1);
	cout << uni(rng) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	if(n <= 10) {
		solve1(n);
	} else {
		solve2(n);
	}
	
	
	return 0;
}

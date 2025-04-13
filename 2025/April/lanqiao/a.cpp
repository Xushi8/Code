#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

// 17609

constexpr int N = 1e5 + 5;
bool isnp[N];
vector<int> primes;

void get_prime() {
	for(int i = 2; i < N; i++) {
		if(!isnp[i]) {
			primes.emplace_back(i);
		}
		
		for(auto p : primes) {
			if(p * i >= N) {
				break;
			}
			
			isnp[p * i] = 1;
			
			if(i % p == 0) {
				break;
			}
		}
	}
}

int get(int x) {
	return primes[x - 1];
}

void solve() {
	get_prime();
	
	cout << get(1) << ' ' << get(2) << ' ' << get(3) << ' ' << get(4) << ' ' << get(2025) << '\n';
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

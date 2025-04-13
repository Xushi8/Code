#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;


/*
1   0 -1  0 -1 -1
-1 -1 -1  0 -1 -1
-1 -1 -1 -1  0  0
-1 -1 -1 -1 -1 -1
-1 -1  1 -1 -1  1
-1  0 -1 -1  1 -1



*/




/*


1 0 1 0 0 1
0 1 0 0 1 1
1 0 1 1 0 0
0 1 0 1 1 0
0 1 1 0 0 1
1 0 0 1 1 0

101001010011101100010110011001100110


*/

void solve() {
//	cout << (1 << 26) << '\n';

	constexpr int n = 6;
	array<array<int, n>, n> a;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	auto check = [&](array<array<int, n>, n> const& vec) {		
		// row num
		for(int i = 0; i < n; i++) {
			array<int, 2> cnt{};
			for(int j = 0; j < n; j++) {
				cnt[vec[i][j]]++;
			}
			if(cnt[0] != cnt[1]) {
				return false;
			}
		}
		
		for(int j = 0; j < n; j++) {
			array<int, 2> cnt{};
			for(int i = 0; i < n; i++) {
				cnt[vec[i][j]]++;
			}
			if(cnt[0] != cnt[1]) {
				return false;
			}
		}
		
		// row
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n - 2; j++) {
				if(vec[i][j] == vec[i][j + 1] && vec[i][j] == vec[i][j + 2]) {
					return false;
				}
			}
		}
		
		// col
		for(int j = 0; j < n; j++) {
			for(int i = 0; i < n - 2; i++) {
				if(vec[i][j] == vec[i + 1][j] && vec[i][j] == vec[i + 2][j]) {
					return false;
				}
			}
		}
		
		set<array<int, n>> st;
		
		// row unique
		st.clear();
		for(int i = 0; i < n; i++) {
			st.insert(vec[i]);
		}
		
		if(st.size() != n) {
			return false;
		}
		
		// col unique
		st.clear();
		for(int j = 0; j < n; j++) {
			array<int , n> tmp;
			for(int i = 0; i < n; i++) {
				tmp[i] = vec[i][j];
			}
			st.insert(tmp);
		}
		if(st.size() != n) {
			return false;
		}
		
		return true;
	};
	
	for(int S = 0; S < (1 << 26); S++) {
		if(S % 1000 == 0) {
			cout << S << '\n';
		}

		vector<int> tmp(26);
		for(int i = 0; i < 26; i++) {
			tmp[i] =  (S >> i) & 1;
		}
		
		auto b = a;
		int tot = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(b[i][j] == -1) {
					b[i][j] = tmp[tot++];
				}
			}
		}
		
		bool ok = check(b);
		if(ok) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << b[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
			
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << b[i][j];
				}
			}
			cout << '\n';

			return;
		}
	}
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

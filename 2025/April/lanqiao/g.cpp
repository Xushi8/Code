#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;
using pdd = pair<long double, long double>;


/*

1
2 2 1

2
1 3 1
3 1 1

*/

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
//			cin >> a[i][j];
			scanf("%d", &a[i][j]);
		}
	}
	vector<pdd> qujian;
	
	
	for(int i = 0; i < n; i++) {
		long double x = a[i][0];
		long double y = a[i][1];
		long double r = a[i][2];
		
		long double dis = sqrt(x * x + y * y);
		// sin(du_jiao) = r / dis
		// du_jiao = asin(r / dis)
		
		// tan(du_yuan) = y / x;
		// du_yuan = atan(y / x)
		
		long double du_jiao = asin(r / dis);
		long double du_yuan = atan(y / x);
		
		qujian.emplace_back(du_yuan - du_jiao, du_yuan + du_jiao);
	}
	
	sort(qujian.begin(), qujian.end());
	long double now = 0;
	long double ans = 0;
	
	for(int i = 0; i < n; i++) {
		long double du1 = qujian[i].first;
		long double du2 = qujian[i].second;
		
		if(du1 > now) {
			ans += du1 - now;
		}
		now = du2;
	}
	
	const long double pi = acosl(-1);
	ans += pi / 2 - now;
	
	double ans_d = ans / (pi / 2);
	printf("%.3lf", ans_d);
}

int main() {
	int tt = 1;

	while(tt--) {
		solve();
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

struct node {
    int r, val;
};

i64 qpow(i64 a, size_t n) {
    i64 ans = 1;
    for (size_t i = 0; i < n; i++){
        ans *= a;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto get = [](i64 n, int mi) -> node
    {
        i64 sum = 0;
        for (int i = 1; sum <= n; i++) {
            sum += qpow(i, mi);
            if(sum > n) {
                return {-1, -1};
            }
            if(sum == n) {
                return {i, mi};
            }
        }

        return {-1, -1};
    };

    i64 n;
    cin >> n;

    for (int mi = 33; mi > 0; mi--) {
        auto [r, val] = get(n, mi);
        if(r != -1) {
            for (int i = 1; i <= r; i++) {
                if(i != 1) {
                    cout << '+';
                }
                cout << i << '^' << mi;
            }
            cout << '\n';
            return 0;
        }
    }

    cout << "Impossible for " << n << ".\n";
}
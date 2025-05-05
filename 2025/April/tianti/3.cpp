#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxx, op, minn;
    cin >> maxx >> op >> minn;
    if(op && maxx > 35 && minn >= 33) {
        cout << "Bu Tie\n";
        cout << maxx << '\n';
        return 0;
    } 

    if(!op && maxx > 35 && minn >= 33) {
        cout << "Shi Nei\n";
        cout << maxx << '\n';
        return 0;
    }

    if(op && (maxx <= 35 || minn < 33)) {
        cout << "Bu Re\n";
        cout << minn << '\n';
        return 0;
    }

    if (!op && (maxx <= 35 || minn < 33))
    {
        cout << "Shu Shi\n";
        cout << minn << '\n';
        return 0;
    }
}
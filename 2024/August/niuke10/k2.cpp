#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T>
bool chmax(T& a, const T& b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T& a, const T& b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod = 998244353, MAX = 300005, INF = 15 << 26;

int main()
{
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        int l = 0, r = N + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            bool ok = false;
            for (int i = 0; i + mid - 1 < N; i++)
            {
                int a = i, b = N - (i + mid);
                int s = A[i], t = A[i + mid - 1];
                if (s >= 0)
                {
                    if (t <= b)
                        ok = true;
                }
                else if (t <= 0)
                {
                    if (-s <= a)
                        ok = true;
                }
                else
                {
                    if (-s <= a && (t + (-s)) <= b)
                        ok = true;
                    if (t <= b && (t + (-s)) <= a)
                        ok = true;
                }
            }
            if (ok)
                l = mid;
            else
                r = mid;
        }
        cout << l << "\n";
    }
}

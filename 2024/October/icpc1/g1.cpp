#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;
void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    map<int, int> B;
    for (int i = 0;i < n;i++)
    {
        cin >> A[i];
        B[A[i]] = 0;
    }
    for (int l = 0;l < n;l++)
    {
        priority_queue<int, vector<int>, greater<int> > S;
        priority_queue<int, vector<int>, less<int> > D;
        int mid;

        for (int r = l;r < n;r++)
        {
            if (l == r)
            {
                mid = A[r];
            }
            else
            {
                if (!S.empty() && !D.empty())
                {
                    if (mid > A[r])
                    {
                        S.push(mid);
                        mid = A[r];
                    }
                    else
                    {
                        D.push(A[r]);
                    }
                }
                else if (!S.empty() || !D.empty())
                {
                    if (S.size())
                    {
                        if (mid >= A[r])
                        {
                            D.push(mid);
                            mid = A[r];
                        }
                        else
                        {
                            D.push(A[r]);
                        }
                    }
                    else if (D.size())
                    {
                        if (mid <= A[r])
                        {
                            S.push(mid);
                            mid = A[r];
                        }
                        else
                        {
                            S.push(A[r]);
                        }
                    }
                }
                else
                {
                    if (mid < A[r] && mid)
                    {
                        D.push(A[r]);
                    }
                    else if (mid >= A[r])
                    {
                        S.push(A[r]);
                    }

                }
            }
            B[mid]++;
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
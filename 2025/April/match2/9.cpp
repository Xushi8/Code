#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> siz;
    stack<int> A;
    stack<int> B;

    A.emplace(a[0]);
    for (int i = 1; i < n; i++)
    {
        int C = a[i];
        if (C < A.top())
        {
            A.emplace(C);
        }
        else
        {
            if (B.empty() || C > B.top())
            {
                B.emplace(C);
            }
            else
            {
                siz.emplace_back(A.size());
                stack<int>().swap(A);

                while (!B.empty() && B.top() > C)
                {
                    A.emplace(B.top());
                    B.pop();
                }
                A.emplace(C);
            }
        }
    }

    int maxx = *max_element(siz.begin(), siz.end());
    cout << siz.size() << ' ' << maxx << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}
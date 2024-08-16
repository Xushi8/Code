#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

size_t get_zuixiao(vector<pii> const& a)
{
    auto b = a;
    b.insert(b.end(), a.begin(), a.end());
    const size_t n = a.size();
    size_t i, j;
    for (i = 0, j = 1; i < n && j < n;)
    {
        size_t k;
        for (k = 0; k < n && b[i + k].second == b[j + k].second; k++)
        {
            // cerr << i << ' ' << j << ' ' << b[i].second << ' ' << b[j].second << '\n';
        }

        if (b[i + k].second > b[j + k].second)
            i = i + k + 1;
        else
            j = j + k + 1;
        if (i == j)
            j++;
    }
    return min(i, j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    size_t k = get_zuixiao(a);
    rotate(a.begin(), a.begin() + k, a.end());
    for (auto [x, y] : a)
    {
        cout << y << ' ';
    }
}
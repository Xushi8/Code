#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1\n";
        return 0;
    }
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    if (a[0].first == a[1].first)
    {
        cout << "Still Rozdil\n";
    }
    else
    {
        cout << a[0].second + 1 << '\n';
    }

    cout << clock() / 1000. << "ms\n";
    return 0;
}

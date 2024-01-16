// 2024/01/16 10:02:36
#include <iostream>
#include <vector>
#include <set>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

void func(vector<int>& a, multiset<int> const& b)
{
    cout << a.capacity() << endl;
    a.insert(a.end(), b.begin(), b.end());
    // copy(b.begin(), b.end(), back_inserter(a));
    cout << a.capacity() << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // string s = "ksdlasdjk";
    // string_view sv(s.data() + s.size() - 3, s.data() + s.size() - 2);
    // cout << sv << endl;

    vector<int> a(3, 5);
    multiset<int> b;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.emplace(x);
    }

    func(a, b);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
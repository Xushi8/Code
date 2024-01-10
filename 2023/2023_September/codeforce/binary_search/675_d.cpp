// 2023/10/04 13:49:38
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

// struct node
// {
//     int val;
//     node* l, * r;

//     constexpr node(int val_, node* left = nullptr, node* right = nullptr) :
//         val(val_),
//         l(left),
//         r(right) {}


//     void insert(int x)
//     {
//         if (x > this->val)
//         {
//             if (r == nullptr)
//             {
//                 r = new node(x);
//                 par[x] = this->val;
//             }
//             else
//             {
//                 r->insert(x);
//             }
//         }
//         else if (x < this->val)
//         {
//             if (l == nullptr)
//             {
//                 l = new node(x);
//                 par[x] = this->val;
//             }
//             else
//             {
//                 l->insert(x);
//             }
//         }
//     }

//     ~node()
//     {
//         if(this->l != nullptr)
//             this->l->~node();
//         if(this->r != nullptr)
//             this->r->~node();

//         free(this->l);
//         free(this->r);
//     }
// };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> st;
    map<int, int> left;
    map<int, int> right;
    int val;
    cin >> val;
    st.insert(val);
    for (int i = 1; i < n; i++)
    {
        cin >> val;
        int ans = 0;
        auto it = st.upper_bound(val);
        if (it != st.end() && left.count(*it) == 0)
        {
            ans = *it;
            left[*it] = val;
        }
        else
        {
            ans = *(--it);
            right[*it] = val;
        }
        cout << ans << ' ';
        st.insert(val);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
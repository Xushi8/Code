// 2023/09/09 20:41:40
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    map<string, int> st;
    st.emplace("tourist", 3858);
    st.emplace("ksun48", 3679);
    st.emplace("Benq", 3658);
    st.emplace("Um_nik", 3648);
    st.emplace("apiad", 3638);
    st.emplace("Stonefeang", 3630);
    st.emplace("ecnerwala", 3613);
    st.emplace("mnbvmar", 3555);
    st.emplace("newbiedmy", 3516);
    st.emplace("semiexp", 3481);

    string s;
    cin >> s;
    cout << st[s] << '\n';

    

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}
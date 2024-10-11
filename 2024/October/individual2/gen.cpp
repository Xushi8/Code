#include <random>
#include <vector>
#include <fstream>
#include <set>
using namespace std;

int main()
{
    constexpr size_t n = 100000, m = 100000, k = 100, s = 100;
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    ofs << n << ' ' << m << ' ' << k << ' ' << s << '\n';
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> uni_k(1, k);
    for (size_t i = 0; i < n; i++)
    {
        ofs << uni_k(rng) << ' ';
    }
    ofs << '\n';

    uniform_int_distribution<size_t> uni_size_t(0, (n - 1) * (n - 1));
    set<size_t> st;
    for(size_t cnt = 0; cnt < m; cnt++)
    {
        size_t x = uni_size_t(rng);
        if (st.contains(x))
        {
            cnt--;
            continue;
        }
        st.emplace(x);
        ofs << x / n + 1 << ' ' << x % n + 1 << '\n';
    }
}
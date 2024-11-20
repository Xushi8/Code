#include <random>
#include <fstream>
#include <set>
#include <array>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> uni(1, 100000);
    set<array<int, 3>> st;
    constexpr int N = 1e5;
    for (int i = 0; i < N; i++)
    {
        int x = uni(rng);
        int y = uni(rng);
        int z = uni(rng);
        st.insert({x, y, z});
    }

    ofs << 1 << '\n';
    ofs << st.size() << '\n';
    for (auto [x, y, z] : st)
    {
        ofs << x << ' ' << y << ' ' << z << '\n';
    }
}
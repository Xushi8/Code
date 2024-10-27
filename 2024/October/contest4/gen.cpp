#include <random>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());

    constexpr int n = 5, q = 5;
    constexpr int minn = -1e1, maxx = 1e1;
    uniform_int_distribution<int> uni(minn, maxx);
    uniform_int_distribution<size_t> unindex(1, n);

    ofs << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << uni(rng) << ' ';
    }
    ofs << '\n';

    for (int i = 0; i < q; i++)
    {
        ofs << unindex(rng) << ' ' << uni(rng) << '\n';
    }
}
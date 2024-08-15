#include <algorithm>
#include <fstream>
#include <vector>
#include <random>
#include <iostream>
using namespace std;

void write(string const& file_path, vector<double> const& a)
{
    ofstream ofs(file_path);
    ofs.write(reinterpret_cast<const char*>(a.data()), sizeof(double) * a.size());
}

void read(string const& file_path, vector<double>& a)
{
    ifstream ifs(file_path);
    ifs.seekg(0, ios::end);
    const size_t n = ifs.tellg() / sizeof(char);
    ifs.seekg(0);
    a.resize(n / sizeof(double));
    ifs.read(reinterpret_cast<char*>(a.data()), n);
}

void func1()
{
    constexpr size_t n = 1e1;
    vector<double> a(n);
    mt19937 rng(random_device{}());
    uniform_real_distribution<double> unf(-1e18, 1e18);
    generate_n(a.begin(), n, [&rng, &unf]()
        { return unf(rng); });
    for (size_t i = 0; i < 3; i++)
    {
        cout << a[i] << '\n';
    }
    for (size_t i = n - 1; i > n - 4; i--)
    {
        cout << a[i] << '\n';
    }
    string path = "/home/tom/Documents/Code/in.txt";
    write(path, a);
}

void func2()
{
    vector<double> a;
    string path = "/home/tom/Documents/Code/in.txt";
    read(path, a);
    const size_t n = a.size();
    for (size_t i = 0; i < 3; i++)
    {
        cout << a[i] << '\n';
    }
    for (size_t i = n - 1; i > n - 4; i--)
    {
        cout << a[i] << '\n';
    }
}

int main()
{
    func1();
    // func2();
}
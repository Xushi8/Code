#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std::chrono;
using namespace std;

void binary_in()
{
    ifstream ifs("filename.data", ios::in | ios::binary);

    auto start_time = steady_clock::now();
    auto end_time = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    // for (size_t i = 0; i < n; i++)
    // {
    //     double x;
    //     ifs.read((char*)&x, sizeof(x));
    // }

    ifs.seekg(0, std::ios::end);
    const size_t n = ifs.tellg() / sizeof(double);
    ifs.seekg(0);
    vector<double> res(n);
    ifs.read(reinterpret_cast<char*>(res.data()), sizeof(double) * n);

    // for (auto x : res)
    // {
    //     cout << x << '\n';
    // }

    end_time = steady_clock::now();
    duration = duration_cast<milliseconds>(end_time - start_time);
    cout << duration << endl;
}

int main(int argc, char* argv[])
{
    binary_in();
    return 0;
}
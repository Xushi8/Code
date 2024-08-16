#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    ofstream ofs("/home/tom/Documents/Code/in.txt");
    mt19937 rng(random_device{}());
    uniform_int_distribution<char> uni('A', 'Z');
    string s, t;
    ofs << 1 << '\n';
    for (int i = 0; i < 1000000; i++)
    {
        s += uni(rng);
    }
    for (int i = 0; i < 1048576; i++)
    {
        t += uni(rng);
    }
    ofs << s << ' ' << t << '\n';
}
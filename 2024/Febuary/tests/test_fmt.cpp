#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/os.h>
#include <string>
#include <string_view>
#include <fstream>
#include <chrono>
#include <iostream>
using namespace std;
using namespace fmt;
using namespace std::chrono;

int main()
{
    print(stderr, "Don't {}\n", "panic");
    print("{}\n", "system pause");
    print("{}\n", acos(-1));
    ofstream ofs("test.txt", ios::binary | ios::out);
    print(ofs, "test fmt\n");

    constexpr std::string_view s = "ab";
    print("|{:*^{w}}|\n", s, arg("w", 10));

    print("{:.1}\n", s);
    int x = 90000000;
    print("{:b}\n", x);
    // auto tmp = format(std::locale("zh_CN.UTF-8"), "{:L}\n", x);
    // print("{}\n", tmp);

    print("{:L}\n", x);

    auto f = fmt::output_file("guide");
    f.print("The answer is {}.", 42);



    return 0;
}
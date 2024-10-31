#include <clocale>
#include <fmt/format.h>

int main()
{
#ifdef __unix__
    char* ret = setlocale(LC_ALL, ".utf8");
    if (ret == nullptr)
    {
        fmt::print(stderr, "setlocale failed.\n");
    }
#endif
    return 0;
}
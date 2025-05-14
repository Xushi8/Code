#include <print>
#include <stack>

using namespace std;

/**
 * @brief 
 * 
 */
class calculator
{

private:
    stack<int> num;
    stack<char> sign;
};

/**
 * @brief 
 * 
 * @param a 
 * @param ch 
 * @param b 
 * @return int 
 */
int func(int a, char ch, int b)
{
    if (ch == '+')
    {
        return a + b;
    }
    else if (ch == '-')
    {
        return a - b;
    }
    else if (ch == '*')
    {
        return a * b;
    }
    else
    {
        return a / b;
    }
}

int main()
{
    std::println("Hello, C++ {}", __cplusplus);
}
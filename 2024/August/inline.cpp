#include <iostream>
#include <thread>

inline thread_local int counter = 0;

void incrementCounter()
{
    ++counter;
    std::cout << "Counter in thread " << std::this_thread::get_id() << ": " << counter << std::endl;
}

void anotherFunction()
{
    ++counter;
    std::cout << "Counter in anotherFunction in thread " << std::this_thread::get_id() << ": " << counter << std::endl;
}

int main()
{
    std::thread t1([]()
        {
            incrementCounter();
            anotherFunction();
        });

    std::thread t2([]()
        {
            incrementCounter();
            anotherFunction();
        });

    t1.join();
    t2.join();

    return 0;
}

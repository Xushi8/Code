#include <mutex>
#include <iostream>
#include <thread>

#define TRY_MUTEX       0
#define MY_MUTEX        1

volatile int counter(0); // non-atomic counter

std::mutex mtx;

void increases10k()
{
        for(int i=0;i<10000;i++)
        {
#if TRY_MUTEX
                if(mtx.try_lock())
                {
                        ++counter;
                        mtx.unlock();
                }
#elif MY_MUTEX
                mtx.lock();
                ++counter;
                mtx.unlock();
#endif
        }

}

int main(int argc,char **argv)
{
        std::thread threads[10];
        for(int i=0;i<10;i++)
        {
                threads[i]=std::thread(increases10k);
        }
        for(auto& th:threads)
                th.join();
        std::cout << " successful increases of the counter " << counter <<std::endl;
        return 0;

}